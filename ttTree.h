#ifndef TTTREE_H
#define TTTREE_H

struct treeNode {
    
  int firstKey, secondKey;
  treeNode *left, *middle, *right, *parent;
    
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

  treeNode* search(treeNode*, int);

  int inOrder(TreeNode*);

  treeNode* getRootNode();

}; // ttTree

#endif
