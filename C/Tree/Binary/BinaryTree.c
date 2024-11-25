#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

void initBinaryTree(struct BinaryTree* tree) {
  tree->root = NULL;
  tree->numNodes = 0;
}

void clear(struct BinaryTree* tree) {
  if(empty(tree)) { puts("\nThe tree, is already empty, nothing to clear.\n"); return; }
  clearN(&tree->root);
  tree->numNodes = 0;
}

void clearN(struct Node2D** node) {
  if(!*node) return;

  if((*node)->rigth)
    clearN(&(*node)->rigth);
    
  if((*node)->left)
    clearN(&(*node)->left);

  free((void*)*node);
  *node = NULL;
}

void insert(struct BinaryTree* tree, int data) {
  if(empty(tree)) {
    tree->root = malloc(sizeof(struct Node2D));
    if(!tree->root) { perror("\nError alocating memory, for tree->root.\n"); exit(-1); }
    tree->root->data = data;
    tree->root->left = tree->root->rigth = NULL;
  } else insertN(&tree->root, data);
  tree->numNodes++;
}

void insertN(struct Node2D** node, int data) {
  if(!*node) {
    *node = malloc(sizeof(struct Node2D));
    if(!*node) { perror("\nError alocating memory, for *node.\n"); exit(-1); }
    (*node)->data = data;
    (*node)->left = (*node)->rigth = NULL;
  } else if((*node)->data < data) insertN(&(*node)->rigth,data);
    else if((*node)->data > data) insertN(&(*node)->left,data);
}

void removeValue(struct BinaryTree* tree, int rmData) {
  return;
}

void removeN(struct Node2D** node, int rmData) {
  return;
}

bool find(struct BinaryTree* tree, int findData) {
  if(tree->root->data == findData) return true;

  return findN(tree->root,findData);
}

bool findN(struct Node2D* node, int findData) {
  if(!node) return false;

  if(node->data > findData) return findN(node->left,findData);
  else if(node->data < findData) return findN(node->rigth,findData);
  else return true;
}

bool empty(struct BinaryTree* tree) {
  return tree->root == NULL;
}

bool emptyN(struct Node2D* node) {
  return node == NULL;
}

unsigned int getNumNodes(struct BinaryTree* tree) {
  if(empty(tree)) return 0;
  return tree->numNodes;
}

int getRoot(struct BinaryTree* tree) {
  if(empty(tree)) { puts("\nError, no root, returning 0.\n"); return 0; }
  return tree->root->data;
}

int getHeigthBinTree(struct BinaryTree* tree) {
  return heigthN(tree->root);
}

int heigthN(struct Node2D* node) {
  if(!node) return -1;
  return 1 + max(heigthN(node->left),heigthN(node->rigth));
}

void inOrder(struct BinaryTree* tree) {
  if(empty(tree)) { puts("\nCan't do \"in order\" tour.\n"); return; }
  puts("\n\t\t\tIN ORDER TOUR\n");
  inOrderN(tree->root);
  puts("");
}

void inOrderN(struct Node2D* node) {
  if(!node) return;

  if(node->left) inOrderN(node->left);
  printf("%i ",node->data);
  if(node->rigth) inOrderN(node->rigth);
}

void preOrder(struct BinaryTree* tree) {
  if(empty(tree)) { puts("\nCan't do \"pre order\" tour.\n"); return; }
  puts("\n\t\t\tPRE ORDER TOUR\n");
  preOrderN(tree->root);
  puts("");
}

void preOrderN(struct Node2D* node) {
  if(!node) return;

  printf("%i ",node->data);
  if(node->left) preOrderN(node->left);
  if(node->rigth) preOrderN(node->rigth);
}

void posOrder(struct BinaryTree* tree) {
  if(empty(tree)) { puts("\nCan't do \"pos order\" tour.\n"); return; }
  puts("\n\t\t\tPOS ORDER TOUR\n");
  posOrderN(tree->root);
  puts("");
}

void posOrderN(struct Node2D* node) {
  if(!node) return;

  if(node->left) posOrderN(node->left);
  if(node->rigth) posOrderN(node->rigth);
  printf("%i ",node->data);
}

int max(int a, int b) {
  return a > b ? a : b;
}
