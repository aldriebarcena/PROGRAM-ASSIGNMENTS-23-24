#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "Node.h"
#include <iostream>

class BSTree
{
private:
   Node *root;

   // helper functions for remove, search, and height
   void remove(Node *parent, Node *curr, const string &key);
   bool search(Node *curr, const string &key) const;
   int height_of(Node *tree) const;

   // helper functions for pre/post/in order functions
   void preOrder(Node *curr) const;
   void postOrder(Node *curr) const;
   void inOrder(Node *curr) const;

   // helper functions to find the min/max
   Node *findMax(Node *curr) const;
   Node *findMin(Node *curr) const;

   // helper functions for destructor, copy constructor, and copy assignment
   Node *cloneTree(Node *treeToClone);
   void deleteTree(Node *treeToDelete);

public:
   BSTree();
   ~BSTree();
   BSTree(const BSTree &cpy);
   BSTree &operator=(const BSTree &rhs);

   void insert(const string &newString);

   void remove(const string &key)
   {
      remove(nullptr, root, key);
   }

   bool search(const string &key) const
   {
      return search(root, key);
   }

   string largest() const;
   string smallest() const;
   int height(const string &key) const;

   void preOrder() const
   {
      preOrder(root);
   }
   void postOrder() const
   {
      postOrder(root);
   }
   void inOrder() const
   {
      inOrder(root);
   }
};

#endif // __BSTREE_H__
