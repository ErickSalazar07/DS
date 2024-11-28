#ifndef AVL_NODE_H
#define AVL_NODE_H
#include <cstdlib>
#include "../Binario/nodoBinario.h"

template <typename T> class AVLTree;
template <typename T>
class AVLNode: public NodoBin<T> {
  friend class AVLTree<T>;
private:
protected:
public:
  AVLNode(const T& data): NodoBin<T>(data) {}
  T getDato() { return this->dato; }
};

#endif // AVL_NODE_H