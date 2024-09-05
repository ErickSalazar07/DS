#ifndef STACK_H
#define STACK_H

struct Node{
  Node* next;
  int data;
};

struct Stack{
  Node* cima; 
};

#endif // STACK_H
