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
int AVL<datatype>::height(AVLNode *t){
  if (t == nullptr)
    return 0;
  else
    return 1 + max(height(t->left),height(t->right));
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

  balance(t);
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
void AVL<datatype>::remove(AVLNode*&t, datatype x){
  if(findNode(t, x)!=nullptr){
    AVLNode* tx = findNode(t, x);
    if((tx->left==nullptr)&&(tx->right==nullptr)){

      if(!empty()){
        if(tx->parent->right == tx)
          tx->parent->right = nullptr;
        else
          tx->parent->left = nullptr;
      }
      delete tx;
      tx = nullptr;

    }
    else if((tx->left!=nullptr)&&(tx->right!=nullptr)){

      AVLNode * temp = minimum(tx->right);
      tx->key = temp->key;
      if(height(temp)<=1){

        if(temp->parent->left==temp)
          temp->parent->left = nullptr;
        else
          temp->parent->right = nullptr;
        delete temp;
        temp = nullptr;
      }
      else
        remove(temp, temp->key);
      count++;
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
        tx= nullptr;
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
        tx = nullptr;
      }
    }

  }

  count--;
  cout << "OMEEE " << t->key << endl;
  balance(t);
  if(t!=nullptr){
    if(t->parent == nullptr) cout << "Parent de " << t->key << " es: nullptr" << endl;
    else cout << "Parent de " << t->key << " es: " << t->parent -> key << endl;
  }
}

template <typename datatype>
void AVL<datatype>::remove(datatype y){
  remove(root, y);
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
void AVL<datatype>::display(AVLNode *t, int count, vector<string>& s) {
  if(t != nullptr){
    count++;
    display(t->left, count, s);
    string num = to_string(t->key);
    for(unsigned i = 0; i < s.size(); i++){
      if(i == unsigned(count-1))
s[i] += to_string(t->key);
      else{
for(unsigned j = 0; j < num.length(); j++)
 s[i] += " ";
      }
    }
    display(t->right, count, s);
  }
}

template <typename datatype>
void AVL<datatype>::display() {
  int h = height(root);
  vector<string> s(h, "");
  display(root, 0, s);
  for(unsigned i = 0; i < s.size(); i++)
    cout << s[i] << endl;
}

template <typename datatype>
void AVL<datatype>::balance(AVLNode *  & t){

	if(t == nullptr){
		return;
  }

	if(height(t -> left) - height(t -> right) > 1){

    cout << "Tengo que balancear a " << t->key << endl;
		if(height(t -> left -> left) >= height(t -> left ->right)){
			left_rot(t);
    }

		else {
      rightR_leftR(t);
    }
	}

	else if(height(t -> right) - height(t->left) > 1){
    cout << "Tengo que balancear a " << t->key << endl;
		if(height(t->right->right) >= height(t->right->left)){
			right_rot(t);
    }

		else {
      leftR_rightR(t);
    }
	}

  cout << "No tuve que balancear a " << t->key << endl;
	t -> bf= max(height(t -> left), height(t-> right)) + 1;

}

template <typename datatype>
void AVL<datatype>::left_rot(AVLNode *  & t){
	AVLNode * aux = t -> left;
	t -> left = aux -> right;
	aux -> right = t;

  if(t->left!=nullptr)
    t->left->parent = t;

  aux->parent = t->parent;
  t->parent = aux;

  if(aux->parent!=nullptr){

    if(aux->parent->left == t)
      aux->parent->left = aux;

    else
      aux->parent->right = aux;
  }

	t -> bf= max(height(t -> left),height(t->right));
	aux -> bf = max(height(aux -> left), t -> bf) + 1;
	t = aux;
}

template <typename datatype>
void AVL<datatype>::right_rot(AVLNode *  & t){
	AVLNode * aux = t -> right;
	t -> right = aux -> left;
	aux -> left = t;

  if(t->right != nullptr)
    t->right->parent = t;

  aux->parent = t->parent;
  t->parent = aux;

  if(aux->parent!=nullptr){

    if(aux->parent->left == t)
      aux->parent->left = aux;

    else
      aux->parent->right = aux;
  }

	t -> bf = max(height(t -> right),height(t->left));
	aux -> bf = max(height(aux -> right), t -> bf) + 1;
	t = aux;
}

template <typename datatype>
void AVL<datatype>::leftR_rightR(AVLNode *  & t){
	left_rot(t->right);
	right_rot(t);
}

template <typename datatype>
void AVL<datatype>::rightR_leftR(AVLNode *  & t){
	right_rot(t -> left);
	left_rot(t);
}
