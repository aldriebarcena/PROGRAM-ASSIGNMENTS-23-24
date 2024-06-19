#include <iostream>
#include "BSTree.h"
#include <algorithm>

using namespace std;

BSTree::BSTree() // initializes empty tree and sets root to nullptr
{
  root = nullptr;
}

BSTree::~BSTree() // completely empties out tree
{
  deleteTree(root);
}
BSTree::BSTree(const BSTree &cpy) // copy constructor
{
  root = cloneTree(cpy.root);
}
BSTree &BSTree::operator=(const BSTree &rhs) // copy assignment operator
{
  if (this != &rhs)
  {
    deleteTree(root);
    root = cloneTree(rhs.root);
  }
  return *this;
}

// inserts new node in BST and still keeps BST properties
void BSTree::insert(const string &newString)
{
  // if the tree is empty, inserts node at the root and sets it's count to 1
  if (root == nullptr)
  {
    root = new Node(newString);
    root->cnt = 1;
    return;
  }

  // initializes curr pointer to search for spot to put new node
  Node *curr = root;
  // loop block of code until it finds it's place to insert
  while (curr != nullptr)
  {
    if (newString == curr->data) // if there's already a node that exists, increment count
    {
      curr->cnt++;
      return;
    }
    if (newString < curr->data) // go left if it's less than current node pointer
    {
      if (curr->left == nullptr) // if the left is empty, insert node there and initialize count to 1
      {
        curr->left = new Node(newString);
        curr->left->cnt = 1;
        return;
      }
      else // if there is a node at curr->left, continue going left
      {
        curr = curr->left;
      }
    }
    else // go right if it's greater than current node pointer
    {
      if (curr->right == nullptr) // if the right is empty, insert node there and initialize count to 1
      {
        curr->right = new Node(newString);
        curr->right->cnt = 1;
        return;
      }
      else
      {
        curr = curr->right; // if there is a node at curr->right, continue going left
      }
    }
  }
}

// removes node of given key, this is a helper function and curr is set to root when called, tracks parent node as well
void BSTree::remove(Node *parent, Node *curr, const string &key)
{
  if (curr == nullptr) // if empty tree, do nothing
  {
    return;
  }
  if (key < curr->data) // if key is less than curr, recursively call remove on it's left
  {
    remove(curr, curr->left, key);
  }
  else if (key > curr->data) // if key is greater than curr, recursively call remove on it's right
  {
    remove(curr, curr->right, key);
  }
  else // when the node is found, this block is called
  {
    if (curr->cnt > 1) // if there's multiple nodes of the key, just decrement it's count and return
    {
      curr->cnt--;
      return;
    }
    else
    {
      if (curr->left == nullptr && curr->right == nullptr) // if the node to remove is a leaf node
      {
        if (parent == nullptr) // if the node to remove is a root
        {
          root = nullptr; // set the root to nullptr to prevent dangling root pointer
        }
        else if (parent->right == curr) // if the curr is a right child of the parent, set it's parent's right to null
        {
          parent->right = nullptr;
        }
        else
        {
          parent->left = nullptr; // if the curr is a left child of the parent, set it's parent's left to null
        }
        delete curr; // delete the node
        return;
      }
      else if (curr->left != nullptr) // if the node to remove is an internal node with a left child
      {
        Node *maxLeft = findMax(curr->left); // find the max node on it's left
        curr->data = maxLeft->data;          // copy maxLeft's data and count to curr
        curr->cnt = maxLeft->cnt;
        maxLeft->cnt = 1;                        // reset maxLeft's count to 1 to prevent edge case issues with decrementing the count
        remove(curr, curr->left, maxLeft->data); // recursively call remove on the node to remove curr's left
      }
      else // if the node to remove is an internal node with only a right child
      {
        Node *minRight = findMin(curr->right); // find the min node on it's right
        curr->data = minRight->data;           // copy minRight's data and count to curr
        curr->cnt = minRight->cnt;
        minRight->cnt = 1;                         // reset minRight's count to 1 to prevent edge case issues with decrementing the count
        remove(curr, curr->right, minRight->data); // recursively call remove on the node to remove curr's right
      }
    }
  }
}

// search helper function that calls this function with curr as root
bool BSTree::search(Node *curr, const string &key) const
{
  if (curr == nullptr) // if tree is empty, search naturally returns false
  {
    return false;
  }
  if (key == curr->data) // base case, if key is finally found, it returns true
  {
    return true;
  }
  if (key < curr->data) // if the key is less than curr, recursively call search on it's left side
  {
    return search(curr->left, key);
  }
  else
  {
    return search(curr->right, key); // if the key is greater than curr, recursively call search on it's right side
  }
}

// finds the largest string in the tree
string BSTree::largest() const
{
  if (root == nullptr) // if the tree is empty, it just returns an empty string
    return "";

  return findMax(root)->data; // returns the findMax helper function to return the data of the max string in the tree
}

// finds the smallest string in the tree
string BSTree::smallest() const
{
  if (root == nullptr) // if the tree is empty, it just returns an empty string
    return "";

  return findMin(root)->data; // returns the findMin helper function to return the data of the min string in the tree
}

// returns the height of given node
int BSTree::height(const string &key) const
{

  Node *curr = root; // initializes curr to the top of the tree

  // searchs for key
  while (curr != nullptr && curr->data != key) // continue loop while curr isn't null
  {
    if (key < curr->data) // if the key is less than curr, curr goes left
    {
      curr = curr->left;
    }
    else // if the key is greater than curr, curr goes right
    {
      curr = curr->right;
    }
  }

  if (curr == nullptr) // if the key isn't found, returns the height of empty tree, -1
  {
    return -1;
  }

  return height_of(curr); // if it is found, return the helper function height_of, starting at the target node
}

// finds the height of a specific node
int BSTree::height_of(Node *tree) const
{

  if (tree == nullptr) // if the tree is empty, return -1
  {
    return -1;
  }
  // if not empty, recursively call itself on both sides of the tree, and return which ever height is bigger + 1
  return max(height_of(tree->left), height_of(tree->right)) + 1;
}

// recursive print function that prints data first, then recursively calls itself on left and right
void BSTree::preOrder(Node *curr) const
{
  if (curr == nullptr) // if the tree is empty, just return
  {
    return;
  }
  cout << curr->data << "(" << curr->cnt << "), "; // prints data and cnt of curr
  preOrder(curr->left);                            // recursively calls itself on it's left and right
  preOrder(curr->right);
}
// recurisve print function that calls itself on left and right first, then prints it's data
void BSTree::postOrder(Node *curr) const
{
  if (curr == nullptr) // if the tree is empty, just return
  {
    return;
  }
  postOrder(curr->left); // recursively calls itself on it's left and right
  postOrder(curr->right);
  cout << curr->data << "(" << curr->cnt << "), "; // prints data and cnt of curr
}
// recursive print functin that calls itself on the left first, then prints it's data/count, then calls itself on the right
void BSTree::inOrder(Node *curr) const
{
  if (curr == nullptr) // if the tree is empty, just return
  {
    return;
  }
  inOrder(curr->left);                             // recursively calls itself on the left
  cout << curr->data << "(" << curr->cnt << "), "; // prints data and cnt of curr
  inOrder(curr->right);                            // recursively calls itself on the right
}

// OTHER HELPER FUNCTIONS --------------

// helper function that finds the max value from the given node
Node *BSTree::findMax(Node *curr) const
{
  while (curr->right != nullptr) // continnues going right until it can't anymore (by property of BST)
  {
    curr = curr->right;
  }
  return curr;
}

// helper function that finds the min value from the given node
Node *BSTree::findMin(Node *curr) const
{
  while (curr->left != nullptr) // continnues going left until it can't anymore (by property of BST)
  {
    curr = curr->left;
  }
  return curr;
}

// helper function that recursively deletes itself
void BSTree::deleteTree(Node *treeToDelete)
{
  if (treeToDelete != nullptr) // continue loop until the tree to delete doesn't exist
  {
    deleteTree(treeToDelete->left); // deletes tree on the left and right
    deleteTree(treeToDelete->right);
    delete treeToDelete;
  }
}

// helper function that recursively clones itself
Node *BSTree::cloneTree(Node *treeToClone)
{
  if (treeToClone == nullptr) // if it's an empty tree, return nothing
  {
    return nullptr;
  }
  Node *clonedTree = new Node(treeToClone->data); // creates new node that copies the data
  clonedTree->cnt = treeToClone->cnt;             // copies the cnt
  // clones this new node's left and right
  clonedTree->left = cloneTree(treeToClone->left);
  clonedTree->right = cloneTree(treeToClone->right);
  return clonedTree; // return the copies tree
}
