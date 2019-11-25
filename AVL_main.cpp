#include "AVL.hpp"

int main(){
  AVL<int> tree;
  tree.insert(6);
  tree.display();
  tree.insert(5);
  tree.display();
  tree.insert(4);
  tree.display();
  tree.insert(3);
  tree.display();
  tree.insert(2);
  tree.display();
  tree.insert(1);
  tree.display();
  // tree.insert(5);
  // tree.display();
  // tree.insert(2);
  // tree.display();
  // tree.insert(10);
  // tree.display();
  // tree.insert(4);
  // tree.display();
  // tree.insert(1);
  // tree.display();
  // tree.insert(3);
  // tree.display();
  // tree.insert(7);
  // tree.display();
  // tree.insert(13);
  // tree.display();
  // tree.insert(14);
  // tree.display();
  // tree.insert(15);
  // tree.display();
  // tree.insert(16);
  // tree.display();
  // cout <<"El tamaño es: " <<tree.size() << endl;
  // cout << "------------------" << endl;
  // tree.remove(13);
  //
  // tree.display();
  // tree.insert(0);
  // cout <<"El tamaño es: " <<tree.size() << endl;
  // tree.display();
  // tree.remove(4);
  // tree.insert(4);
  tree.remove(3);
  tree.display();
  tree.insert(0);
  tree.display();
  tree.insert(7);
  tree.display();
  tree.insert(8);
  tree.display();

  return 0;
}
