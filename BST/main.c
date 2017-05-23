#include "bst.h"


Node * add(Node *node, int num) {

  if(node == NULL) {
    node = (Node*) malloc(sizeof(Node));
    node->value = num;
    node->left = NULL;
    node->right = NULL;
  }
  else if(num <= node->value) {
    node->left = add(node->left, num);
  }
  else {
    node->right = add(node->right, num);
  }
 
  return node;
}

void printInOrder(Node *node, const char* parentDir) {
  if(node != NULL) {
    printInOrder(node->left, "left");
    printf("ParentDir:(%s) %d\n",parentDir, node->value);
    printInOrder(node->right, "right");
  }
}

void freeTree(Node *node) {
  if(node != NULL) {
    free(node->left);
    free(node->right);
    free(node);
  }
}

int main(void) {
  Node *treeNode = add(NULL, 77);
  treeNode = add(treeNode, 56);
  treeNode = add(treeNode, 45);
  treeNode = add(treeNode, 45);
  treeNode = add(treeNode, 22);
  treeNode = add(treeNode, 88);
  printInOrder(treeNode, "root");
  freeTree(treeNode);
}
