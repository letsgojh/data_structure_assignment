#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
  node *left;
  node *right;
  char data;
};

int top = -1;

node *stack[80];

void preOrder(node **root);
void levelOrderTraversal(node **root);
void inOrder(node **root);
int createToken(char ope);
void add(node **root, char data);
void Input();

int main(void) { Input(); }

void preOrder(node **root) {
  node *currentNode = *root;

  printf("%c ", currentNode->data);
  if (currentNode->left != NULL)
    preOrder(&currentNode->left);

  if (currentNode->right != NULL)
    preOrder(&currentNode->right);
}
void levelOrderTraversal(node **root) {

  int front = 0;
  int rear = 0;

  node *queue[30];
  //전위연산자를 써서 코드가 돌아가지 않았다. 후위연산자를 쓰자
  queue[rear++] = *root;

  while (front != rear) {
    node *ptr = queue[front++];

    if (ptr !=
        NULL) { //자식노드가 NULL일때도 추가하는 에러 존재 -> if문으로 처리
      printf("%c ", ptr->data);
      queue[rear++] = ptr->left;
      queue[rear++] = ptr->right;
    }
  }
}

void inOrder(node **root) { //그냥 외우는게 빠를 듯 ㅋㅋ

  //반복문을 통한 inOrder 구현은 stack을 사용해야한다.
  node *currentNode = *root;

  node *tempStack[20];
  int tempTop = -1;

  while (currentNode != NULL ||
         tempTop != -1) { // currentNode가 NULL이 아니거나 stack이 비어있지
                          // 않으면 loop 계속돈다.
    // currentNode는 NULL인데 stack이 비어있지 않을때도 loop는 돈다.
    while (currentNode != NULL) {
      tempStack[++tempTop] = currentNode; //왼쪽으로만 돌면서 push
      currentNode = currentNode->left;
    }

    currentNode = tempStack[tempTop--];
    printf("%c ", currentNode->data);
    currentNode = currentNode->right;
  }
}

int createToken(char ope) {

  switch (ope) {
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

void add(node **root, char data) {

  node *newNode = (node *)malloc(sizeof(node));

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

  if (token == 0) {
    stack[++top] = newNode;
  }

  else { //오른쪽 왼쪽순으로 넣기 , 왼쪽 오른쪽 XX
    newNode->right = stack[top--];
    newNode->left = stack[top--];
    stack[++top] = newNode;
    *root = newNode;
  }
}

void Input() {
  FILE *f;

  f = fopen("A-11/2/input.txt", "r");

  if (f == NULL) {
    printf("file does not open\n");
    exit(1);
  }

  char k;
  node *root = NULL;

  printf("the length of input string should be less than 80\n");
  printf("input string (postfix expression) : ");
  while (1) {

    k = fgetc(f);

    if (k == EOF)
      break; //계속 break;가 아니라 return;이라함

    add(&root, k);
    printf("%c", k);
  }
  printf("\ncreating its binary tree\n\n");

  printf("iterative inorder traversal    : ");
  inOrder(&root);
  printf("\n 스텍에 들어가는 데이터의 순서 : ");
  preOrder(&root);
  printf("\n\nlevel order traversal          : ");
  levelOrderTraversal(&root);
}