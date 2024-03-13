#include <iostream>
using namespace std;

#include "IntList.h"

int main() {

  //tests constructor, destructor, push_front, pop_front, display

   {
      cout << "\nlist1 constructor called" << endl;
      IntList list1;
      cout << "pushfront 10" << endl;
      list1.push_front(10);
      cout << "pushfront 20" << endl;
      list1.push_front(20);
      cout << "pushfront 30" << endl;
      list1.push_front(30);
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pop" << endl;
      list1.pop_front();
      cout << "list1: " << list1 << endl;
      cout << "pushfront 100" << endl;
      list1.push_front(100);
      cout << "pushfront 200" << endl;
      list1.push_front(200);
      cout << "pushfront 300" << endl;
      list1.push_front(300);
      cout << "list1: " << list1 << endl;
      cout << endl;
      cout << "Calling list1 destructor..." << endl;
   }
   cout << "list1 destructor returned" << endl;
   
   // Test destructor on empty IntList
   {
      IntList list2;
      cout << "Calling list2 destructor..." << endl;
   }
   cout << "list2 destructor returned" << endl;

   // test harnesses for the rest of the functions;
   cout << endl << "TEST HARNESS FOR REMAINING FUNCTIONS: " << endl;
   IntList list3;
   cout << endl;
   cout << "creating list3..." << endl;
   cout << "checking if empty, should return empty" << endl;
   if (list3.empty()) {
      cout << "EMPTY" << endl;
   } else {
      cout << "ERROR, returns not empty when it shouldnt" << endl;
   }
   cout << "pushfront 300" << endl;
   list3.push_front(300);
   cout << "checking if empty, should return NOT empty" << endl;
   if (!list3.empty()) {
      cout << "NOT EMPTY" << endl;
   } else {
      cout << "ERROR, returns empty when it shouldnt" << endl;
   }

   cout << endl << endl;

   cout << "testing front and back" << endl;
   cout << "pushfront 500" << endl;
   list3.push_front(500);
   cout << "front should be 500, back should be 300" << endl;
   cout << "front: " << list3.front() << endl;
   cout << "back: " << list3.back() << endl;

   cout << endl << endl;

   cout << "testing clear function" << endl;
   cout << "should return true" << endl;
   if (!list3.empty()) {
      cout << "list3 isn't empty, true" << endl;
   }
   cout << "clearing list3..." << endl;
   list3.clear();
   cout << "testing clear function again, should return true again" << endl;
   if (list3.empty()) {
      cout << "list3 is now empty, true" << endl;
   }
   cout << endl << endl;

   cout << "now testing insertion operator overload..." << endl;
   cout << "pushfront 1, 2, 3, 4, 5" << endl;
   list3.push_front(5);
   list3.push_front(4);
   list3.push_front(3);
   list3.push_front(2);
   list3.push_front(1);
   cout << "should return 1 2 3 4 5" << endl;
   cout << "List: " << list3 << endl;

   return 0;
}
