#ifndef NODO_BINARIO_H
#define NODO_BINARIO_H

template <typename T> class ArbolBin;
template <typename T>
class NodoBin{
  friend class ArbolBin<T>;
private:
  T dato;
  NodoBin* izq;
  NodoBin* der;
  void insert(const T&, NodoBin*&);
  void pop(const T&, NodoBin*, NodoBin*);
  void pop(const T&, NodoBin*&);
  void inOrden(const NodoBin* const) const;
  void inOrden(Queue<T>&, const NodoBin* const);
  void preOrden(const NodoBin* const) const;
  void preOrden(Queue<T>&, const NodoBin* const);
  void posOrden(const NodoBin* const) const;
  void posOrden(Queue<T>&, const NodoBin* const);
  void nivelOrden(const NodoBin* const);
  void nivelOrden(Queue<T>&, const NodoBin* const);
  void eraseNode(NodoBin*, NodoBin*);
  bool leaf() const;
  bool find(const T&, const NodoBin* const) const;
protected:
public:
  NodoBin(const T&, NodoBin* const = NULL, NodoBin* const = NULL);
  ~NodoBin();
};

#include "nodoBinario.hpp"

#endif //NODO_BINARIO_H