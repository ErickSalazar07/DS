#ifndef ARB_GEN_H
#define ARB_GEN_H

#include"nodoGeneral.h"

template<class T>
class ArbolGeneral{
    NodoGeneral<T>* raiz;
public:
    ArbolGeneral();
    ArbolGeneral(const T& val);
    ~ArbolGeneral();
    bool esVacio();
    NodoGeneral<T>* obtenerRaiz();
    void fijarRaiz(NodoGeneral<T>* nraiz);
    bool insertarNodo(T& padre,T& n);
    bool eliminarNodo(T& n)
    bool buscar(T& n);
    int altura();
    int altura(NodoGeneral<T>*);
    unsigned int tamano();
    void preOrden();
    void preOrden(NodoGeneral<T>*);
    void posOrden();
    void posOrden(NodoGeneral<T>*);
    void nivelOrden();
};

#include"arbolGeneral.hpp"
#endif