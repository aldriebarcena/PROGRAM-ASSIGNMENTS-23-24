#include "SortedSet.h"
#include "IntList.h"
#include <iostream>
using namespace std;

void TestCase1()
{
  // tests add and in function
  cout << "Testing add and in function" << endl
       << endl;
  SortedSet s;
  s.add(4);
  s.add(10);
  s.add(9);
  s.add(14);
  s.add(15);

  cout << "Adding 4, 10, 9, 14, 15..." << endl;
  cout << s << endl;
  cout << "Checking if 4 is in set..." << endl;
  cout << s.in(4) << endl;
  cout << "Checking if 20 is in set..." << endl;
  cout << s.in(20) << endl;

  cout << endl;
}

void TestCase2()
{
  cout << "Testing overridden functions" << endl
       << endl;
  SortedSet s;

  cout << "Pushing back 5..." << endl;
  s.push_back(5);
  cout << "Pushing front 7..." << endl;
  s.push_front(7);
  cout << "Insert ordering 8..." << endl;
  s.insert_ordered(8);
  cout << "Checking order..." << endl;
  cout << s << endl;

  cout << endl;
}

void TestCase3()
{
  cout << "Testing union overload" << endl
       << endl;

  SortedSet s1;
  cout << "Creating set 1..." << endl;
  s1.add(1);
  s1.add(5);
  s1.add(6);
  s1.add(9);
  s1.add(10);
  cout << s1 << endl;

  SortedSet s2;
  cout << "Creating set 2..." << endl;
  s2.add(13);
  s2.add(14);
  s2.add(3);
  s2.add(11);
  s2.add(2);
  cout << s2 << endl;
  cout << endl;

  cout << "Combing both sets..." << endl;
  SortedSet s3;
  s3 = s1 | s2;
  cout << s3 << endl;

  cout << endl;
}

void TestCase4()
{
  cout << "Testing intersection overload" << endl
       << endl;

  SortedSet s1;
  cout << "Creating set 1..." << endl;
  s1.add(1);
  s1.add(2);
  s1.add(3);
  s1.add(4);
  s1.add(5);
  cout << s1 << endl;

  SortedSet s2;
  cout << "Creating set 2..." << endl;
  s2.add(2);
  s2.add(4);
  s2.add(6);
  s2.add(8);
  s2.add(10);
  cout << s2 << endl;
  cout << endl;

  cout << "Intersectinng both sets..." << endl;
  SortedSet s3;
  s3 = s1 & s2;
  cout << s3 << endl;

  cout << endl;
}

int main()
{
  TestCase4();
  return 0;
}