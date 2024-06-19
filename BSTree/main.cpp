#include <iostream>
#include <limits>
#include "BSTree.h"

using namespace std;

void printOrders(BSTree tree)
{
  cout << "Preorder = ";
  tree.preOrder();
  cout << endl;
  cout << "Inorder = ";
  tree.inOrder();
  cout << endl;
  cout << "Postorder = ";
  tree.postOrder();
  cout << endl;
}

int menu()
{
  int choice = 0;
  cout << endl
       << "Enter menu choice: ";
  cout << endl;
  cout
      << "1. Insert" << endl
      << "2. Remove" << endl
      << "3. Print" << endl
      << "4. Search" << endl
      << "5. Smallest" << endl
      << "6. Largest" << endl
      << "7. Height" << endl
      << "8. Quit" << endl;
  cin >> choice;

  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return choice;
}

int main()
{
  // Pass all your tests before running the executable main
  // run_tests();  // TODO: Remove before submitting
  // return 0;

  BSTree tree;

  int choice = menu();

  string entry;

  while (choice != 8) // continue to ask for options if the choice isn't 8

  {
    if (choice == 1) // insert
    {
      cout << "Enter string to insert: " << endl;
      string insert;
      getline(cin, insert);
      tree.insert(insert); // calls insert on desired string
    }
    else if (choice == 2) // remove
    {
      cout << "Enter string to remove: " << endl;
      string remove;
      getline(cin, remove);
      tree.remove(remove); // calls remove on desired string
    }
    else if (choice == 3) // print
    {
      printOrders(tree); // prints all types of print functions
    }
    else if (choice == 4) // search
    {
      cout << "Enter string to search for: " << endl;
      string search;
      getline(cin, search);
      if (!tree.search(search)) // if the node isn't found
      {
        cout << "Not Found" << endl;
      }
      else // if the node is found
      {
        cout << "Found" << endl;
      }
    }
    else if (choice == 5) // smallest
    {
      cout << "Smallest: " << tree.smallest() << endl;
    }
    else if (choice == 6) // largest
    {
      cout << "Largest: " << tree.largest() << endl;
    }
    else if (choice == 7) // height
    {
      cout << "Enter string: " << endl;
      string height;
      getline(cin, height);
      cout << "Height of subtree rooted at " << height << ": " << tree.height(height) << endl;
    }
    // fix buffer just in case non-numeric choice entered
    choice = menu();
  }
  return 0;
}
