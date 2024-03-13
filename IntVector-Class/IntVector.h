using namespace std;

class IntVector
{
private:
  int *_data;
  unsigned _size;
  unsigned _capacity;

  void expand();
  /*This function will double the capacity of the vector. This function should reallocate memory for the dynamically allocated array and update the value of capacity. Make sure your expand() function properly handles the case when capacity is 0. This will be a special case within the expand() function. Since doubling 0 still gives you 0, you should set capacity to 1 in this special case.

  Make sure you don't create a memory leak here.*/
  void expand(unsigned amount);
  /*This function will expand the capacity of the vector by the amount passed in. This function should reallocate memory for the dynamically allocated array and update the value of capacity.

  Make sure you don't create a memory leak here.*/

public:
  IntVector(unsigned capacity = 0, int value = 0);
  ~IntVector();

  unsigned size() const;
  unsigned capacity() const;
  bool empty() const;
  const int &at(unsigned index) const;
  const int &front() const;
  const int &back() const;

  int &at(unsigned index);
  /*This function does exactly the same thing the accessor (const) version of at does.*/

  int &front();
  /*This function does exactly the same thing the accessor (const) version of front does.*/

  int &back();
  /*This function does exactly the same thing the accessor (const) version of back does.*/

  void insert(unsigned index, int value);
  /*This function inserts data at position index. To do this, all values currently at position index and greater are shifted to the right by 1 (to the element right after its current position).

  Size will be increased by 1. However, If size will become larger than capacity, this function needs to first double the capacity. In other words, if capacity and size are both 20 when this function is called, this function must first increase the capacity to 40 and then it will be able to increase the size to 21.

  Since other functions will also potentially need to expand (double) the capacity, call the private helper function named expand (see above) to do this for you.

  This function should throw an out_of_range exception, passing it the string "IntVector::insert_range_check" if the index is too large. See bottom of specifications for more details on how to throw an exception and how to test that it works properly.*/

  void erase(unsigned index);
  /*This function removes the value at position index and shifts all of the values at positions greater than index to the left by one (to the element right before its current position).

  Size is decreased by 1.

  This function should throw an out_of_range exception, passing it the string "IntVector::erase_range_check" if the index is too large. See bottom of specifications for more details on how to throw an exception and how to test that it works properly.*/

  void assign(unsigned n, int value);
  /*Assigns new content to the vector object, dropping all the elements contained in the vector before the call and replacing them by those specified by the parameters. The new value of size will be n and all values stored in the vector will have the value of the 2nd parameter.

  If the new value of size will be larger than capacity, then this function must first expand capacity by either double (expand()) or by increasing the capacity by a specific amount (expand(n - capacity)), whichever results in the largest capacity.*/

  void push_back(int value);
  /*This function inserts a value at the back end of the array.

  Size will be increased by 1. However, If size will become larger than capacity, this function needs to first increase the capacity. In other words, if capacity and size are both 20 when this function is called, capacity must first be increased to 40 and then size can be increased to 21.

  Since other functions will also potentially need to expand (double) the capacity, call the private helper function named expand (see above) to do this for you.*/

  void pop_back();
  /*This function just needs to decrease size by 1.

  This function will never throw an exception. Calling pop_back on an empty vector will cause undefined behavior.*/

  void clear();
  /*This function reduces the size of the vector to 0.*/

  void resize(unsigned n, int value = 0);
  /*This function resizes the vector to contain size elements.

  If size is smaller than the current size(_size), this function just reduces the value of _size to size.

  If size is greater than the current size(_size), then the appropriate number of elements are inserted at the end of the vector, giving all of the new elements the value passed in through the 2nd parameter (value).

  If the new value of size will be larger than capacity, then the capacity must first be expanded by either doubling (expand()) or by increasing the capacity by a specific amount (expand(new size - current capacity)), whichever results in the largest capacity. Then, this function can increase the size appropriately.*/

  void reserve(unsigned n);
  /*This function requests that the capacity (the size of the dynamically allocated array) be set to n at minimum. This informs the vector of a planned increase in size.

  This function should NOT ever reduce the size of the vector. If n is larger than the current capacity then the capacity should be expanded to n.

  A call to this function never affects the elements contained in the vector, nor the vector's size.*/
};