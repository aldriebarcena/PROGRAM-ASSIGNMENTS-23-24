using namespace std;
#include "IntList.h"
#include <vector>
#include <algorithm>

IntList::IntList()
{
  head = nullptr; // creates empty list
}

IntList::~IntList()
{
  while (head) // deletes each node in list
  {
    IntNode *next = head->next; // temp pointer to the value of next to head
    delete head;                // deletes head
    head = next;                // makes new head the next value
  }
}

void IntList::clear()
{
  while (head)
  {                             // until head becomes empty/nullptr
    IntNode *temp = head->next; // create temp node to store next node
    delete head;                // delete current node
    head = temp;                // move the head to next node
  }
  tail = nullptr;

  // same thing as deconstructor, but makes tail nullptr as well
}

void IntList::push_front(int value)
{
  IntNode *newNode = new IntNode(value); // creates node with value

  if (!head)
  {                 // if the list is empty
    head = newNode; // sets both head and tail to new node
    tail = newNode;
  }
  else
  {
    newNode->next = head; // make next pointer = head of the list, makes the new node the first node of the list
    head = newNode;       // makes head the new node
  }
}

void IntList::pop_front()
{
  if (head)
  {                       // if the list isn't empty
    IntNode *temp = head; // temp store current head node
    head = head->next;    // move the head to the next node
    delete temp;          // deletes the old head node
  }

  // creates a temporary node for current head, then moves the head to the next node, then deletes temp
}

bool IntList::empty() const
{
  if (head == nullptr)
  {
    return true;
  }
  return false;
  // if no head, then empty
}

const int &IntList::front() const
{
  return head->value;
}

const int &IntList::back() const
{
  return tail->value;
}

ostream &operator<<(ostream &out, const IntList &list)
{
  IntNode *curr = list.head; // creates current node

  while (curr != nullptr) // iterates through entire list
  {
    out << curr->value;

    if (curr->next != nullptr)
    { // if curr isn't the last node (if the next value after the current value isnt null)
      out << " ";
    }

    curr = curr->next; // moves curr to the next node
  }

  return out;
}

IntList::IntList(const IntList &cpy)
{
  head = nullptr; // initializes new list

  for (IntNode *current = cpy.head; current; current = current->next)
  {
    push_back(current->value);
  }
}

IntList &IntList::operator=(const IntList &rhs)
{
  if (this != &rhs)
  {
    clear(); // clears left side

    for (IntNode *current = rhs.head; current; current = current->next)
    {
      push_back(current->value); // copying
    }
  }

  return *this;
}

void IntList::push_back(int value)
{
  IntNode *newNode = new IntNode(value);

  if (!head)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    IntNode *current = head;
    while (current->next != nullptr)
    {
      current = current->next;
    }

    current->next = newNode;
    tail = newNode;
  }
}

void IntList::selection_sort()
{
  for (IntNode *current = head; current != nullptr; current = current->next)
  {
    IntNode *minNode = current; // keeps track of lowest node
    for (IntNode *nextNode = current->next; nextNode != nullptr; nextNode = nextNode->next)
    {
      if (nextNode->value < minNode->value)
      {
        minNode = nextNode; // sets new minNode
      }
    }

    int temp = current->value;
    current->value = minNode->value;
    minNode->value = temp;
  }
}

void IntList::insert_ordered(int value)
{
  IntNode *newNode = new IntNode(value);

  if (!head || head->value >= value) // if empty list or head is >= value
  {
    newNode->next = head; // new node becomes head
    head = newNode;
  }
  else
  {
    IntNode *current = head;                                         // current node is initialized
    while (current->next != nullptr && current->next->value < value) // ends at end of list or next node is greater than value
    // used to find correct position to place node
    {
      current = current->next;
    }

    newNode->next = current->next; // inserts
    current->next = newNode;
  }
}

void IntList::remove_duplicates()
{
  if ((!empty()) && (head != tail)) //  not empty and list has more than 1 element
  {
    for (IntNode *i = head; i != nullptr; i = i->next)
    {
      IntNode *prev = i; // initializes a previous node
      for (IntNode *j = i->next; j != nullptr; j = j->next)
      {
        if ((j->value) == (i->value)) // duplicate found
        {
          if (j == tail) // condition: duplicate found is the tail
          {
            delete j;
            tail = prev;
            tail->next = nullptr;
            j = prev;
          }
          else
          {
            prev->next = j->next; // skips j node
            delete j;             // deletes j
            j = prev;             // updates
          }
        }
        else
        {
          prev = prev->next; // continues iteration
        }
      }
    }
  }
}