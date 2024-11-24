#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

template <typename T>
class Graph{

private:
  std::vector< std::vector<float> > matrix;
  std::vector<T> nodes;
protected:
  void DFSAux(const int&, std::vector<bool>&);
  void getIndex(const T&);
public:
  Graph(const int&);
  Graph(const Graph<T>&);
  ~Graph();
  void addEdge(const T&, const T&, const float& = 0.0F);
  void addNode(const T&);
  void DFS(const T&);
  void BFS(const T&);
};

#include "graph.hpp"
#endif // GRAPH_H
