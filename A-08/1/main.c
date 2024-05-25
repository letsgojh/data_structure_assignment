/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct node node;

typedef struct node{
    int subNum;
    int classNum;
    int score;
    node * next;
};


void add();
//void pop();
void sprint();
void Input();


int main(void){
    Input();
}

void add(node element,node** top){
    node * newNode = (node *)malloc(sizeof(node));

    newNode->subNum = element.subNum;
    newNode->classNum = element.classNum;
    newNode->score = element.score;
    newNode-> next = NULL;

    if(*top == NULL){
        *top = newNode;
        return;
    }

    if((*top)->classNum >newNode->classNum){ //오름차순 정렬
        newNode->next = *top;
        *top = newNode;
        return;
    }

    node * currentNode;
    node * previousNode;


    currentNode = previousNode = *top;

    while(currentNode->next != NULL){
        currentNode = currentNode->next;
        if(currentNode->classNum > newNode->classNum){
            newNode->next = currentNode;
            previousNode->next = newNode;
            return;
        }
        previousNode = previousNode->next;
    }
    currentNode->next = newNode;
}


void sprint(node ** top){
    node * currentNode;

    currentNode = *top;

    printf("*************************\n");
    while(currentNode != NULL){
        printf("%8d %4d %4d\n", currentNode->subNum,currentNode->classNum,currentNode->score);
        currentNode = currentNode->next;
    }

}

void Input(){
    FILE *f;

    f = fopen("A-07/4/input.txt","r");


    node * front1 = NULL;
    node * front2 = NULL;
    node * front3 = NULL;
    
    node * rear1 = NULL;
    node * rear2 = NULL;
    node * rear3 = NULL;

    while(!feof(f)){
        node element;
        fscanf(f,"%d %d %d",&element.subNum,&element.classNum,&element.score);
        //printf("%d %d %d\n",element.subNum,element.classNum,element.score);

        if(element.subNum== 0){
            add(element,&rear1);
        }
        else if(element.subNum == 1){
            add(element,&rear2);
        }
        else if(element.subNum == 2){
            add(element,&rear3);
        }
    }

    printf("과목번호, 학반, 성적\n");
    sprint(&rear1);
    sprint(&rear2);
    sprint(&rear3);
}*/