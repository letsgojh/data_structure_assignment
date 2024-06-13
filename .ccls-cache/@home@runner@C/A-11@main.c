#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node{
    node * left;
    node * right;
    char data;
};

int top = -1;

node * stack[80];

void inOrder(node **root);
void preOrder(node **root);
void postOrder(node **root);
int createToken(char ope);
void add(node ** root,char data);
void Input();


int main(void){
    Input();
}

void inOrder(node **root){

    node * currentNode = *root;
    
    if(currentNode->left != NULL){
        inOrder(&currentNode->left);
    }

    printf("%c",currentNode->data);
    
    if(currentNode->right != NULL){
        inOrder(&currentNode->right);
    }
}
void preOrder(node **root){
    node * currentNode = *root;

    printf("%c",currentNode->data);
    
    if(currentNode->left != NULL){
        preOrder(&currentNode->left);
    }

    if(currentNode->right != NULL){
        preOrder(&currentNode->right);
    }
}
void postOrder(node **root){
    node * currentNode = *root;

    if(currentNode->left != NULL){
        postOrder(&currentNode->left);
    }

    if(currentNode->right != NULL){
        postOrder(&currentNode->right);
    }

    printf("%c",currentNode->data);
}

int createToken(char ope){

    switch(ope){
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        case '%':
            return 2;
            break;
        default:
            return 0;
    }
}

void add(node ** root,char data){

    node * newNode = (node*)malloc(sizeof(node));

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;

    int token = createToken(data);
    
/* root가 계속 바뀌는데 첫번째로 지정해서 코드가 안돌아간 것
    if(root == NULL){
        root = newNode;
        stack[++top] = newNode;
        return;
    }
*/
    
    if(token == 0){
        stack[++top] = newNode;
    }

    else{//오른쪽 왼쪽순으로 넣기 , 왼쪽 오른쪽 XX
        newNode->right = stack[top--];
        newNode->left = stack[top--];
        stack[++top] = newNode;
        *root = newNode;
    }
}

void Input(){
    FILE * f;

    f = fopen("A-11/input.txt","r");

    if(f == NULL){
        printf("file does not open\n");
        exit(1);
    }

    char k;
    node * root = NULL;

    printf("the length of input string should be less than 80\n");
    printf("input string (postfix expression) : ");
    while(1){
        
        k = fgetc(f);

        if(k == EOF)
            break; //계속 break;가 아니라 return;이라함

        add(&root,k);
        printf("%c",k);
    }
    printf("\ncreating its binary tree\n\n");

    printf("inorder traversal    :");
    inOrder(&root);
    printf("\npreorder traversal    :");
    preOrder(&root);
    printf("\npostorder traversal    :");
    postOrder(&root);

}