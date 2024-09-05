#pragma once
#include<deque>

template<class T>
class Heap{
    std::deque<T> vec;
    void inOrder(const std::deque<T>&,int);
public:
    Heap();
    ~Heap();
    void insert(const T&);
    void erase(const T&);
    void inOrder();
};

#include"heap.hpp"