#ifndef __AVLNode__
#define __AVLNode__
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
template <typename datatype>
class AVL{
private:
  /*

		*Struct de los nodos del árbol

		*key: Valor que tiene cada nodo

		*left: Puntero al hijo izquierdo del nodo

		*right: Puntero al hijo derecho del nodo

		*parent: Puntero al padre del nodo

    *bf: Factor de balanceo, este nos permite ver
         si el nodo está balanceado

		*/
  struct AVLNode {
    datatype key;
    AVLNode *left;
    AVLNode *right;
    AVLNode *parent;
    int bf;
  };

  // Raíz del árbol
  AVLNode *root;

  // Tamaño del árbol
  size_t count;

  // Inserta el nodo t, con llave x, cuyo padre va a ser parent
  void insert(AVLNode*&t, datatype x, AVLNode*parent);

  // Remueve el nodo x desde t (raíz)
  void remove(AVLNode*&t, datatype x);

  // Borra el nodo y sus descendientes recursivamente
  void destroyRecursive(AVLNode *t);

  // Imprime el arbol para la comodidad del usuario
  void display(AVLNode *t, int count, vector<string> &s);

  // De existir, retorna el nodo con llave k
  AVLNode* findNode(AVLNode *t, datatype k) const;

  // Retorna el menor nodo
  AVLNode* minimum(AVLNode *t);

  // Retorna el mayor nodo
  AVLNode* maximum(AVLNode *t);

  // Retorna el nodo con la mayor clave menor que t
  AVLNode* predecessor(AVLNode* t);

  // Retorna el nodo con la menor clave mayor que t
  AVLNode* successor(AVLNode* t);

  // Retorna la altura del nodo t
  int height(AVLNode *t);

public:
  // Constructor
  AVL();

  // Destructor
  ~AVL();

  // Remueve todos los elementos del árbol
  void clear();

  // Crea un nodo con la llave x de forma organizada
  void insert(datatype x);

  // Remueve el nodo con llave x
  void remove(datatype x);

  // Imprime el arbol para la comodidad del usuario
  void display();

  // Verifica si existe un nodo con llave k en el árbol
  bool find(datatype k) const;

  // Retorna el valor del menor nodo
  datatype minimo();

  // Retorna el valor del mayor nodo
  datatype maximo();

  // Balancea el árbol
  void balance(AVLNode * & t);

  // Realiza una rotación hacia la izquierda
  void left_rot(AVLNode * & t);

  // Realiza una rotación hacia la derecha
  void right_rot(AVLNode * & t);

  /* Realiza una rotación hacia la izquierda sobre node->right y luego
  realiza una rotacion a la derecha sobre node*/
  void leftR_rightR(AVLNode * & t);

  /* Realiza una rotación hacia la derecha sobre node->left y luego
  realiza una rotacion a la izquierda sobre node*/
  void rightR_leftR(AVLNode * & t);

  // Retorna la cantidad de nodos en el árbol
  size_t size();

  // Verifica si el árbol está vacío
  bool empty();

};

#include "AVL.cpp"
#endif //__AVLNode__

// La manera del display fue obtenida del Profesor Carlos.
