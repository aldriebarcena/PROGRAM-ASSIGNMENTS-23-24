using namespace std;

#include "IntVector.h"
#include "iostream"
#include <stdexcept>

int main()
{

  // test default constructor
  // temp moved _size, _capacity to public
  // IntVector vec1;
  // cout << "vec1: size = " << vec1._size << endl;
  // cout << "vec1: capacity = " << vec1._capacity << endl;
  // cout << endl;

  // test constructor with paramenters
  // temp moved _size, _capacity to public
  // IntVector vec2(5, 10);
  // cout << "vec2: size = " << vec2._size << endl;
  // cout << "vec2: capacity = " << vec2._capacity << endl;
  // cout << endl;

  // test size, capacity
  IntVector vec1(5, 4);
  IntVector vec2(2, 2);

  cout << "vec1: size = " << vec1.size() << endl;
  cout << "vec1: capacity = " << vec1.capacity() << endl;

  cout << "vec2: size = " << vec2.size() << endl;
  cout << "vec2: capacity = " << vec2.capacity() << endl;

  cout << endl;

  // tests is empty
  IntVector emptyVector(0, 5);

  if (emptyVector.empty())
  {
    cout << "emptyVector is empty" << endl;
  }
  else
  {
    cout << "Error!" << endl;
  }

  if (!vec1.empty())
  {
    cout << "vect1 is NOT empty" << endl;
  }
  else
  {
    cout << "Error!" << endl;
  }

  cout << endl;

  // tests at
  IntVector vec3(5, 0);

  // cout << vec3.at(5) << endl;
  // cout << vec3.at(6) << endl;
  cout << "vec3 at index 4: " << vec3.at(4) << endl;
  cout << endl;

  // tests front and back
  IntVector vec4(5, 5);
  IntVector vec5(5, 10);

  cout << "vec4 front index: " << vec4.front() << endl;
  cout << "vec4 back index: " << vec4.back() << endl;
  cout << "vec5 front index: " << vec5.front() << endl;
  cout << "vec5 back index: " << vec5.back() << endl;
  cout << endl;

  // tests expand function (functions made temporarily public)
  // IntVector vec6(6, 5);
  // cout << "vec6 capacity: " << vec6.capacity() << endl;
  // vec6.expand(2);
  // cout << "vec6 capacity with 2 more added: " << vec6.capacity() << endl;
  // vec6.expand();
  // cout << "vec6 capacity doubled: " << vec6.capacity() << endl;
  // cout << endl;

  // tests insert
  IntVector vec7(6, 4);

  cout << "vec7 current values: ";
  for (unsigned i = 0; i < vec7.size(); i++)
  {
    cout << vec7.at(i) << " ";
  }
  cout << endl;

  vec7.insert(4, 10);
  cout << "vec7 new values: ";
  for (unsigned i = 0; i < vec7.size(); i++)
  {
    cout << vec7.at(i) << " ";
  }
  cout << endl
       << endl;

  // test out of range
  // vec7.insert(8, 10);
  // cout << "vec7 new values: ";
  // for (unsigned i = 0; i < vec7.size(); i ++) {
  //   cout << vec7.at(i) << " ";
  // }

  // tests erase
  IntVector vec8(6, 4);

  cout << "vec8 current values: ";
  for (unsigned i = 0; i < vec8.size(); i++)
  {
    cout << vec8.at(i) << " ";
  }
  cout << endl;

  vec8.erase(4);
  cout << "erasing...." << endl;
  cout << "vec8 new values: ";
  for (unsigned i = 0; i < vec8.size(); i++)
  {
    cout << vec8.at(i) << " ";
  }
  cout << endl
       << endl;

  // IntVector vec9(6, 4);

  // cout << "vec9 current values: ";
  // for (unsigned i = 0; i < vec9.size(); i++)
  // {
  //   cout << vec9.at(i) << " ";
  // }
  // cout << endl;

  // vec9.erase(8);
  // cout << "vec9 new values: ";
  // for (unsigned i = 0; i < vec9.size(); i++)
  // {
  //   cout << vec9.at(i) << " ";
  // }
  // cout << endl << endl;

  // tests assign
  IntVector vec10(6, 5);

  cout << "vec10: current capacity: " << vec10.capacity() << endl;
  cout << "vec10: current size: " << vec10.size() << endl;
  cout << "vec10: currect values: ";
  for (unsigned int i = 0; i < vec10.size(); i++)
  {
    cout << vec10.at(i) << " ";
  }
  cout << endl
       << endl;

  vec10.assign(8, 9);
  cout << "assigning new values...." << endl;
  cout << "vec10: current capacity: " << vec10.capacity() << endl;
  cout << "vec10: current size: " << vec10.size() << endl;
  cout << "vec10: currect values: ";
  for (unsigned int i = 0; i < vec10.size(); i++)
  {
    cout << vec10.at(i) << " ";
  }
  cout << endl
       << endl;

  IntVector vec11(6, 7);
  cout << "vec11: currect values: ";
  for (unsigned int i = 0; i < vec11.size(); i++)
  {
    cout << vec11.at(i) << " ";
  }
  cout << endl;
  cout << "vec11: current size: " << vec11.size() << endl;

  vec11.push_back(5);
  cout << "pushing back value 5......." << endl;
  cout << "vec11: new size: " << vec11.size() << endl;
  cout << "vec11: new values: ";
  for (unsigned int i = 0; i < vec11.size(); i++)
  {
    cout << vec11.at(i) << " ";
  }
  cout << endl;

  vec11.pop_back();
  cout << "pop_back...." << endl;
  cout << "vec11: new size: " << vec11.size() << endl;
  cout << endl;

  vec11.clear();
  cout << "clearing...." << endl;
  cout << "vec11: new size: " << vec11.size() << endl;

  cout << "vec11: new values: ";
  for (unsigned int i = 0; i < vec11.size(); i++)
  {
    cout << vec11.at(i) << " ";
  }
  cout << endl << endl;

  IntVector vec12(6, 8);
  cout << "vec12 current size: " << vec12.size() << endl;
  cout << "vec12: current values: ";
  for (unsigned int i = 0; i < vec12.size(); i++)
  {
    cout << vec12.at(i) << " ";
  }
  cout << endl;

  cout << "resizing smaller...." << endl;
  vec12.resize(5);
  cout << "vec12 new size: " << vec12.size() << endl;
  cout << "vec12: new values: ";
  for (unsigned int i = 0; i < vec12.size(); i++)
  {
    cout << vec12.at(i) << " ";
  }
  cout << endl;

  cout << "resizing bigger....." << endl;
  vec12.resize(8, 9);
  cout << "vec12 new size: " << vec12.size() << endl;
  cout << "vec12: new values: ";
  for (unsigned int i = 0; i < vec12.size(); i++)
  {
    cout << vec12.at(i) << " ";
  }
  cout << endl << endl;

  IntVector vec13(5, 1);
  cout << "vec13 current capacity: " << vec13.capacity() << endl;
  cout << "reserving...." << endl;
  vec13.reserve(7);
  cout << "vec13 new capacity: " << vec13.capacity() << endl;
  cout << "reserving with value less than original capacity....." << endl;
  vec13.reserve(3);
  cout << "vec13 capacity (capacity shouldn't change): " << vec13.capacity() << endl;
  cout << endl;


  

  return 0;
}
