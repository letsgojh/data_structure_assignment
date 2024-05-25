/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct listNode{
    int data;
    struct listNode* link;
}listNode;



listNode* first = NULL;

void removeNode();
void deleteNode();
void insertNode(int data);
void printNode();
void Input();


int main(void){
    Input();
}


void removeNode(){
    listNode* delNode;

    delNode = first;

    while(first != NULL){
        first = first->link;
        free(delNode);
        delNode = first;
    }
}

void deleteNode(){
    listNode* delNode;
    listNode *previousNode;

    if(first == NULL){ //linkedlist 형성 안되어있을 경우
        printf("not linkedlist\n");
        return;
    }

    listNode * traversalNode = first;

    while(traversalNode->link != NULL){

        if((first->data)%2 == 1){ //첫노드가 홀수일경우
            delNode = first;
            first = first->link;
            traversalNode = traversalNode->link;
            free(delNode);
            continue;
        }

        delNode = traversalNode;
        previousNode = traversalNode;

        while(delNode->link != NULL){ //중간 노드가 홀수일경우
            delNode = delNode->link;

            if((delNode->data)%2 == 1){
                previousNode->link = delNode->link;
                free(delNode);
                break;

            }
            previousNode = previousNode->link;
        }
        traversalNode = traversalNode->link;
    }
}

void insertNode(int data){

    listNode* newNode = (listNode*)malloc(sizeof(listNode));

    newNode->data = data; //받으면 먼저 초기화
    newNode->link = NULL;

    if(first == NULL){
        first = newNode; //연결리스트 형성x했을때
        return;
    }

    if(first->data > newNode->data){ // first노드의 data보다 값 작을경우
        newNode->link = first;
        first = newNode;
        return;
    }

    listNode* currentNode;
    listNode* previousNode;

    currentNode = previousNode = first; 
    //currentNode는 가장 마지막 노드 찾는 포인터, previousNode는 그 전 노드 찾는 포인터

    while(currentNode->link != NULL){
        currentNode = currentNode->link; //previous 포인터 때문에 미리 한번 이동

        if(newNode->data < currentNode->data){
            newNode->link = currentNode;
            previousNode->link = newNode;
            return;
        }

        previousNode = previousNode->link;
    }

    currentNode->link = newNode; //끝에 추가하는 경우
}


void printNode(){
    listNode* currentNode;

    currentNode = first;

    printf("The ordered list contatins:\n");

    while(currentNode != NULL){
        printf("(%9p, %9d, %9p)",currentNode,currentNode->data,currentNode->link);
        currentNode = currentNode->link;
    }
}


void Input(){
    FILE * f;

    f = fopen("A-07/2/input.txt","r");

    if(f == NULL){
        printf("file does not open\n");
        exit(1);
    }

    int data = 0;


    while(!feof(f)){

        int data;
        fscanf(f,"%d",&data);
        insertNode(data);
    }

    fclose(f);

    printNode();
    deleteNode();

    printf("\nAfter deleting nodes with odd value\n");
    printNode();
    removeNode();
}
*/