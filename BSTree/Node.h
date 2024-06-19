
#include <iostream>
using namespace std;

struct Node
{
  string data;
  int cnt;
  Node *left;
  Node *right;

  Node(string val);
};
