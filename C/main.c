#include <stdio.h>
#include "Stack/stack.h"

int main(){
  struct Stack pila;

  init(&pila);
  
  for(int i = 1; i <= 10; i++){
    printf("%i\n",i);
    push(&pila,i);
  }

  printf("\t\t\tSE VA A DESEMPILAR\n\n");

  while(!empty(pila)){
    printf("TOP -> %i\n",pila.cima->data);
    pop(&pila);
  }

  return 0;
}
