#include <stdio.h>
#include <stdlib.h>
#include "ListSim.h"

void initListSim(struct ListSim* lista) {
  lista->begin = NULL;
  lista->numNodes = 0;
}

void push(struct ListSim* lista, int data) {

  if(empty(lista->begin)) {
    lista->begin = malloc(sizeof(struct Node1D));
    lista->begin->data = data;
    return;
  }

  struct Node1D* newNode = malloc(sizeof(struct Node1D));  
  struct Node1D* it; // iterator list
  newNode->data = data;

  for(it = lista->begin; it->next; it = it->next);

  newNode->next = it->next;
  it->next = newNode;
  lista->numNodes++;
}

/*void pop(struct ListSim* lista) {

}*/

bool empty(struct Node1D* node) {
  return node == NULL;
}

bool find(struct ListSim* lista, int data) {
  if(empty(lista->begin)) return false;

  struct Node1D* it; // list iterator

  for(it = lista->begin; it; it = it->next)
    if(it->data == data) return true;
  return false;
}

void clear(struct ListSim* lista) {
  if(empty(lista->begin)) { printf("\nList already clear\n"); return; }

  struct Node1D* auxRm;

  while(lista->begin) {
    auxRm = lista->begin;
    lista->begin = lista->begin->next;
    free(auxRm);
  }
  lista->numNodes = 0;
}

void showItems(struct ListSim* lista) {
  if(empty(lista->begin)) { printf("\n\nNo Items to display\n\n"); return; }

  struct Node1D* it = lista->begin; // list iterator 

  for(it = lista->begin; it; it = it->next) 
    printf("%i%c",it->data,(empty(it->next) ? '\n' : ','));
  
}

unsigned int getNumNodes(struct ListSim* lista) {
  if(empty(lista->begin)) return 0;
  return lista->numNodes;
}