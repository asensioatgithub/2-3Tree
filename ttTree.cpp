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

    cout << "first insert" << endl;

  } else {

    stack<treeNode*> s = search(root,key);

    stack<treeNode*> butts(s);
    
    while (!butts.empty()) {

      cout << butts.top() << endl;
      butts.pop();

    } // while
    
    int dir = 0;
    struct treeNode *node = new treeNode;

    node = s.top();
    s.pop();

    if ((node->firstKey == key) || (node->secondKey == key)) return 0;

    int count = 0;

    while (count < (s.size() + 1)) {

      struct treeNode *node1 = new treeNode;
      struct treeNode *node2 = new treeNode;
      struct treeNode *parent = new treeNode;

      node1->firstKey = minimum(node->firstKey, node->secondKey, key);
      node2->firstKey = maximum(node->firstKey, node->secondKey, key);
      int temp = middle(node->firstKey, node->secondKey, key);

      if (!s.empty()) {
	
	parent = s.top();
	s.pop();
	
      } //if

      if (isTwoNode(node)) {

	cout << "isTwoNode(node)" << endl;

	node->firstKey = min(node->firstKey, key);
	node->secondKey = max(node->firstKey, key);
	break;

      } else {  // current node is a 3 node

 
	if (node == parent->left) dir = 0;
	if (node == parent->middle) dir = 1;
	if (node == parent->right) dir = 2;

	if (isTwoNode(parent)) {

	  cout << "isTwoNode(parent)" << endl;

	  switch(dir) {

	  case 0:
	    
	    parent->secondKey = parent->firstKey;
	    parent->firstKey = temp;
	    parent->left = node1;
	    parent->right = parent->middle;
	    parent->middle = node2;
	    break;
	    
	  case 1:
	    
	    parent->secondKey = temp;
	    parent->middle = node1;
	    parent->right = node2;
	    break;
	    
	  } // switch
	  
	} else if (s.empty()) {

	  cout << "root node!" << endl;

	  treeNode *newRoot = new treeNode;
	  newRoot->firstKey = temp;
	  newRoot->left = node1;
	  newRoot->middle = node2;
	  root = newRoot;

	} else {

	  cout << "isThreeNode(parent)" << endl;

	  switch(dir) {

	  case 0:
	    
	    parent->temp = parent->right;
	    parent->right = parent->middle;
	    parent->middle = node2;
	    parent->left = node1;
	    break;
	  
	  case 1:
	    
	    parent->temp = parent->right;
	    parent->right = node2;
	    parent->middle = node1;
	    break;
	    
	  case 2:
	    
	    parent->right = node1;
	    parent->temp = node2;
	    break;
	    
	  } // switch
	  
	} // if else

      } // else

      key = temp;
      node = parent;
      count++;

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

  cout << "search works!" << endl;

  return s;

} // search

treeNode* ttTree::getRootNode() {

  return root;

} // getRootNode 


int ttTree::maximum(int x, int y, int z) {

  int max = x;

  if (y > max) max = y;
  if (z > max) max = z;
  return max;

} // max

int ttTree::minimum(int x, int y, int z) {

  int min = x;

  if (y < min) min = y;
  if (z < min) min = z;
  return min;

} // min


int ttTree::middle(int x, int y, int z) {
  
  int mid = 0;

  if ((z < x && y > x) || (y < x && z > x)) mid = x;
  if ((x < y && z > y) || (z < y && x > y)) mid = y;
  if ((y < z && x > z) || (x < z && y > z)) mid = z;
  return mid;

} // mid
