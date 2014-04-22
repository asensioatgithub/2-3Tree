#include <iostream>
#include "ttTree.h"

using namespace std;

struct treeNode *root;

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

    treeNode node = search(root, key);
    
    if (node 

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


//
//
//
//
// TEST METHODS
//
//
//
//

bool ttTree::isLeaf(treeNode *node) {
  // checks if the node is a leaf

  if (node->left == NULL && node->middle == NULL && node->right == NULL) {
    return true;
  } else {
    return false;
  } // if

} // isLeaf

treeNode* ttTree::search(treeNode *node, int key) {

  if (isLeaf(node->left) && isLeaf(node->middle) && isLeaf(node->right)) {

    return node;

  } else {

    if (key <= node->firstKey) {

      return search(node->left, key);

    } else if (key <= node->secondKey) {

      return search(node->middle, key);

    } else {

      return search(node->right, key);

    } // if else

  } // if

} // search

int ttTree::inOrder(*node) {

  if (node != NULL) {

    inOrder(node->left);
    if (node->firstKey != NULL) return node->firstKey;
    inOrder(node->middle);
    if (node->secondKey != NULL) return node->secondKey;
    inOrder(node->right);

  } // if

} // inOrder

treeNode* ttTree::getRootNode() {

  return root;

} // getRootNode
