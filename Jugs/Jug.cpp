#include "Jug.h"
#include <vector>
#include <sstream>
#include <list>

using std::endl;
using std::list;
using std::stringstream;

// constructor that builds the graph
Jug::Jug(int Ca, int Cb, int N, int cfA, int cfB, int ceA, int ceB, int cpAB, int cpBA)
    : Ca(Ca), Cb(Cb), N(N), cfA(cfA), cfB(cfB), ceA(ceA), ceB(ceB), cpAB(cpAB), cpBA(cpBA)
{

  for (int a = 0; a <= Ca; ++a)
  {
    for (int b = 0; b <= Cb; ++b)
    {
      // Compute action fill A.  A will have Ca gallons. B unchanged
      // Compute action fill B.  A unchanged, B will have Cb gallons
      unsigned fillA = state_number(Ca, b, Ca, Cb);
      unsigned fillB = state_number(a, Cb, Ca, Cb);

      // For the empties... just set the appropriate amount to zero
      unsigned emptyA = state_number(0, b, Ca, Cb);
      unsigned emptyB = state_number(a, 0, Ca, Cb);

      // For the transfers, we can only pour in as much as we have
      // in the "from" jug OR as much room as we have in the "to" jug
      unsigned transferFromA = std::min(a, Cb - b);
      unsigned AtoB = state_number(a - transferFromA, b + transferFromA, Ca, Cb);
      unsigned transferFromB = std::min(b, Ca - a);
      unsigned BtoA = state_number(a + transferFromB, b - transferFromB, Ca, Cb);

      // pushes each state into the vector, graph is now created
      states.push_back(State(a, b, fillA, fillB, emptyA, emptyB, AtoB, BtoA));
    }
  }
}

Jug::~Jug() // clears the entire vector
{
  states.clear();
}

// finds the shortest distance to end goal, returns -1 if invalid inputs, 0 if no solution found, 1 if a solution is found
int Jug::solve(string &solution)
{

  // check inputs first
  if (!(0 < Ca && Ca <= Cb) || !(N <= Cb && Cb <= 1000))
  {
    solution = "";
    return -1;
  }

  // sets (0,0)'s distance to 0 and it's previous to infinity to set up dikstra method
  states[0].distance = 0;
  states[0].previous = infinity;

  // loop that repeats step on each possible state
  while (true)
  {
    unsigned distance = infinity; // "clears" distance and current state
    unsigned curr = infinity;

    // loops through entire graph to find the smallest distance and also not visited
    for (unsigned i = 0; i < states.size(); i++)
    {
      if (states[i].distance < distance && !states[i].visited)
      {
        distance = states[i].distance;
        curr = i;
      }
    }

    // if the distance ends up being infinity, no more states to checl
    if (distance == infinity)
    {
      break;
    }

    // set curr to visited
    states[curr].visited = true;

    // done on every action:
    // new variable created for each action and is assigned the current state's action
    // new variable created for the action's distance which is the current distance + the cost of that action
    // if the current action's distance is less than the state's distance, replace it with new distance and set the states action's previous to the current state
    unsigned fillA = states[curr].fillA;
    unsigned fillA_distance = distance + cfA;
    if (fillA_distance < states[fillA].distance)
    {
      states[fillA].distance = fillA_distance;
      states[fillA].previous = curr;
    }

    unsigned fillB = states[curr].fillB;
    unsigned fillB_distance = distance + cfB;
    if (fillB_distance < states[fillB].distance)
    {
      states[fillB].distance = fillB_distance;
      states[fillB].previous = curr;
    }

    unsigned emptyA = states[curr].emptyA;
    unsigned emptyA_distance = distance + ceA;
    if (emptyA_distance < states[emptyA].distance)
    {
      states[emptyA].distance = emptyA_distance;
      states[emptyA].previous = curr;
    }

    unsigned emptyB = states[curr].emptyB;
    unsigned emptyB_distance = distance + ceB;
    if (emptyB_distance < states[emptyB].distance)
    {
      states[emptyB].distance = emptyB_distance;
      states[emptyB].previous = curr;
    }

    unsigned AtoB = states[curr].AtoB;
    unsigned AtoB_distance = distance + cpAB;
    if (AtoB_distance < states[AtoB].distance)
    {
      states[AtoB].distance = AtoB_distance;
      states[AtoB].previous = curr;
    }

    unsigned BtoA = states[curr].BtoA;
    unsigned BtoA_distance = distance + cpBA;
    if (BtoA_distance < states[BtoA].distance)
    {
      states[BtoA].distance = BtoA_distance;
      states[BtoA].previous = curr;
    }

    // if solution is found, set the solution to the steps
    if (states[curr].a == 0 && states[curr].b == N)
    {
      stringstream ss;       // initialize string stream
      unsigned index = curr; // initialize index to curr
      list<State> steps;     // create a list of States that holds the steps that led to solution

      while (index != infinity) // for each step
      {
        steps.push_front(states[index]); // push the state at index to the front, to put the list in chronological order
        index = states[index].previous;  // assign new index to curr's prev
      }

      // loop through whole list and convert the state's action to a string and send to string stream
      for (auto it = steps.begin(); it != steps.end(); ++it)
      {
        auto next_it = std::next(it);
        if (next_it != steps.end())
        {
          ss << stateToActionString(*next_it, *it) << endl;
        }
      }
      ss << "success " << states[curr].distance; // end off with the final distance
      solution = ss.str();                       // ouput the string

      return 1;
    }
  }

  return 0;
}

// helper function that takes in a state and its previous state and output what aciton was done
string Jug::stateToActionString(const State &currState, const State &prevState)
{
  // if Jug A decreased and Jug B increased
  if (currState.a < prevState.a && currState.b > prevState.b)
  {
    return "pour A B";
  } // if Jug A increased and Jug B decreased
  else if (currState.a > prevState.a && currState.b < prevState.b)
  {
    return "pour B A";
  } // if Jug A is the same as the cost of A and was less than it's previous
  // and if Jug B stayed the same
  else if (currState.a == Ca && prevState.a < Ca && currState.b == prevState.b)
  {
    return "fill A";
  } // if Jug B is the same as the cost of B and was less than it's previous
  // and if Jug A stayed the same
  else if (currState.b == Cb && prevState.b < Cb && currState.a == prevState.a)
  {
    return "fill B";
  } // if Jug A becomes 0 and the previous state isn't 0
  else if (currState.a == 0 && prevState.a != 0)
  {
    return "empty A";
  } // if Jug B becomes 0 and the previous state isn't 0
  else if (currState.b == 0 && prevState.b != 0)
  {
    return "empty B";
  }
  else
  {
    return "";
  }
}
