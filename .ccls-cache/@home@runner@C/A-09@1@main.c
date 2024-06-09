#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list list;
struct list {
  char fruit[10];
  char country[10];
  int price;
  list *left;
  list *right;
};

list *head = NULL;
list *tail = NULL;


void searchNode();
void printForward();
void printBackward();
void add(list data);
void Input();

int main(void) { 
  Input(); 
}

void searchNode(){
  printf("\n\n\n나라 이름을 입력하세요\n");

  char search[10];

  scanf("%s",search);

  list * currentNode = head;

  while(currentNode != NULL){
    if(!strcmp(currentNode->country,search)){
      printf("%s, ",currentNode->fruit);
    }
    currentNode = currentNode->right;
  }
  printf("\n\n");

}
void printForward(){
  list * currentNode = head;

  printf("순방향 출력\n");
  printf("The ordered list contains:\n");
  
  while(currentNode!= NULL){
    printf("%p(%s, %s, %d, %p) =>",currentNode,currentNode->fruit,currentNode->country,currentNode->price,currentNode->right);

    currentNode = currentNode->right;
  }
}
void printBackward(){
  list * currentNode = tail;

  printf("역방향 출력\n");
  printf("The ordered list contains:\n");

  while(currentNode!= NULL){
    printf("%p(%s, %s, %d, %p) =>",currentNode,currentNode->fruit,currentNode->country,currentNode->price,currentNode->left);

    currentNode = currentNode->left;
  }
}
void add(list data) {
  list *newNode = (list *)malloc(sizeof(list));

  strcpy(newNode->fruit,data.fruit);
  strcpy(newNode->country,data.country);
  newNode->price = data.price;
  newNode->left = NULL;
  newNode->right = NULL;

  if(head == NULL){
    head = newNode;
    tail = newNode;
    return;
  }

  newNode->right = head;
  head->left = newNode;
  head = newNode;
}

void Input() {
  FILE *f;

  f = fopen("A-09/1/input.txt", "r");

  if (f == NULL) {
    printf("file does not open");
    exit(1);
  }

  while (!feof(f)) {
    list data;
    fscanf(f, "%s %s %d", data.fruit, data.country, &data.price);

    add(data);
  }

  printForward();
  searchNode();
  printBackward();
}