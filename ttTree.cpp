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

  if (root == NULL) {

    root = new treeNode;
    root->firstKey = key;

  } else {

    stack<treeNode*> s = search(root,key);
    
    int dir = 0;
    treeNode *nodeTemp1 = new treeNode;
    treeNode *nodeTemp2 = new treeNode;
    treeNode *node = new treeNode;

    node = s.top();
    s.pop();

    if ((node->firstKey == key) || (node->secondKey == key)) return 0;

    while (!s.empty()) {

	if (isLeaf(node)) {

	  nodeTemp1 = NULL;
	  nodeTemp2 = NULL;

	} // if is leaf node

	if (isTwoNode(node)) {

	  node->firstKey = min(node->firstKey, key);
	  node->secondKey = max(node->firstKey, key);

	  switch (dir) {

	  case 0:
	    node->left = nodeTemp1;
	    node->right = node->middle;
	    node->middle = nodeTemp2;
	  case 1:
	    node->middle = nodeTemp1;
	    node->right = nodeTemp2;
	  
	  } // switch

	  break;

	} else {  // current node is a 3 node

	  treeNode *node1 = new treeNode;
	  treeNode *node2 = new treeNode;
	  
	  
	  




	}


    } // while

  } // if tree is empty






} // ttTreeInsert


























// int ttTree::ttTreeInsert(int key) {

//   // inserts node with value 'key'
//   // returns 1 if successful
//   // returns 0 if key already exists

//   if (root == NULL) { // empty tree

//     root = new treeNode;
//     root->firstKey = key;
    
//   } else {

//     stack<treeNode*> s = search(root, key);

//     treeNode *node = new treeNode;
//     treeNode *node1 = new treeNode;
//     treeNode *node2 = new treeNode;
//     treeNode *parent = new treeNode;

//     if (!s.empty()) node = s.top();

//     s.pop(); // removes top element of stack

//     // return 0 if key exists
//     if ((node->firstKey == key) || (node->secondKey == key)) return 0;

//     while (!s.empty()) {

//       if (isTwoNode(node)) {   // if the node is a 2-node

// 	 if (key < node->firstKey) {

// 	   node->secondKey = node->firstKey;
// 	   node->firstKey = key;

// 	 } else {

// 	   node->secondKey = key;

// 	 } // if else

//        } else {  // if the node is a 3-node

// 	   treeNode *nodeTemp1 = new treeNode;
// 	   treeNode *nodeTemp2 = new treeNode;

// 	   nodeTemp1 = node1;
// 	   nodeTemp2 = node2;

// 	   int temp = mid(node->firstKey,node->secondKey,key);

// 	   node1->firstKey = min(node->firstKey,node->secondKey,key);
// 	   node2->firstKey = max(node->firstKey,node->secondKey,key);

// 	   parent = s.top();
// 	   s.pop();

// 	   if (isTwoNode(parent)) {

// 	     if (parent->left == node) {

// 	       parent->secondKey = parent->firstKey;
// 	       parent->firstKey = temp;
// 	       parent->left = node1;
// 	       parent->right = parent->middle;
// 	       parent->middle = node2;

// 	     } else {

// 	       parent->secondKey = temp;
// 	       parent->middle = node1;
// 	       parent->right = node2;

// 	     } // if else

// 	     break;

// 	   } else {

	   
// 	   } // if else
      
//       } // if else

//     } // while

//   } // if else

//   return 1;
  
// } // ttTreeInsert



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


int ttTree::max(int x, int y, int z) {

  int max = x;

  if (y > max) max = y;
  if (z > max) max = z;
  return max;

} // max

int ttTree::min(int x, int y, int z) {

  int min = x;

  if (y < min) min = y;
  if (z < min) min = z;
  return min;

} // min


int ttTree::mid(int x, int y, int z) {
  
  int mid = 0;

  if ((z < x && y > x) || (y < x && z > x)) mid = x;
  if ((x < y && z > y) || (z < y && x > y)) mid = y;
  if ((y < z && x > z) || (x < z && y > z)) mid = z;
  return mid;

} // mid
