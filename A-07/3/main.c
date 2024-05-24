#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    char name[50];
    char university[50];
    char sex[50];
    node *next;
};

node * head = NULL;

void printWomanNode();
void printManNode();
void printAllNode();
void insertNode(node element);
void Input();

int main(void){
    Input();
}

void printWomanNode(){
    node *currentNode;

    printf("\n여자 리스트\n");
    
    currentNode = head;

    while(currentNode != NULL){
        if(!strcmp(currentNode->sex,"여자")){
            printf("(%p, %s, %s, %s %p)  ",&currentNode,currentNode->name,currentNode->university,currentNode->sex,&currentNode->next);
        }
        currentNode = currentNode->next;
    }

    printf("\n");
}

void printManNode(){
    node *currentNode;

    printf("\n남자 리스트\n");

    currentNode = head;

    while(currentNode != NULL){
        if(!strcmp(currentNode->sex,"남자")){
            printf("(%p, %s, %s, %s %p)  ",&currentNode,currentNode->name,currentNode->university,currentNode->sex,&currentNode->next);
        }
        currentNode = currentNode->next;
    }

    printf("\n");
}

void printAllNode(){

    printf("\n전체 리스트\n");
    node * currentNode;

    currentNode = head;
    
    while(currentNode != NULL){
        printf("(%p, %s, %s, %s %p)  ",&currentNode,currentNode->name,currentNode->university,currentNode->sex,&currentNode->next);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void insertNode(node element){
    node * Node = (node *)malloc(sizeof(node));
    node * currentNode;

    strcpy(Node->name,element.name); // Node->name = element.name x , strcpy()로 옮기기
    strcpy(Node->university,element.university);
    strcpy(Node->sex,element.sex);
    Node->next = NULL;

    if(head == NULL){ //linked list 형성 x
        head = Node;
        return;
    }

    currentNode = head;

    while(currentNode->next != NULL){
        currentNode = currentNode->next;
    }

    currentNode->next = Node;
}

void Input(){
    FILE *f;

    f = fopen("A-07/3/input.txt","r");

    if(f == NULL){
        printf("file does not open\n");
        exit(1);
    }



    while(!feof(f)){
        node element;
        fscanf(f,"%s %s %s", &element.name,&element.university,&element.sex);
        insertNode(element);
    }

    printAllNode();
    printManNode();
    printWomanNode();
}