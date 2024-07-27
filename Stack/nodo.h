/**
  * @author Erick Salazar Suarez
  * @date 18/jun/2024
  * @implements Linear node
  * @brief Basic linear node pointing for at most one node of its same data type. This is necessary for the implementations of data structures such as:
  * Stack, Queue or linked lists
  * @copyright All implementations of the basic operations of the linear node, are created and owned by the author of this header file 
*/

#ifndef NODO_H
#define NODO_H

template <typename T> class Stack;
template <typename T>
class Nodo{
  friend class Stack<T>;
private:
  T dato;
  Nodo<T>* sig;
protected:
public:
  Nodo(const T&, Nodo* const = NULL);
};

#include "nodo.hpp"

#endif // NODO_H