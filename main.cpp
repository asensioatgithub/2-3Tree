#include <iostream>
#include "ttTree.h"

int main() {

  ttTree tree;

  tree.ttTreeInsert(5);
  tree.ttTreeInsert(10);
  tree.ttTreePrint(tree.getRootNode());
  
} // main
