#include "AVL.hpp"

int main(){
  AVL<int> tree;
  tree.insert(5);
  tree.insert(3);
  tree.insert(10);
  tree.insert(2);
  tree.insert(1);
  tree.insert(7);
  // tree.insert(8);
  // tree.insert(9);
  // tree.display();
  // tree.remove(5);
  tree.display();
  cout << boolalpha << tree.balanced() << endl;
  return 0;
}
