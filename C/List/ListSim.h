#ifndef LIST_SIM_H
#define LIST_SIM_H
#include <stdbool.h>

/**
  * @author Erick Salazar Suarez
  * @brief Declaration of simple linked list, the necessary node, and some operations to make on it
*/

struct Node1D { // 1 degree node, it means points to 1 of its own type
  int data; // data to store
  struct Node1D* next; // next node to point
};

struct ListSim { // simple linked list
  struct Node1D* begin; // begin node to make operations in the list
  unsigned int numNodes; // number of nodes
};

void initListSim(struct ListSim*);
void pushFront(struct ListSim*, int);
void pushBack(struct ListSim*, int);
void popFront(struct ListSim*);
void popBack(struct ListSim*);
void removeN(struct ListSim*, unsigned int);
void clear(struct ListSim*);
unsigned int getNumNodes(struct ListSim*);
bool empty(struct ListSim*);
bool emptyN(struct Node1D*);
bool find(struct ListSim*, int);
void showItems(struct ListSim*);

#endif // LIST_SIM_H
