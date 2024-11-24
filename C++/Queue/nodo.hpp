#ifndef NODO_HPP
#define NODO_HPP
#include "nodo.h"

template <typename T>
Nodo<T>::Nodo(const T& dato, Nodo* const nodo): dato(dato), sig(nodo){ }

#endif // NODO_HPP