#include <iostream>
#include <stack>

#include "ttTree.h"

using namespace std;

/*

Private member variables

*/

struct treeNode *root;
const int NULL_KEY = -1000;


/*

Public Methods

*/

ttTree::ttTree() {

  root = NULL;

} // ttTree

ttTree::~ttTree() {} // ~ttTree

int ttTree::ttTreeInsert(int key) {

  // inserts node with value 'key'
  // returns 1 if successful
  // returns 0 if key already exists

  if (root == NULL) { // empty tree

    root = new treeNode;
    root->firstKey = key;

  } else {

    stack<treeNode*> S = search(root, key);

  } // else
  
} // ttTreeInsert

int ttTree::ttTreeDelete(int key) {
  // deletes node with 'key' value
  // returns 1 if successful
  // returns 0 if key is not in tree


} // ttTreeDelete

void ttTree::ttTreePrint(treeNode *root) {

  // prints contents of tree
  
} // ttTreePrint





/*

Test Methods

*/





bool ttTree::isLeaf(treeNode *node) {
  // checks if the node is a leaf

  if (node->left == NULL && node->middle == NULL && node->right == NULL) {

    return true;

  } else {

    return false;

  } // if

} // isLeaf


bool ttTree::isTwoNode(treeNode *node) {

  if (node->secondKey == NULL_KEY) {

    return true;

  } else {
    
    return false;

  } // if

} // isTwoNode


stack<treeNode*> ttTree::search(treeNode *node, int key) {

  // Searches the tree for the key and returns an 
  // inorder stack of node pointers

  stack<treeNode*> s;

  while (node != NULL) {

    s.push(node);

    if (isTwoNode(node)) {

      if (key == node->firstKey) {

	break;

      } else if (key < node->firstKey) {

	node = node->left;

      } else {

	node = node->middle;
	
      } // if else

    } else {

      if ((key == node->firstKey) || (key == node->secondKey)) {

	break;

      } else if (key < node->firstKey) {

	node = node->left;
      
      } else if (key < node->secondKey) {

	node = node->middle;
 
      } else {

	node = node->right;

      } // if else

    } // if else

  } // while

  return s;

} // search

treeNode* ttTree::getRootNode() {

  return root;

} // getRootNode 
