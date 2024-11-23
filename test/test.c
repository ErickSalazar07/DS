#include <stdio.h>
#include "../C/List/ListSim.h"

int main(int argc, char** argv) {

  struct ListSim lista;

  initListSim(&lista);
  push(&lista,10);
  push(&lista,3);
  push(&lista,-2);

  showItems(&lista);
  clear(&lista);

  printf("numNodes: %u\n",getNumNodes(&lista));
  clear(&lista);
  
  return 0;
}