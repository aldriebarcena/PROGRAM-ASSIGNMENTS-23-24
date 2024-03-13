#include "SortedSet.h"
#include "IntList.h"
#include <iostream>
using namespace std;

SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet &cpy) : IntList(cpy) {}

SortedSet::SortedSet(const IntList &cpy) : IntList(cpy)
{
  IntList::selection_sort();
  IntList::remove_duplicates();
}

SortedSet::~SortedSet()
{
  this->IntList::~IntList();
}

bool SortedSet::in(int value)
{

  for (IntNode *curr = head; curr != nullptr; curr = curr->next)
  {
    if (curr->value == value)
    {
      return true;
    }
  }

  return false;
}

void SortedSet::add(int value)
{
  if (!in(value))
  {
    IntList::insert_ordered(value);
  }
}

void SortedSet::push_front(int data)
{
  add(data);
}

void SortedSet::push_back(int data)
{
  add(data);
}

void SortedSet::insert_ordered(int data)
{
  add(data);
}

SortedSet SortedSet::operator|(const SortedSet &rhs)
{
  SortedSet newSet;

  IntNode *curr = head;
  while (curr)
  {
    newSet.add(curr->value);
    curr = curr->next;
  }

  curr = rhs.head;
  while (curr)
  {
    newSet.add(curr->value);
    curr = curr->next;
  }

  return newSet;
}

SortedSet SortedSet::operator&(const SortedSet &rhs)
{
  SortedSet newSet;

  IntNode *i = head;
  IntNode *j = rhs.head;

  while (i != nullptr && j != nullptr)
  {
    if (i->value < j->value)
    {
      i = i->next;
    }
    else if (i->value > j->value)
    {
      j = j->next;
    }
    else // i->value == j->value
    {
      newSet.add(i->value);
      i = i->next;
      j = j->next;
    }
  }

  return newSet;
}

SortedSet &SortedSet::operator|=(const SortedSet &rhs)
{
  SortedSet tempSet;

  IntNode *curr = head;
  while (curr)
  {
    tempSet.add(curr->value);
    curr = curr->next;
  }

  curr = rhs.head;
  while (curr)
  {
    tempSet.add(curr->value);
    curr = curr->next;
  }

  for (IntNode *node = tempSet.head; node != nullptr; node = node->next)
  {
    add(node->value);
  }

  return *this;
}

SortedSet &SortedSet::operator&=(const SortedSet &rhs)
{
  if (this == &rhs)
  {
    return *this;
  }

  SortedSet tempSet;

  IntNode *i = head;
  IntNode *j = rhs.head;

  while (i != nullptr && j != nullptr)
  {
    if (i->value < j->value)
    {
      i = i->next;
    }
    else if (i->value > j->value)
    {
      j = j->next;
    }
    else // i->value == j->value
    {
      tempSet.add(i->value);
      i = i->next;
      j = j->next;
    }
  }

  clear();
  for (IntNode *node = tempSet.head; node != nullptr; node = node->next)
  {
    add(node->value);
  }

  return *this;
}
