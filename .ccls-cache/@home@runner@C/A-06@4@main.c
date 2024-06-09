/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_SIZE 100
#define MAX_STACK_SIZE 10


typedef struct{
    int id;
    char name[MAX_NAME_SIZE];
}element;


element stack[MAX_STACK_SIZE];
int number = 0;
int top[MAX_STACK_SIZE];
int bottom[MAX_STACK_SIZE];

void quit();
int isError(int num);
void form();
void add(int num, char *id);
element delete1(int num);
void sprint(int num);
void Input();


int main(void){
    Input();
}

void quit(){

    printf("\nProgram end\n\n");
    
    for(int i = 0; i<number; i++){
        printf("stack %d :\n",i);
        
        if(bottom[i] == -1){
            for(int k = top[i]; k>=0; k--){
                printf("%s\n",stack[k].name);
            }
            printf("\n");
        }
            
        else{
            for(int k = top[i]-1; k>=bottom[i]; k--){
                printf("%s\n",stack[k].name);
            }
            printf("\n");
        printf("\n");
        }
    }
}

int isError(int num){
    if((num >=0)&&(num < number)){ // 범위 안에 있을때
        return 1;    
    }

    else{ // 범위 벗어날 경우
        return 0;
    }
}
void form(){
    printf(" C Language program to implement the Multiple Stacks\nadd stack_num(0-2) name : add 0 kim\n");
    printf("delete stack_num(0-2) : delete 0\n");
    printf("sprint stack_num(0-2) : sprint 0\n");
    printf("quit\n");
    printf("*****************************************************\n\n");
}

void add(int num, char *id){

    if(bottom[num] == -1){
        if(top[num] == bottom[num+1]-1){
            printf("Stack %d is Full\n", num);
            return;
        }
        printf("%s is Pushed in Stack No. %d\n",id,num);

        strcpy(stack[++top[num]].name,id);
        stack[top[num]].id = num;
        //printf("bottom : %d top : %d\n",bottom[num],top[num]);
    }

    else{
        if(top[num] == bottom[num+1]){
            printf("Stack %d is Full\n", num);
            return;
        }
        printf("%s is Pushed in Stack No. %d\n",id,num);
        //printf("bottom : %d top : %d\n",bottom[num],top[num]);
        
        strcpy(stack[top[num]++].name,id); // 90번줄과 91번 줄을 바꿔서 계속 결과가 잘 못 나왔다.
        stack[top[num]].id = num;

        //printf("%s",stack[3].name);
    }

}

element delete1(int num){
    if(top[num] == bottom[num]){
        printf("can't delete element\n");
        return;
    }
    
    if(bottom[num] == -1){
        printf("%s is popped from Stack No. %d\n",stack[top[num]--].name,num);
    }
    else{
        printf("%s is popped from Stack No. %d\n",stack[--top[num]].name,num);
    }
    
    return stack[top[num]];
}

void sprint(int num){
    //printf("sprint bottom : %d top : %d\n", bottom[num],top[num]);

    if(bottom[num] == -1){
        printf("\n");
        for(int i = top[num]; i>=0; i--){
            printf("%s\n",stack[i].name);
        }
        printf("\n");
    }
    else{
        printf("\n");
        for(int i = top[num]-1; i>=bottom[num]; i--){
            printf("%s\n",stack[i].name);
        }
        printf("\n");
    }
}

void Input(){

    printf("How Many Stacks ? : ");
    scanf("%d",&number);

    form();


    top[0] = bottom[0] = -1; //시작은 -1

    for(int i = 1; i<number; i++){
        
        top[i] = bottom[i] = (MAX_STACK_SIZE /number)*i;
    }
    
    bottom[number] = MAX_STACK_SIZE;  //add할때 top[num] == bottom[num+1]-1 일때까지 push하는데, num이 n-1일 경우 num+1 값은 지정되있지 않기때문에 index error가 뜰 것이다. 그래서 가장 큰 값으로 지정
    
    FILE *f;

    f = fopen("A-06/4/input.txt","r");

    if(f == NULL){
        printf("File does not open");
        exit(1);
    }

    while(!feof(f)){
        char str[20];
        int id = 0;
        
        fscanf(f,"%s",&str);

        if(!strcmp(str,"add")){
            fscanf(f,"%d %s",&id,&str);
            
            if(isError(id))
                add(id,str);
            else
                printf("stack number error, try again\n");
        }
            
        else if(!strcmp(str,"delete")){
            fscanf(f,"%d",&id);
            if(isError(id))
                delete1(id);
            else
                printf("stack number error, try again\n");
        }
            
        else if(!strcmp(str,"sprint")){
            fscanf(f,"%d",&id);
            if(isError(id))
                sprint(id);
            else
                printf("stack number error, try again\n");

        }
            
        else if(!strcmp(str,"quit")){
            quit();
            break;
        }
            
        else{
            printf("wrong command, try again!!\n");
        }
    }

    fclose(f);
}
*/