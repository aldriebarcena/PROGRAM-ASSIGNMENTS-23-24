#include "IntList.h"
#include <iostream>
using namespace std;

class SortedSet : public IntList
{

public:
  SortedSet();
  // The default constructor initializes an empty set.
  SortedSet(const SortedSet &);
  // The copy constructor initializes the set to be a copy of the set passed in. Use the IntList copy constructor. This function should definitely NOT call the removeduplicates or selectionsort functions since there should not be any duplicates or out of order values in the SortedSet being copied in.
  SortedSet(const IntList &);
  // A constructor that is passed an IntList instead of a SortedSet. It should initialize the set using the values in the IntList. Again, you can use the IntList copy constructor and then remove all of the duplicates and sort the remaining values.
  ~SortedSet();
  // The destructor needs to deallocate all dynamically allocated memory that the IntList destructor will not already deallocate. You may very well find that this function does not need to do anything.

  bool in(int value);
  // This function returns true if the value passed in is a member of the set, otherwise false.

  void add(int value);
  //  This function adds the value passed in to the set. It needs to make sure the value does not already exist in the set (no duplicates) and that it is inserted in the proper position (in ascending order).
  //  This must be an O(n) operation (essentially meaning only going through the list once - no nested loops).
  //  This means you cannot call remove_duplicates or selection_sort member functions within this function. Instead, this function must go through the list once (and only once) looking for the location to add the new value and then inserting it only if that location does not already have the value located there. This will be O(n) because you will visit each node in the list at most once. Recall, the remove_duplicates and selection_sort functions are O(n2) functions.
  //  So, this function is basically the insert_ordered function from your IntList, only you don't insert duplicates.

  void push_front(int value);
  // Override this function so that it inserts the value in the proper position (in ascending order) only if the value does not already exist in the set (no duplicates).
  // In other words, this function should do exactly what add does. The only reason we are overriding this function is so that the push_front from the IntList is not inherited. A user of the SortedSet should not be able to just push any value onto the front of the list.
  // In fact, since this function should do exactly what add does, this function should just call add to do the work for it.

  void push_back(int value);
  //  Override this function so that it inserts the value in the proper position (in ascending order) only if the value does not already exist in the set (no duplicates).
  //  See specs for push_front above. The same rationale for overriding applies to this function.

  void insert_ordered(int value);
  //  Override this function so that it does not insert duplicates.
  //  See specs for push_front above. The same rationale for overriding applies to this function.

  SortedSet operator|(const SortedSet &rhs);
  //  This function returns a SortedSet object that is the union of 2 SortedSet objects, the left and right operands of this binary operator. A union of 2 sets is a set that consists of all of the distinct elements of both sets combined. That is, all of the values that are in the left operand or in the right operand or in both operands.
  //  sset1 = sset2 | sset3;
  //  Hint: This operator return type will be very similar to the + operator you implemented for the Distance class.
  //  Note: This function should NOT call removeduplicates or selectionsort functions.

  SortedSet operator&(const SortedSet &rhs);
  //  This function returns a SortedSet object that is the intersection of 2 SortedSet objects, the left and right operands of this binary operator. An intersection of 2 sets is a set of all elements that are in both sets. That is, all of the values that are both in the left operand and in the right operand.
  //  sset1 = sset2 & sset3;
  //  Hint: This operator return type will be very similar to the + operator you implemented for the Distance class.
  //  Note: This function should NOT call removeduplicates or selectionsort functions.

  SortedSet &operator|=(const SortedSet &rhs);
  // This function is the union-assign operator function. It returns a union of the left and right operands, but also sets the left operand's value to be that union as well. In other words, sset1 |= sset2 is equivalent to sset1 = sset1 | sset2.

  // Hint 1: Take advantage of functions you have already written and you know work.
  // Hint 2: This is an assignment operator, so the return type should be the same as the assignment operator.

  // Note: This function should NOT call removeduplicates or selectionsort functions.

  SortedSet &operator&=(const SortedSet &rhs);
  // This function is the intersection-assign operator function. It returns an intersection of the left and right operands, but also sets the left operand's value to be that intersection as well. In other words, sset1 &= sset2 is equivalent to sset1 = sset1 & sset2.
  // Hint 1: Take advantage of functions you have already written and you know work.
  // Hint 2: This is an assignment operator, so the return type should be the same as the assignment operator.
  // Note: This function should NOT call removeduplicates or selectionsort functions.
};