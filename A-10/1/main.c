/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;

struct node {
  node *left;
  node *right;
  int data;
};

void preorder(node **root);
void inorder(node **root);
void postorder(node **root);
void add(node **root, int data);
void Input();

int main(void) { Input(); }

void preorder(node **root) {

  node *currentNode = *root;

  printf("(%p : %p  %c  %p)\n", currentNode,currentNode->left,currentNode->data,currentNode->right);
  
  if(currentNode->left != NULL)
    preorder(&currentNode->left);
    
  if(currentNode->right != NULL)
    preorder(&currentNode->right);
}

void inorder(node **root) {

  node *currentNode = *root;

  if(currentNode->left != NULL)
    inorder(&currentNode->left);


  printf("(%8p : %8p  %c  %8p)\n", currentNode,currentNode->left,currentNode->data,currentNode->right);

  if(currentNode->right != NULL)
    inorder(&currentNode->right);
}

void postorder(node **root) {

  node *currentNode = *root;

  if(currentNode->left != NULL)
    postorder(&currentNode->left);

  if(currentNode->right != NULL)
    postorder(&currentNode->right);

  printf("(%p : %p  %c  %p)\n", currentNode,currentNode->left,currentNode->data,currentNode->right);

}

void add(node **root, int data) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  if (*root == NULL) {
    *root = newNode;
    return;
  }

  node *currentNode;

  currentNode = *root;

  while (1) {
    if (currentNode->left == NULL) {
      currentNode->left = newNode;
      break;
    }

    else if (currentNode->right == NULL) {
      currentNode->right = newNode;
      break;
    } 
    
    else {
      currentNode = currentNode->left;
    }
  }
}
void Input() {
  printf("creating a binary tree\n\n");

  printf("three binary tree traversals\n");

  node *root = NULL;

  for (int i = 65; i <= 69; i++) {
    add(&root, i);
  }

  
  printf("inorder traversal   :\n");
  inorder(&root);
  printf("\n\n");
  printf("preorder traversal   :\n");
  preorder(&root);
  printf("\n\n");
  printf("postorder traversal   :\n");
  postorder(&root);
}*/