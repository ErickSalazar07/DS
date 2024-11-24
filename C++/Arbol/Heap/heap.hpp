#pragma once
#include"heap.h"
#include<iostream>
#include<deque>
#include<algorithm>

template<class T>
Heap<T>::Heap(){
    vec.clear();
}

template<class T>
Heap<T>::~Heap(){
    vec.clear();
}

template<class T>
void Heap<T>::insert(const T& dato){
    vec.push_back(dato);
    std::push_heap(vec.begin(),vec.end());
}

template<class T>
void Heap<T>::erase(const T& dato){
    std::pop_heap(vec.begin(),vec.end());
    vec.pop_back();
}

template<class T>
void Heap<T>::inOrder(){
    if(vec.empty()) return;

    inOrder(vec,0);
}

template<class T>
void Heap<T>::inOrder(const std::deque<T>& heap, int index){
    int n = heap.size();

    if(index >= n) return;

    inOrder(heap,2*index+1);

    std::cout<<heap[index]<<' ';

    inOrder(heap,2*index+2);
}