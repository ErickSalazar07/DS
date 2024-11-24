#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

struct Node{
  struct Node* next;
  int data;
};

struct Stack{
  struct Node* cima; 
  int numItems;
};

void init(struct Stack*);
bool empty(struct Stack);
void pop(struct Stack*);
void push(struct Stack*,int);

#endif // STACK_H
