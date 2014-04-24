#include <iostream>
#include "ttTree.h"

int main() {

  ttTree tree;

  tree.ttTreeInsert(5);
  tree.ttTreeInsert(10);
  tree.ttTreeInsert(100);
  tree.ttTreeInsert(300);
  tree.ttTreeInsert(600);
  tree.ttTreeInsert(700);
  tree.ttTreeInsert(800);
  tree.ttTreePrint(tree.getRootNode());
  
} // main
