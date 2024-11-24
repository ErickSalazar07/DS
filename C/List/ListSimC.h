#ifndef LIST_SIM_C_H
#define LIST_SIM_C_H
#include <stdbool.h>

/**
  * @author Erick Salazar Suarez
  * @brief Declaration of simple linked list, the necessary node, and some operations to make on it
*/

struct Node1D { // 1 degree node, it means points to 1 of its own type
  int data; // data to store
  struct Node1D* next; // next node to point
};

struct ListSimC { // simple linked list
  struct Node1D* begin; // begin node to make operations in the list
  unsigned int numNodes; // number of nodes
};

void initListSim(struct ListSimC*);
void push(struct ListSimC*, int);
// void pop(struct ListSimC*);
// void remove(struct ListSimC*, unsigned int);
void clear(struct ListSimC*);
unsigned int getNumNodes(struct ListSimC*);
bool empty(struct Node1D*);
bool find(struct ListSimC*, int);
void showItems(struct ListSimC*);

#endif // LIST_SIM_C_H
