// NON GRAPH STRUCTURES USED: LIST, VECTOR

#include <string>
#include <stdexcept>
#include <vector>
#include <limits>

using std::string;
using std::vector;

const unsigned infinity = std::numeric_limits<unsigned>::max(); // setting "infinity"

struct State
{
  int a; // Amount in jug A
  int b; // Amount in jug B

  // Where to go on each of the six actions
  unsigned fillA;
  unsigned fillB;
  unsigned emptyA;
  unsigned emptyB;
  unsigned AtoB;
  unsigned BtoA;

  // These fields are useful when we do Dijkstra's method
  unsigned previous;
  unsigned distance;
  bool visited;

  State(unsigned a = infinity,
        unsigned b = infinity,
        unsigned fillA = infinity,
        unsigned fillB = infinity,
        unsigned emptyA = infinity,
        unsigned emptyB = infinity,
        unsigned AtoB = infinity,
        unsigned BtoA = infinity)
      : a(a),
        b(b),
        fillA(fillA),
        fillB(fillB),
        emptyA(emptyA),
        emptyB(emptyB),
        AtoB(AtoB),
        BtoA(BtoA),
        previous(infinity),
        distance(infinity),
        visited(false)
  {
  }
};

class Jug
{
public:
  Jug(int Ca, int Cb, int N, int cfA, int cfB, int ceA, int ceB, int cpAB, int cpBA);
  ~Jug();
  Jug(const Jug &) = delete;
  Jug &operator=(const Jug &) = delete;
  int solve(string &solution);

private:
  int Ca, Cb, N, cfA, cfB, ceA, ceB, cpAB, cpBA;
  vector<State> states;
  string stateToActionString(const State &currState, const State &prevState);

  // function that returns the state number of a vertex
  unsigned state_number(unsigned a, unsigned b, unsigned Ca, unsigned Cb)
  {
    if (a > Ca or b > Cb) // domain error
    {
      throw std::runtime_error("domain error");
    }

    return a * (Cb + 1) + b;
  }
};