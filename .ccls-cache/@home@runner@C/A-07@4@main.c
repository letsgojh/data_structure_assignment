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


void push();
//void pop();
void sprint();
void Input();


int main(void){
    Input();
}

void push(node element,node** top){
    node * newNode = (node *)malloc(sizeof(node));

    newNode->subNum = element.subNum;
    newNode->classNum = element.classNum;
    newNode->score = element.score;
    newNode-> next = NULL;

    if(*top == NULL){
        *top = newNode;
        return;
    }

    if((*top)->classNum <newNode->classNum){ //내림차순 정렬
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


    node * top1 = NULL;
    node * top2 = NULL;
    node * top3 = NULL;
    
    while(!feof(f)){
        node element;
        fscanf(f,"%d %d %d",&element.subNum,&element.classNum,&element.score);
        //printf("%d %d %d\n",element.subNum,element.classNum,element.score);
        
        if(element.subNum== 0){
            push(element,&top1);
        }
        else if(element.subNum == 1){
            push(element,&top2);
        }
        else if(element.subNum == 2){
            push(element,&top3);
        }
    }

    printf("과목번호, 학반, 성적\n");
    sprint(&top1);
    sprint(&top2);
    sprint(&top3);
}*/