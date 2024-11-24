/**
  * @author Erick Salazar Suarez
  * @date 2/06/2024
  * @implements Stack, linear data structure
  * @brief Implemetantion of data structure Stack, which provides basic data buffer with LIFO stream operations
  * @copyright All implementations of the Stack operations, are created and owned by the autor of this header file   
*/

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "nodo.h"

template <typename T>
class Stack{
private:
  size_t numItems;
  Nodo<T>* cima;
protected:
public:
  Stack();
  Stack(const T&);
  Stack(const Stack<T>&);
  ~Stack();
  T top() const;
  Stack& push(const T&);
  Stack& pop();
  Stack& clear();
  bool empty() const;
  size_t size() const;
  Stack<T>& operator = (const Stack<T>&);
  Stack<T>& operator += (const Stack<T>&);
  T operator [] (const size_t&);
};

#include "stack.hpp"
#endif // STACK_H