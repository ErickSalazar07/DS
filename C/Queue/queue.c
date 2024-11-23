#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(struct Queue* cola) {
  cola->numNodes = 0;
  cola->back = cola->front = NULL;
}

void push(struct Queue* cola, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;


  if(emptyN(cola->front)) {
    cola->back = cola->front = newNode;
    return;
  }

  cola->back->next = newNode;
  cola->back = newNode;
  cola->numNodes++;
}

void pop(struct Queue* cola) {
  if(empty(cola)) return;

  struct Node* auxRm = cola->front;
  cola->front = cola->front->next;
  free(auxRm);
  cola->numNodes--;
}

void showItems(struct Queue* cola) {
  if(empty(cola)) { printf("\nNo Items to display\n"); return; }
  
  struct Node* it;

  printf("\n\nDisplaying items.\nThe path starts in the front node, so we see at first, the firsts nodes entered.\n\n");
  for(it = cola->front; it; it = it->next) 
    printf("%i%c",it->data,(emptyN(it->next) ? '\n' : ','));
}

void clear(struct Queue* cola) {
  if(empty(cola)) { printf("\nQueue already clear\n"); return; }

  while(!empty(cola))
    pop(cola);
  if(cola->front) cola->front = NULL;
  if(cola->back) cola->back = NULL;
  cola->numNodes = 0;
}

bool empty(struct Queue* cola) {
  return cola->front == NULL;
}

bool emptyN(struct Node* nodo) {
  return nodo == NULL;
}

int getFront(struct Queue* cola) {
  if(empty(cola)) { printf("\nEmpty queue returning 0\n"); return 0; }
  return cola->front->data;
}

int getBack(struct Queue* cola) {
  if(empty(cola)) { printf("\nEmpty queue returning 0\n"); return 0; }
  return cola->back->data;
}

unsigned int getNumNodes(struct Queue* cola) {
  return cola->numNodes;
}
