/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
  node *llink;
  int data;
  node *rlink;
};

node *header = NULL;

void deleteNode();
void printForward();
void printBackward();
void add(int data);
void Input();

int main(void) { Input(); }

void deleteNode() {

  node *currentNode;

  printf("After deleting numbers less than and equal to 50 :\n");

  currentNode = header->rlink;

  do { //처음 노드 삭제하는 경우
    if (currentNode->data <= 50) {
      node *delNode = currentNode;
      delNode->rlink->llink = header;
      header->rlink = delNode->rlink;
      currentNode = header->rlink;
      free(delNode);
    }
  } while (currentNode->data <= 50);

  node *delNode;

  while (currentNode != header) { //중간 노드 삭제하는 경우

    delNode = currentNode;

    if (delNode->data <= 50) {
      delNode->llink->rlink = delNode->rlink;
      delNode->rlink->llink = delNode->llink;
      currentNode = delNode->rlink;
      free(delNode);
      continue;
    }

    currentNode = currentNode->rlink;
  }
}

void printForward() {
  node *currentNode = header->rlink;

  printf("forward\n");

  while (currentNode != header) {
    printf("(%p    %d %p)\n", currentNode->llink, currentNode->data,
           currentNode->rlink);

    currentNode = currentNode->rlink;
  }
  printf("\n\n");
}

void printBackward() {
  node *currentNode = header->llink;

  printf("backward\n");

  while (currentNode != header) {
    printf("(%p    %d %p)\n", currentNode->llink, currentNode->data,
           currentNode->rlink);

    currentNode = currentNode->llink;
  }
  printf("\n\n");
}

void add(int data) {

  node *newNode = (node *)malloc(sizeof(node)); //메모리 할당 확인하기 까먹음;
  newNode->data = data;
  newNode->llink = NULL;
  newNode->rlink = NULL;

  if (header == NULL) {
    header = (node *)malloc(sizeof(node));
    header->llink = newNode;
    header->rlink = newNode;
    newNode->llink = header;
    newNode->rlink = header;
    return;
  }

  newNode->llink = header->llink;
  header->llink->rlink = newNode;
  newNode->rlink = header;
  header->llink = newNode;
}

void Input() {
  FILE *f;

  f = fopen("A-09/3/input.txt", "r");

  if (f == NULL) {
    printf("file does not open\n");
    exit(1);
  }

  while (!feof(f)) {
    int data;
    fscanf(f, "%d", &data);
    add(data);
  }

  printForward();
  printBackward();
  deleteNode();
  printForward();
  printBackward();
}*/