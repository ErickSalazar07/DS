#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <stdbool.h>

struct Node2D {
  int data;
  struct Node2D* left;
  struct Node2D* rigth;
};

struct BinaryTree {
  struct Node2D* root;
  unsigned int numNodes;
};

void initBinaryTree(struct BinaryTree*);
void clear(struct BinaryTree*);
void clearN(struct Node2D**);
void insert(struct BinaryTree*, int);
void insertN(struct Node2D**, int);
void removeValue(struct BinaryTree*, int);
void removeN(struct Node2D**, int);
bool find(struct BinaryTree*, int);
bool findN(struct Node2D*, int);
unsigned int getNumNodes(struct BinaryTree*);
int getRoot(struct BinaryTree*);
int getHeigthBinTree(struct BinaryTree*);
int heigthN(struct Node2D*);
bool empty(struct BinaryTree*);
bool emptyN(struct Node2D*);
void inOrder(struct BinaryTree*);
void posOrder(struct BinaryTree*);
void preOrder(struct BinaryTree*);
void inOrderN(struct Node2D*);
void posOrderN(struct Node2D*);
void preOrderN(struct Node2D*);
int max(int, int);

#endif // BINARY_TREE_H