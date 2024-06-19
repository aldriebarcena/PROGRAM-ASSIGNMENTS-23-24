#include "HashTable.h"
#include "WordEntry.h"
#include <list>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

// constructor that creates a HashTable with given size
HashTable::HashTable(int userSize)
{
  size = userSize;                       // sets inputted size to class's size
  hashTable = new list<WordEntry>[size]; // creates new hashTable of lists with the size of size
}

// destructor
HashTable::~HashTable()
{
  delete[] hashTable;
}

// computes the index of where to place string
// chatGPT prompt: write me the best hash function that takes in a string and uses an array of linked lists in c++
int HashTable::computeHash(const string &s) const
{
  int h = 0;              // initialize sum holder
  for (char currChar : s) // iterates for every character in the string
  {
    h = (h + static_cast<int>(currChar)) % size; // add the current sum to the int value of the current char, and modolo by size
  }
  return h; // return that sum
}

// places a string and it's score into the hashtable
void HashTable::put(const string &s, int score)
{
  int h = computeHash(s); // compute hash

  for (list<WordEntry>::iterator it = hashTable[h].begin(); it != hashTable[h].end(); it++) // iterated through entire list @ slot
  {
    if (it->getWord() == s) // if already exists, just add appearance
    {
      it->addNewAppearance(score);
      return; // return early
    }
  }

  hashTable[h].push_back(WordEntry(s, score)); // deals with empty slot and collisions
}

// returns the average score of the given word
double HashTable::getAverage(const string &s) const
{

  int h = computeHash(s); // compute hash

  for (list<WordEntry>::iterator it = hashTable[h].begin(); it != hashTable[h].end(); it++) // iterated through entire list @ slot
  {
    if (it->getWord() == s) // if already exists, return the average of the string
    {
      return it->getAverage();
    }
  }

  return 2.0; // if DNE, just return median score
}

// checks if hashtable contains given string
bool HashTable::contains(const string &s) const
{
  int h = computeHash(s); // compute hash

  for (list<WordEntry>::iterator it = hashTable[h].begin(); it != hashTable[h].end(); it++) // iterated through entire list @ slot
  {
    if (it->getWord() == s) // if exists, return true
    {
      return true;
    }
  }

  return false; // otherwise return false
}

// put main in here for zybooks --------------
int main()
{
  // declare a few needed variables for inputing the data
  string line;
  int score;
  string message = " ";

  // open input file
  ifstream myfile("movieReviews.txt");
  if (myfile.fail())
  {
    cout << "could not open file" << endl;
    exit(1);
  }

  // create hash table
  HashTable table(20071);

  while (true)
  {
    myfile >> score; // get score
    myfile.get();    // get blank space
    getline(myfile, line);
    if (not myfile)
    {
      if (myfile.eof())
        break; // Doesn't return true unless we tried input
      throw runtime_error("input failed");
    }
    int len = line.size();
    while (len > 0)
    { // identify all individual strings
      string sub;
      len = line.find(" ");
      if (len > 0)
      {
        sub = line.substr(0, len);
        line = line.substr(len + 1, line.size());
      }
      else
      {
        sub = line.substr(0, line.size() - 1);
      }
      table.put(sub, score); // insert string with the score
    }
  }

  // after data is entered in hash function
  // prompt user for a new movie review
  while (message.length() > 0)
  {
    cout << "enter a review -- Press return to exit: " << endl;
    getline(cin, message);

    // used for calculating the average
    double sum = 0;
    int count = 0;

    double sentiment = 0.0;

    size_t len = message.size();
    // get each individual word from the input
    while (len != string::npos)
    {
      string sub;
      len = message.find(" ");
      if (len != string::npos)
      {
        sub = message.substr(0, len);
        message = message.substr(len + 1, message.size());
      }
      else
      {
        sub = message;
      }
      // calculate the score of each word
      sum += table.getAverage(sub);
      ++count;
    }

    if (message.size() > 0)
    {
      sentiment = sum / count;
      cout << "The review has an average value of " << sentiment << endl;
      if (sentiment >= 3.0)
      {
        cout << "Positive Sentiment" << endl;
      }
      else if (sentiment >= 2.0)
      {
        cout << "Somewhat Positive Sentiment" << endl;
      }
      else if (sentiment >= 1.0)
      {
        cout << "Somewhat Negative Sentiment" << endl;
      }
      else
      {
        cout << "Negative Sentiment" << endl;
      }
      cout << endl;
    }
  }

  return 0;
}
