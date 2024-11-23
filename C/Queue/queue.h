#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

struct Node {
  int data;
  struct Node* next;
};

struct Queue {
  struct Node* front;
  struct Node* back;
  unsigned int numNodes;
};

// operations
void initQueue(struct Queue*);
void push(struct Queue*, int);
void pop(struct Queue*);
void showItems(struct Queue*);
void clear(struct Queue*);
bool empty(struct Queue*);
bool emptyN(struct Node*);
int getFront(struct Queue*);
int getBack(struct Queue*);
unsigned int getNumNodes(struct Queue*);

#endif // QUEUE_H
