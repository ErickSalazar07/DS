#ifndef NODO_AVL_H
#define NODO_AVL_H
#include <vector>
#include <cstdlib>

template <class T> class ArbolAVL;
template <class T>
class NodoAVL{
  friend class ArbolAVL<T>;
private:
  T data;
  NodoAVL* izq;
  NodoAVL* der;
  void insert(const T&, NodoAVL*&, NodoAVL* const);
  void pop(const T&, NodoAVL*, NodoAVL*);
  void eraseNode(NodoAVL*, NodoAVL*);
  void inOrden(const NodoAVL* const); // Recorridos
  void inOrden(const std::vector<T>&, const NodoAVL* const);
  void preOrden(const NodoAVL* const);
  void preOrden(const std::vector<T>&, const NodoAVL* const);
  void posOrden(const NodoAVL* const);
  void posOrden(const std::vector<T>&, const NodoAVL* const);
  void nivelOrden(const NodoAVL* const);
  void nivelOrden(const std::vector<T>&, const NodoAVL* const);
  int heigth() const; // is the heigth of some node in the tree
  int heigth(const NodoAVL* const) const;
  bool leaf() const;
  bool leaf(const NodoAVL* const) const;
  bool find(const T&, const NodoAVL* const) const;
  int max(const int&, const int&) const; // Maximo entre dos valores numericos
  void balance(NodoAVL* , NodoAVL*);
  NodoAVL* leftRot(NodoAVL*);
  NodoAVL* rightRot(NodoAVL*);
  NodoAVL* leftRightRot(NodoAVL*);
  NodoAVL* rightLeftRot(NodoAVL*);
protected:
public:
  NodoAVL(const T&, NodoAVL* = NULL, NodoAVL* = NULL);
  ~NodoAVL();
};

#include "nodoAvl.hpp"

#endif // NODO_AVL_H