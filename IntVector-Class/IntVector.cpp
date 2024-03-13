using namespace std;

#include "IntVector.h"
#include <stdexcept>

IntVector::IntVector(unsigned capacity, int value)
{
  _size = capacity;
  _capacity = capacity;

  if (capacity > 0)
  {
    _data = new int[_capacity]; // creates allocated memory size of capacity

    for (unsigned i = 0; i < _capacity; i++)
    {
      _data[i] = value;
    }
  }
  else
  {
    _data = nullptr; // if no capacity, no array needed
  }
}

IntVector::~IntVector()
{
  delete[] _data; // deallocates to prevent memory leaks
}

unsigned IntVector::size() const
{
  return _size;
}

unsigned IntVector::capacity() const
{
  return _capacity;
}

bool IntVector::empty() const
{
  if (_size == 0)
  {
    return true;
  }
  return false;
}

const int &IntVector::at(unsigned index) const
{
  if (index >= _size)
  {
    throw out_of_range("IntVector::at_range_check");
  }
  return _data[index];
}

const int &IntVector::front() const
{
  return _data[0];
}

const int &IntVector::back() const
{
  return _data[_size - 1];
}

int &IntVector::at(unsigned index)
{
  if (index >= _size)
  {
    throw out_of_range("IntVector::at_range_check");
  }
  return _data[index];
}

int &IntVector::front()
{
  return _data[0];
}

int &IntVector::back()
{
  return _data[_size - 1];
}

void IntVector::expand()
{
  if (_capacity == 0)
  {
    _capacity++;
  }
  else
  {
    _capacity *= 2;
  }

  int *newData = new int[_capacity];

  for (unsigned i = 0; i < _size; i++)
  {
    newData[i] = _data[i];
  }

  delete[] _data;
  _data = newData;
}

void IntVector::expand(unsigned amount)
{
  _capacity += amount;

  int *newData = new int[_capacity];

  for (unsigned i = 0; i < _size; i++)
  {
    newData[i] = _data[i];
  }

  delete[] _data;
  _data = newData;
}

void IntVector::insert(unsigned index, int value)
{

  if (index > _size)
  {
    throw out_of_range("IntVector::insert_range_check");
  }
  else
  {
    if (_size == _capacity)
    {
      expand();
    }

    _size++;

    for (unsigned i = _size; i > index; --i)
    {
      _data[i] = _data[i - 1];
    }

    _data[index] = value;
  }
}

void IntVector::erase(unsigned index)
{
  if (index >= _size)
  {
    throw std::out_of_range("IntVector::erase_range_check");
  }

  for (unsigned i = index; i < _size - 1; ++i)
  {
    _data[i] = _data[i + 1];
  }

  _size--;
}

void IntVector::assign(unsigned n, int value)
{
  // n = new size

  unsigned testCapacity = (_capacity) + (n - _capacity);

  if (n > _capacity)
  {
    if (testCapacity > (_capacity * 2))
    {
      expand(n - _capacity);
    }
    else
    {
      expand();
    }
  }
  else if (n < _size)
  {
    _size = n;
  }

  for (unsigned i = 0; i < n; i++)
  {
    _data[i] = value;
  }

  _size = n;
}

void IntVector::push_back(int value)
{
  if (_size == _capacity)
  {
    expand();
  }

  _data[_size] = value;
  _size++;
}

void IntVector::pop_back()
{
  _size--;
}

void IntVector::clear()
{
  _size = 0;
}

void IntVector::resize(unsigned n, int value)
{

  unsigned testCapacity = (_capacity) + (n - _capacity);

  if (n > _capacity)
  {
    if (testCapacity > (_capacity * 2))
    {
      expand(n - _capacity);
    }
    else
    {
      expand();
    }
  }

  if (n < _size)
  {
    _size = n;
  }
  else if (n > _size)
  {
    for (unsigned i = _size; i < n; i++)
    {
      push_back(value);
    }
  }
}

void IntVector::reserve(unsigned n)
{
  if (n > _capacity)
  {
    expand(n - _capacity);
  }
}