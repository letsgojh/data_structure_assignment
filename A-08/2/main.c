/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode listNode;

struct listNode {
  int data;
  listNode *link;
};

listNode *first = NULL;

void printNode();
void addNode(int data);
void deleteNode();
void Input();

int main(void) { Input(); }

void printNode() {
  listNode *currentNode;

  currentNode = first->link;

  //do{ //circular linked list 를 출력할때는 do while문을 쓴 후, 마지막에 first
  //한번 더 출력 currentNode = currentNode->link; printf("(%4p, %4d,
  //%4p)",currentNode,currentNode->data,currentNode->link); }while(currentNode!=
  //first);
  //printf("(%5p, %5d, %5p)",currentNode,currentNode->data,currentNode->link);

  printf("The Circularly Linked List contatins:\n");
  while (currentNode != first) {
    printf("(%4p, %4d, %4p)", currentNode, currentNode->data,
           currentNode->link);
    currentNode = currentNode->link;
  }
  printf("(%4p, %4d, %4p)", currentNode, currentNode->data, currentNode->link);
}

void addNode(int data) {
  listNode *newNode = (listNode *)malloc(sizeof(listNode));

  newNode->data = data;
  newNode->link = NULL;

  if (first == NULL) {
    first = newNode;
    newNode->link = first;
    return;
  }

  newNode->link = first->link;
  first->link = newNode;
  first = newNode;
}

void deleteNode() {

  if (first == NULL) {
    printf("No Node");
    return;
  }

  listNode *delNode;
  listNode *flowNode;
  listNode *currentNode;


  first = first->link;
  
  while ((first->data) % 2 == 1) {
    if (first->link == first) { //만약 노드가 하나인데 홀수 인경우
      free(first);
      first = NULL;
      return;
    }

    listNode *lastNode = first;

    while (lastNode->link != first) { // first->data 가 홀수라면 마지막 노드와
      lastNode = lastNode->link;  // first를 다시 연결해야함
    }
    
    delNode = first;
    first = first->link;
    lastNode->link = first;
    free(delNode);
  }


  
  currentNode = first->link;

  while (currentNode->link != first) { // first가 아닌 다른 노드에 홀수가 있는경우
    if ((currentNode->link->data) % 2 == 1) { // previousNode 쓰지 않고 currentNode->link->data로 쓴다
      delNode = currentNode->link;
      currentNode->link = delNode->link; // del노드는 삭제 할 노드, 그 전과 후만 연결
      free(delNode);
    } else {
      currentNode = currentNode->link;
    }
  }

  first = currentNode;
  
}

void Input() {
  FILE *f;

  f = fopen("A-08/2/input.txt", "r");

  if (f == NULL) {
    printf("file does not open\n");
    exit(1);
  }

  while (!feof(f)) {
    int data;
    fscanf(f, "%d", &data);
    addNode(data);
    //printf("%d\n",data);
  }

  printNode();
  deleteNode();
  printf("\n\nAfter deleting nodes with odd value\n\n");
  printNode();

}*/