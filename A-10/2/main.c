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

int front = 0;
int rear = 0;

node *queue[MAX_QUEUE_SIZE];

void deleteQueue();
void addNode(char data);
void addQueue(char data);

void Input();

int main(void) { Input(); }


void deleteQueue(){
  if(front == rear){
    printf("Queue is empty");
    return;
  }
  front++;
}


void addNode(char data) {

  node *newNode = (node *)malloc(sizeof(node));
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->data = data;

  while(1){ // queue에 char 데이터만 따로 저장하려고 했는데 되지 않는다.. 왜지?
    if (rear == 0) {
      addQueue(data);
      break;
    }
  
    if (queue[front]->left == NULL) {
      queue[front]->left = newNode;
      addQueue(data);
      break;
    }
  
    if (queue[front]->right == NULL) {
      queue[front]->right = newNode;
      addQueue(data);
      break;
    }

    deleteQueue();
    
  }
}

void addQueue(char data) {
  if (rear == MAX_QUEUE_SIZE) {
    printf("queue is full\n");
    return;
  }
  queue[rear++]->data = data;
}
void Input() {
  FILE *f;

  f = fopen("A-10/2/input.txt", "r");

  if (f == NULL) {
    printf("file does not open\n");
    exit(1);
  }

  char k;

  while (!feof(f)) {
    fscanf(f, "%c", &k);
    //printf("%c",k);
    addNode(k);
    break;
  }

  printf("%c",queue[front]->data);
}