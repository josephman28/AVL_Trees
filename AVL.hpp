#ifndef __AVLNode__
#define __AVLNode__
#include <iostream>

using namespace std;

template <typename datatype>
class AVL{
private:
  struct AVLNode {
    datatype key;
    AVLNode *left;
    AVLNode *right;
    AVLNode *parent;
  };
  AVLNode *root;
  size_t count;
  void insert(AVLNode*&t, datatype x, AVLNode*parent=nullptr);
  void remove(AVLNode*&t, datatype x, AVLNode*parent=nullptr);
  void destroyRecursive(AVLNode *t);
  void display(AVLNode *t, int count);
  AVLNode* findNode(AVLNode *t, datatype k) const;
  AVLNode* minimum(AVLNode *t);
  AVLNode* maximum(AVLNode *t);
  AVLNode* predecessor(AVLNode* t);
  AVLNode* successor(AVLNode* t);
  size_t height(AVLNode *t);

public:
  AVL();
  ~AVL();
  void clear();
  void insert(datatype x);
  void remove(datatype x);
  void display();
  bool find(datatype k) const;
  datatype minimo();
  datatype maximo();
  //void remove(datatype y);
  size_t size();
  bool empty();
};
#include "AVL.cpp"
#endif //__AVLNode__
