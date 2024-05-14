#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

char stack[MAX_STACK_SIZE];
int top = -1;
char outputStr[100]; //잠깐 input.txt의 값 저장하는 용도
int i = 0; //outputStr의 길이 측정
int k = 0; // i만큼 길이 측정

int getToken(char string);
void InfixToPosfix(FILE *f);
void Input();


int main(void){
    Input();
}

int getToken(char string){

    int getT = 0;
    
    switch(string){
        case '(':
            getT = -1;
            break;
        case ')':
            getT = 3;
            break;
        case '+':
            getT = 1;
            break;
        case '-':
            getT = 1;
            break;
        case '*':
            getT = 2;
            break;
        case '/':
            getT = 2;
            break;
        case '%':
            getT = 2;
            break;
        default: //피연산자 일경우
            getT = 0;
    }

    return getT;
    
}

void InfixToPosfix(FILE *f){
    
    while(k != i){
        char c = outputStr[k];
        //printf("%c",c);
        int getT = getToken(outputStr[k]);
        //printf("%d  ", getT);
        if(getT == 0){ //피 연산자일경우 출력
            fprintf(f,"%c",c);
        }

        else if((getT == 1)||(getT == 2)){ //일반 연산자일 경우

            if(top == -1){ // stack이 비어있을 경우 무조건 push
                stack[++top] = c;
            }
            else{ // stack이 비어있지 않을경우
                if(getT > stack[top]){ //우선순위가 stack[top] 보다 높을경우 push
                    stack[++top] = c;
                }
                else{ //우선순위가 stack[top] 보다 작거나 같을경우 높은거 나올때까지 pop
                    while(getToken(stack[top]) >= getT){
                        fprintf(f,"%c",stack[top--]);
                    }
                    stack[++top] = c;
                }
            }
        }

        else if(getT == 3){ //) 일경우 ( 나올때까지 pop
            while(stack[top] != '('){
                fprintf(f,"%c",stack[top--]);
            }
            top--; // 마지막 top이 "(" 에서 멈춰있으므로 한번 더 --해준다.

        }

        else if(getT == -1){ //( 일경우 무조건 push
            stack[++top] = c;
        }

        k++;
    }

    while(top != -1){ //파일 끝까지 읽었을 경우 나머지 모두 출력
        fprintf(f,"%c",stack[top--]);
    }
}

void Input(){
    FILE *f = fopen("input.txt","r");

    if(f == NULL){
        printf("file does not open");
        exit(1);
    }

    while(1){
        char c = fgetc(f);
        
        if(c == EOF)
            break;

        outputStr[i++] = c;
        
    }

    fclose(f);

    f = fopen("output.txt","w");


    if(f == NULL){
        printf("file does not open");
        exit(1);
    }

    InfixToPosfix(f);

}