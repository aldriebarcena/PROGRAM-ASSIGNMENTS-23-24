#include "WordLadder.h"

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::string;

int main()
{
  string dictFile, wordBegin, wordEnd, outFile;
  cout << "Enter the name of the dictionary file: ";
  cin >> dictFile;
  cout << endl;
  cout << "Enter the name of the output file: ";
  cin >> outFile;
  cout << endl;
  cout << "Enter the first word: ";
  cin >> wordBegin;
  cout << endl;

  if (not cin)
  { // if any cin issues
    throw runtime_error("input failure");
  }

  while (wordBegin.size() != 5)
  { // continues looping if starting word isn't exactly 5 characters
    cout << "Word must have exactly 5 characters." << endl
         << "Please reenter the first word: ";
    if (not(cin >> wordBegin))
    { // if any cin issues
      throw runtime_error("Could not read 5 character first word");
    }
    cout << endl;
  }
  cout << "Enter the last word: ";
  if (not(cin >> wordEnd))
  { // if any cin issues
    throw runtime_error("Could not read 5 character last word");
  }
  cout << endl;

  while (wordEnd.size() != 5)
  { // continues looping if ending word isn't exactly 5 characters
    cout << "Word must have exactly 5 characters." << endl
         << "Please reenter the last word: ";
    cin >> wordEnd;
    if (not(cin >> wordEnd))
    { // if any cin issues
      throw runtime_error("Could not read 5 character last word");
    }
    cout << endl;
  }

  WordLadder wl(dictFile); // create WordLadder object with the dictionary file

  wl.outputLadder(wordBegin, wordEnd, outFile); // calls wl's output function and sends word ladder to output file
  return 0;
}
