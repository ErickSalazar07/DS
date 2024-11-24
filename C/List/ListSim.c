#include <stdio.h>
#include <stdlib.h>
#include "ListSim.h"

void initListSim(struct ListSim* lista) {
  lista->begin = NULL;
  lista->numNodes = 0;
}

void pushFront(struct ListSim* lista, int data) {
  struct Node1D* newNode = malloc(sizeof(struct Node1D));
  
  if(newNode == NULL) { perror("\n\nError alocating memory for node.\n\n"); exit(-1); }

  newNode->data = data;
  newNode->next = lista->begin;
  lista->begin = newNode;
  lista->numNodes++;
}

void pushBack(struct ListSim* lista, int data) {
  struct Node1D* newNode = malloc(sizeof(struct Node1D));

  if(newNode == NULL) { perror("\n\nError alocating memory for node.\n\n"); exit(-1); }
  newNode->data = data;
  newNode->next = NULL;

  if(empty(lista)) {
    lista->begin = newNode;
    lista->numNodes++;
    return;
  }

  struct Node1D* it;
  for(it = lista->begin; it->next != NULL; it = it->next);
  
  it->next = newNode;
  lista->numNodes++;
}

void popFront(struct ListSim* lista) {
  if(empty(lista)) { printf("\nCan not remove front of List. Is Empty\n"); return; }
  
  struct Node1D* auxRm = lista->begin;
  lista->begin = lista->begin->next;
  free((void*)auxRm);
  lista->numNodes--;
}

void popBack(struct ListSim* lista) {
  if(empty(lista)) { printf("\nCan not remove back of List. Is Empty\n"); return; }

  if(!lista->begin->next) {
    free((void*)lista->begin);
    lista->begin = NULL;
    lista->numNodes = 0;
    return;
  }

  struct Node1D* auxPrev, *auxRm;

  auxPrev = auxRm = lista->begin;
  while(auxRm->next != NULL) {
    auxPrev = auxRm;
    auxRm = auxRm->next;
  }

  free((void*)auxRm);
  auxPrev->next = NULL;
  lista->numNodes--;
}

bool empty(struct ListSim* lista) {
  return lista->begin == NULL;
}

bool emptyN(struct Node1D* node) {
  return node == NULL;
}

bool find(struct ListSim* lista, int data) {
  if(empty(lista)) return false;

  struct Node1D* it; // list iterator

  for(it = lista->begin; it; it = it->next)
    if(it->data == data) return true;
  return false;
}

void clear(struct ListSim* lista) {
  if(empty(lista)) { printf("\nList already clear\n"); return; }

  struct Node1D* auxRm;

  while(lista->begin) {
    auxRm = lista->begin;
    lista->begin = lista->begin->next;
    free((void*)auxRm);
  }
  lista->numNodes = 0;
}

void removeN(struct ListSim* lista, unsigned int index) {
  return;
}

void showItems(struct ListSim* lista) {
  if(empty(lista)) { printf("\n\nNo Items to display\n\n"); return; }

  struct Node1D* it = lista->begin; // list iterator 

  for(it = lista->begin; it; it = it->next) 
    printf("%i%c",it->data,(emptyN(it->next) ? '\n' : ','));
}

unsigned int getNumNodes(struct ListSim* lista) {
  if(empty(lista)) return 0;
  return lista->numNodes;
}