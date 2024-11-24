#include <stdlib.h>
#include "stack.h"


void init(struct Stack* pila){
  if(pila->cima){
    pila->cima = 0;
    pila->numItems = 0;
  }
}

bool empty(struct Stack pila){
  if(!pila.cima) return true;
  return false;
}

void pop(struct Stack* pila){
  if(!pila->cima) return;

  struct Node* aux = pila->cima;
  pila->cima = pila->cima->next;
  free((void*)aux);
  pila->numItems--;
}

void push(struct Stack* pila, int newData){
  struct Node* aux = malloc(sizeof(struct Node));
  aux->data = newData;
  aux->next = pila->cima;
  pila->cima = aux;
  pila->numItems++;
}
