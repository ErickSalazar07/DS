#ifndef QUEUE_H
#define QUEUE_H
#include "nodo.h"

template <typename T>
class Queue{
private:
  size_t numItems;
  Nodo<T>* frt;
  Nodo<T>* bck;
protected:
public:
  Queue();
  Queue(const Queue<T>&);
  Queue(const T&);
  ~Queue();
  T front(); //primer elemento en la cola es decir el primero que entro que no ha sido eliminado
  T back(); // ultimo elemento agregado a la cola
  void clear();
  void pop();
  void push(const T&);
  inline size_t size() const;
  inline bool empty() const;
  Queue<T>& operator = (const Queue<T>&);
};

#include "queue.hpp"
#endif // QUEUE_H