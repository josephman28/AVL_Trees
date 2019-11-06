#include "AVL.hpp"

template <typename datatype>
typename AVL<datatype>::AVLNode * AVL<datatype>::minimum(AVLNode *t){
  while(t->left!=nullptr){
    t= t->left;
  }
  return t;
}

template <typename datatype>
datatype AVL<datatype>::minimo(){
  return (minimum(root)->key);
}

template <typename datatype>
typename AVL<datatype>::AVLNode * AVL<datatype>::maximum(AVLNode *t){
  while(t->right!=nullptr){
    t= t->right;
  }
  return t;
}

template <typename datatype>
datatype AVL<datatype>::maximo(){
  return (maximum(root)->key);
}

template <typename datatype>
typename AVL<datatype>::AVLNode * AVL<datatype>::predecessor(AVLNode *t){
  if(t->key != minimo()){
    if(t->left!=nullptr)
      return maximum(t->left);
    else{
      if(t->parent->right == t)
        return t->parent;
      else{
        while(t==t->parent->left)
          t=t->parent;
        return t;
      }
    }
  }
  return nullptr;
}

template <typename datatype>
typename AVL<datatype>::AVLNode * AVL<datatype>::successor(AVLNode *t){
  if(t->key != maximo()){
    if(t->right!=nullptr)
      return minimum(t->left);
    else{
      if(t->parent->left == t)
        return t->parent;
      else{
        while(t==t->parent->right)
          t=t->parent;
        return t;
      }
    }
  }
  return nullptr;
}

template <typename datatype>
size_t AVL<datatype>::height(AVLNode *t){

}

template <typename datatype>
AVL<datatype>::AVL(){
   root = nullptr;
   count = 0;
}

template <typename datatype>
AVL<datatype>::~AVL(){
  clear();
}

template <typename datatype>
void AVL<datatype>::insert(AVLNode* &t, datatype x, AVLNode* parent){
  if(t==nullptr){
    t = new AVLNode;
    t -> key = x;
    t -> left = nullptr;
    t -> right = nullptr;
    t -> parent = parent;
  }
  else{
    if(t->key != x){
      if(x<t->key){
        insert(t->left, x, t);
      }
      else{
        insert(t->right, x, t);
      }
    }

  }
  if(t->parent == nullptr) cout << "Parent de " << t->key << " es: nullptr" << endl;
  else cout << "Parent de " << t->key << " es: " << t->parent -> key << endl;
}

template <typename datatype>
void AVL<datatype>::insert(datatype x){
  cout << "I'm inserting " << x << endl;
  insert(root,x,nullptr);
  count ++;
}

template <typename datatype>
void AVL<datatype>::remove(AVLNode*&t, datatype x, AVLNode*parent){
  if(findNode(t, x)!=nullptr){
    AVLNode* tx = findNode(t, x);
    if((tx->left==nullptr)&&(tx->right==nullptr)){

      if(size()>0){
        if(tx->parent->right == tx)
          tx->parent->right = nullptr;
        else
          tx->parent->left = nullptr;
      }
      delete tx;
    }
    else if((tx->left!=nullptr)&&(tx->right!=nullptr)){
      // falta si tiene dos hijos
    }
    else{
      if((tx->left!=nullptr)&&(tx->right==nullptr)){
        tx->left->parent = tx->parent;
        if(tx->parent!= nullptr){
          if(tx->parent->right == tx)
            tx->parent->right = tx->left;
          else
            tx->parent->left = tx->left;
        }
        delete tx;
      }
      else{
        tx->right->parent = tx->parent;
        if(tx->parent!= nullptr){
          if(tx->parent->right == tx)
            tx->parent->right = tx->right;
          else
            tx->parent->left = tx->right;
        }
        delete tx;
      }
    }
  }
}

template <typename datatype>
void AVL<datatype>::remove(datatype y){
  remove(root, y, nullptr);
  count --;
}

template <typename datatype>
typename AVL<datatype>::AVLNode* AVL<datatype>::findNode(AVLNode *t, datatype k) const{
  if(t==nullptr) return nullptr;
  if(k==t->key) return t;
  if(k < t->key) return findNode(t->left, k);
  else return findNode(t->right, k);
}

template <typename datatype>
bool AVL<datatype>::find(datatype k) const{
  if(findNode(root, k)==nullptr)
    return false;
  return true;
}

template <typename datatype>
void AVL<datatype>::destroyRecursive(AVLNode *t){
  if(t!=nullptr){
    destroyRecursive(t->left);
    destroyRecursive(t->right);
    delete t;
  }
}

template <typename datatype>
void AVL<datatype>::clear(){
  cout << "I'm destroying" << endl;
  destroyRecursive(root);
  root = nullptr;
  count = 0;
}

template <typename datatype>
size_t AVL<datatype>::size(){
  return count;
}

template <typename datatype>
bool AVL<datatype>::empty(){
  return root == nullptr;
}

template <typename datatype>
void AVL<datatype>::display(AVLNode *t, int count){
  if(t!=nullptr){
    count++;
    display(t->left,count);
    cout << "(" << count-1 << ")" << t->key << " ";
    if(predecessor(t)==nullptr){
      cout << "pre" << " NULL ";
    }
    else
      cout << "pre" << predecessor(t)->key << " ";
    display(t->right,count);
  }

}

template <typename datatype>
void AVL<datatype>::display(){
  display(root,0);
}