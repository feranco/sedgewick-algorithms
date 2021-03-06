#ifndef TREES_H
#define TREES_H

#include <iostream>

typedef char Item;

class BinaryTree {
  struct Node {
    Item item;
    Node* l;
    Node* r;
    Node (Item x) {item = x; l = r = 0;}
  };
  typedef Node* link;
  link root;

 public:
  BinaryTree () {root = 0;};
  BinaryTree (const char* s, const char* l);
  link preorderBuild (link t, const char* s, const char* l);
  void dump (std::ostream& out, link t, int h) const;
  link getRoot (void);
  friend std::ostream& operator<< (std::ostream& out, const BinaryTree& bt);
  void removeLeaf (Item r);
  friend bool doRemoveLeaf (link t, Item r);
  int countLeaf (link t);
  int countMix (link t);
  bool isLeaf (link t);
  int  internalPathLength (link t, int l);
  void preorderTraversal (void);
  void inorderTraversal (void);
  void postorderTraversal (void);
};

void testTreeTraversal (void);
void levelorderTraversal (const char* preOrder, const char* inOrder);
void testLevelorderTraversal();

#endif
