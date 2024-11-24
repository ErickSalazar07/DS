#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>
#include <queue>
#include "graph.h"

template <typename T>
Graph<T>::Graph(const int& numItems): matrix(numItems, 0.0F), nodes(numItems, T()){ }

template <typename T>
Graph<T>::Graph(const Graph<T>&){ }

template <typename T>
void Graph<T>::addEdge(const T& beg, const T& end, const float& w){
  if(nodes.empty()){ std::cerr<<"\a\nNo hay nodos en el grafo.\n\n"; return;}
  matrix[getIndex(beg)][getIndex(end)] = w;
}

template <typename T>
void Graph<T>::addNode(const T& data, const int& index){
  nodes[index] = data;
}

template <typename T>
void Graph<T>::BFS(const T& beg){
  int index = this->getIndex(beg);
  std::vector<bool> visited;
  std::queue<int> cola;
  
  cola.push(index);
  
  while(!cola.empty()){
    index = cola.front();
    if(!visited[index]){
      std::cout<<nodes[index]<<' ';
      visited[index] = true;
      for(int i = 0; i < matrix[index].size(); i++)
        if(matrix[index][i] && !visited[i]) cola.push(i);
    }
    cola.pop();
  }
}

template <typename T>
void Graph<T>::DFS(const T& beg){

}

template <typename T>
void Graph<T>::DFSAux(const int& beg, std::vector<bool>& visited){

  for(int i = 0; i < matrix[beg].size(); i++)
    if(matrix[beg][i] && !visited[i]){
      std::cout<<nodes[beg]<<' ';
      visited[beg] = true;
      this->DFSAux(i, visited);
    }
}

template <typename T>
int Graph<T>::getIndex(const T& value){
  for(int i = 0; i < nodes.size(); i++) if(nodes[i] == value) return i;
  return -1;
}

#endif // GRAPH_HPP