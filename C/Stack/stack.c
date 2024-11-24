#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(struct Stack* pila) {
  pila->top = NULL;
  pila->numNodes = 0;
}

bool empty(struct Stack* pila) {
  return pila->top == NULL;
}

bool emptyN(struct Node* node) {
  return node == NULL;
}

unsigned int getNumNodes(struct Stack* pila) {
  if(empty(pila)) return 0;
  return pila->numNodes;
}

int getTop(struct Stack* pila) {
  if(empty(pila)) { printf("\nNo Node in the top, returning 0.\n"); return 0; }
  return pila->top->data;
}

void showItems(struct Stack* pila) {
  if(empty(pila)) { printf("\nNo Items to display\n"); return; }

  struct Node* it; // stack iterator

  for(it = pila->top; it != NULL; it = it->next) 
    printf("%i%c",it->data,(emptyN(it->next) ? '\n' : ','));
  
}

void clear(struct Stack* pila) {
  while(!empty(pila))
    pop(pila);
  pila->top = NULL;
  pila->numNodes = 0;
}

void pop(struct Stack* pila) {
  if(empty(pila)) return;

  struct Node* aux = pila->top;
  pila->top = pila->top->next;
  free((void*)aux);
  pila->numNodes--;
}

void push(struct Stack* pila, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));

  if(newNode == NULL) { perror("\n\nError alocating memory for node\n\n"); exit(-1); }
  
  newNode->data = data;
  newNode->next = pila->top;
  pila->top = newNode;
  pila->numNodes++;
}
