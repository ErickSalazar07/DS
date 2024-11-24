#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

struct Node {
  int data;
  struct Node* next;
};

struct Stack {
  struct Node* top; 
  unsigned int numNodes;
};

void initStack(struct Stack*);
bool empty(struct Stack*);
bool emptyN(struct Node*);
unsigned int getNumNodes(struct Stack*);
int getTop(struct Stack*);
void showItems(struct Stack*);
void clear(struct Stack*);
void pop(struct Stack*);
void push(struct Stack*,int);

#endif // STACK_H
