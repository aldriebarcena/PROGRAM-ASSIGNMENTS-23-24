#include "WordLadder.h"

#include <iostream>
#include <fstream>

#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// constructs wordladder object that takes in a file name as parameter
WordLadder::WordLadder(const string &filename) 
{
  ifstream inFS; // initialize ifstream variable
  string currWord;

  inFS.open(filename);

  if (!inFS.is_open()) // if file didn't open
  {
    // throw runtime_error("Unable to open file");

    // used for zybooks rubric:
      cout << "Unable to open file" << endl;
      return;
  }

  while (inFS >> currWord) // loop until no more words were sent to stream
  {
    if (currWord.length() != 5) // if any word wasn't exactly 5 characters, throw error
    {
      // throw runtime_error("Word read was not 5 letters");

      // used for zybooks rubric:
        cout << "Word read was not 5 letters" << endl;
        return;
    }
    dict.push_back(currWord); // adding each word to dict vector
  }

  inFS.close();
}

// outputs the ladder to an output file, takes in a starting and ending word
void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile)
{
  // if start/end word isn't in dictionary
  if (!(std::find(dict.begin(), dict.end(), start) != dict.end()))
  {
    throw runtime_error("Start word is not in dictionary");
  }
  if (!(std::find(dict.begin(), dict.end(), end) != dict.end()))
  {
    throw runtime_error("End word is not in dictionary");
  }

  // opening desired output file
  ofstream outFS;
  outFS.open(outputFile);

  // if ofstream wasn't able to open the file
  if (!outFS.is_open())
  {
    throw runtime_error("Unable to open file");
  }

  // create initial stack with starting word inside
  stack<string> startingStack;
  startingStack.push(start);

  // creates the queue of all stacks and initializes it with starting stack
  queue<stack<string>> queueOfStacks;
  queueOfStacks.push(startingStack);

  // initialized to false and will be called if a ladder was never found
  bool ladderFound = false;

  while (!queueOfStacks.empty()) // continue the loop as long as this queue isn't empty
  {
    // setting the current stack to the queue's front stack
    stack<string> currStack = queueOfStacks.front();

    // setting current word to front stack's top word
    string currWord = currStack.top();

    // remove queue's front stack
    queueOfStacks.pop();

    if (currWord == end) // word ladder finished
    {
      // copied the stack's words to a vector to output it in correct order
      vector<string> ladderCpy;

      // copying each word from currStack to the vector
      while (!currStack.empty())
      {
        ladderCpy.push_back(currStack.top());
        currStack.pop(); // removes top each iteration so next word can be pushed to vector
      }

      // outputs each word in vector in reverse order
      for (int i = ladderCpy.size() - 1; i >= 0; i--)
      {
        outFS << ladderCpy.at(i) << endl;
      }

      ladderFound = true; // set to true to prevent "no word ladder" output
      break;              // break out of loop to indicate that word ladder was found
    }

    // loop that iterates over every word in the dictionary
    for (auto it = dict.begin(); it != dict.end();)
    {
      const string &currDictWord = *it; // set a variable to *it for better clarity

      // used to track letter difference between both words
      int diffLetters = 0;

      // compares each character of both words
      for (unsigned i = 0; i < 5; i++)
      {
        if (currWord.at(i) != currDictWord.at(i)) // if same letter found
        {
          diffLetters++;
        }
      }

      // if "off by one" word is found
      if (diffLetters == 1)
      {
        // create a new stack that is a copy of the current front stack
        stack<string> frontStackCpy = currStack;

        // adds "off by one" word to new stack
        frontStackCpy.push(currDictWord);

        // finally, adds this copy to the queue of stacks
        queueOfStacks.push(frontStackCpy);

        // erases current word
        it = dict.erase(it);
      }
      else // if current word isn't an off by one word, iterate over to next word in dictionary
      {
        it++;
      }
    }
  }

  // if a ladder wasn't found, this is outputted to the file
  if (!ladderFound)
  {
    outFS << "No Word Ladder Found." << endl;
  }

  outFS.close();
}
