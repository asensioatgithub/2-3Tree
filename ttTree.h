#ifndef TTTREE_H
#define TTTREE_H

#include <stack>

struct treeNode {
    
  int firstKey, secondKey;
  treeNode *left, *middle, *right, *temp;
    
}; // treeNode

class ttTree {

 private:
  treeNode *root;

 public:
  ttTree();
  ~ttTree();

  int ttTreeInsert(int);
  int ttTreeDelete(int);

  void ttTreePrint(treeNode*);

  // TESTING

  bool isLeaf(treeNode*);

  bool isTwoNode(treeNode*);

  std::stack<treeNode*> search(treeNode*, int);

  int inOrder(treeNode*);

  treeNode* getRootNode();

  int maximum(int,int,int);
  int minimum(int,int,int);
  int middle(int,int,int);
}; // ttTree

#endif
