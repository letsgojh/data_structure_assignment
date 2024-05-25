#include <stdio.h>
#include <stdlib.h>


typedef struct listNode listNode;

struct listNode{
    int data;
    listNode * link;
};

listNode * first = NULL;

void printNode();
void addNode(int data);
void deleteNode();
void Input();


int main(void){
    Input();
}

void printNode(){
    listNode * currentNode;

    currentNode = first->link;
    /*
    do{ //circular linked list 를 출력할때는 do while문을 쓴 후, 마지막에 first 한번 더 출력
        currentNode = currentNode->link;
        printf("(%4p, %4d, %4p)",currentNode,currentNode->data,currentNode->link);
    }while(currentNode!= first);
    //printf("(%5p, %5d, %5p)",currentNode,currentNode->data,currentNode->link);
    */
    printf("The Circularly Linked List contatins:\n");
    while(currentNode != first){
        printf("(%4p, %4d, %4p)",currentNode,currentNode->data,currentNode->link);
        currentNode = currentNode->link;
    }
    printf("(%4p, %4d, %4p)",currentNode,currentNode->data,currentNode->link);
    
}

void addNode(int data){
    listNode * newNode = (listNode *)malloc(sizeof(listNode));

    newNode->data = data;
    newNode->link = NULL;


    if(first == NULL){
        first = newNode;
        newNode->link = first;
        return;
    }

    newNode->link = first->link;
    first->link = newNode;
    first = newNode;
}

void deleteNode(){
    
    listNode * delNode;
    listNode * previousNode;
    listNode * flowNode;
    listNode * currentNode;

    flowNode = first;

    while(flowNode->link != first){
        
        flowNode = first;

        while((first->data)%2 == 1){ //첫번째 노드가 홀수일경우
            while(currentNode->link != first){
                currentNode = currentNode->link;
            }
            currentNode->link = first->link;
            delNode = first;
            first = currentNode->link;
            flowNode = first;
            free(delNode);
            break;
        }

        delNode = flowNode;
        previousNode = flowNode;

        delNode = delNode->link;

        if((delNode->data)%2 == 1){
            delNode->link = previousNode->link;
            free(delNode);
            flowNode = flowNode->link;
            continue;
        }
        
        previousNode = previousNode->link;

        flowNode = flowNode->link;
    }
}

void Input(){
    FILE *f;

    f = fopen("A-08/2/input.txt","r");

    if(f == NULL){
        printf("file does not open\n");
        exit(1);
    }

    while(!feof(f)){
        int data;
        fscanf(f,"%d",&data);
        addNode(data);
        //printf("%d\n",data);
    }

    printNode();
    deleteNode();
    printf("\n\nAfter deleting nodes with odd value\n\n");
    printNode();

}