#ifndef N_GEN_H
#define N_GEN_H
#include<vector>

template<class T>
class NodoGeneral{
    T dato;
    std::list< NodoGeneral<T>* > desc;
public:
    NodoGeneral();
    ~NodoGeneral();
    T& obtenerDato();
    void fijarDato(const T&);
    void limpiarLista();
    void adicionarDesc(const T&);
    void eliminarDesc(const T&);
    bool esHoja();
};

#include"nodoGeneral.hpp"
#endif