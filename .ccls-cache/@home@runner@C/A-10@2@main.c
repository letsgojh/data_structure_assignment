/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100

typedef struct node node;
struct node {
  node *left;
  node *right;
  char data;
};

node *root = NULL;
int front = 0;
int rear = 0;

node *queue[MAX_QUEUE_SIZE];

void inOrder(node **root);
void preOrder(node **root);
void postOrder(node **root);
void addNode(node **root, char data);

void Input();

int main(void) { Input(); }

void inOrder(node **root) {

  node *currentNode = *root;

  if (currentNode->left != NULL)
    inOrder(&currentNode->left);

  printf("%c ", currentNode->data);

  if (currentNode->right != NULL)
    inOrder(&currentNode->right);
}
void preOrder(node **root) {
  node *currentNode = *root;

  printf("%c ", currentNode->data);

  if (currentNode->left != NULL)
    preOrder(&currentNode->left);

  if (currentNode->right != NULL)
    preOrder(&currentNode->right);
}
void postOrder(node **root) {
  node *currentNode = *root;

  if (currentNode->left != NULL)
    preOrder(&currentNode->left);

  if (currentNode->right != NULL)
    preOrder(&currentNode->right);

  printf("%c ", currentNode->data);
}

void addNode(node **root, char data) {

  node *newNode = (node *)malloc(sizeof(node));
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->data = data;

  if (rear == 0) {
    queue[rear++] = newNode;
    *root = newNode;
    return;
  }

  while (
      1) { // queue에 char 데이터만 따로 저장하려고 했는데 되지 않는다.. 왜지?

    if (queue[front]->left == NULL) {
      queue[front]->left = newNode;
      queue[rear++] = newNode;
      // printf("case1\n");
      break;
    }

    else if (queue[front]->right == NULL) {
      queue[front]->right = newNode;
      queue[rear++] = newNode;
      // printf("case2\n");
      break;
    }

    front++;
  }
}

void Input() {
  FILE *f;

  f = fopen("A-10/2/input.txt", "r");

  if (f == NULL) {
    printf("file does not open\n");
    exit(1);
  }

  char k;
  node *root = NULL;

  while (1) {
    k = fgetc(f);
    if (k == EOF) //문자 한개 받을때는 이런식으로 받기 , NULL값까지 받으니깐
                  //트리 이상하게 만들어진다.
      break;
    // printf("%c",k);
    addNode(&root, k);
  }

  printf("creating a complete binary tree\n\n");
  printf("three binary tree traversals\n");
  printf("inorder traversal       : ");
  inOrder(&root);
  printf("\npreorder traversal      : ");
  preOrder(&root);
  printf("\npostorder traversal     : ");
  postOrder(&root);
}*/