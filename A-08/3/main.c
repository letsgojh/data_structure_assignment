#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct expression expression;

struct expression {
  int degree;
  int coefficient;
  expression *link;
};

void printA(expression **head);
void printB(expression **head);
void printC(expression **head);
void make_c(expression **headA, expression **headB, expression **headC);
void add_a(expression **head, expression data);
void add_d(expression **head, expression data);
void Input();

int main(void) { Input(); }

void printA(expression **head) {
  printf("    a :\n");

  expression *currentNode;

  currentNode = *head;

  while (currentNode != NULL) {
    if (currentNode->coefficient > 0) {
      printf("(%p : %+6dx^%d : %p)\n", currentNode, currentNode->coefficient,
             currentNode->degree, currentNode->link);
    } else {
      printf("(%p : %6dx^%d : %p)\n", currentNode, currentNode->coefficient,
             currentNode->degree, currentNode->link);
    }
    currentNode = currentNode->link;
  }
  printf("\n");
}

void printB(expression **head) {
  printf("    b :\n");

  expression *currentNode;

  currentNode = *head;

  while (currentNode != NULL) {
    if (currentNode->coefficient > 0) {
      printf("(%p : %+6dx^%d : %p)\n", currentNode, currentNode->coefficient,
             currentNode->degree, currentNode->link);
    } else {
      printf("(%p : %6dx^%d : %p)\n", currentNode, currentNode->coefficient,
             currentNode->degree, currentNode->link);
    }
    currentNode = currentNode->link;
  }
  printf("\n");
}

void printC(expression **head) {
  printf("    a+b=c :\n");

  expression *currentNode;

  currentNode = *head;

  while (currentNode != NULL) {
    if (currentNode->coefficient > 0) {
      printf("(%p : %+6dx^%d : %p)\n", currentNode, currentNode->coefficient,
             currentNode->degree, currentNode->link);
    } else {
      printf("(%p : %6dx^%d : %p)\n", currentNode, currentNode->coefficient,
             currentNode->degree, currentNode->link);
    }
    currentNode = currentNode->link;
  }
  printf("\n");
}

void make_c(expression **headA, expression **headB, expression **headC) {
  expression *currentA = *headA;
  expression *currentB = *headB;

  while ((currentA != NULL) &&
         (currentB !=
          NULL)) { //왜 and 연산을 썻는데 currentA,B에 남은 노드가 존재할까?
    // 왜 ||연산은 안되고 &&연산은 될까? 남은 노드가 있으려면 ||연산 써야되는 것
    // 아닌가?
    expression *newNode = (expression *)malloc(
        sizeof(expression)); //바깥쪽에 넣어서 계속 답이 안나옴

    if (currentA->degree < currentB->degree) {
      newNode->degree = currentB->degree;
      newNode->coefficient = currentB->coefficient;
      currentB = currentB->link;
      // printf("cof : %d, deg : %d",newNode->coefficient, newNode->degree);
    } else if (currentA->degree > currentB->degree) {
      newNode->degree = currentA->degree;
      newNode->coefficient = currentA->coefficient;
      currentA = currentA->link;
      // printf("cof : %d, deg : %d",newNode->coefficient, newNode->degree);
    } else {
      newNode->degree = currentA->degree;
      newNode->coefficient = currentA->coefficient + currentB->coefficient;
      // printf("cof : %d, deg : %d",newNode->coefficient, newNode->degree);

      currentA = currentA->link;
      currentB = currentB->link;
    }

    newNode->link = NULL;

    if (*headC == NULL) {
      *headC = newNode;
      continue;
    }

    expression *currentNode;

    currentNode = *headC;

    while (currentNode->link != NULL) {
      currentNode = currentNode->link;
    }

    currentNode->link = newNode;
  }

  while (currentA != NULL) {
    expression *node = (expression *)malloc(sizeof(expression));
    node->coefficient = currentA->coefficient;
    node->degree = currentA->degree;
    node->link = NULL;

    expression *currentNode = *headC;

    while (currentNode->link != NULL) {
      currentNode = currentNode->link;
    }

    currentNode->link = node;

    currentA = currentA->link;
  }

  while (currentB != NULL) {
    expression *node = (expression *)malloc(sizeof(expression));
    node->coefficient = currentB->coefficient;
    node->degree = currentB->degree;
    node->link = NULL;

    expression *currentNode = *headC;

    while (currentNode->link != NULL) {
      currentNode = currentNode->link;
    }

    currentNode->link = node;

    currentB = currentB->link;
  }
}

void add_a(expression **headA, expression data) {
  expression *newNode = (expression *)malloc(sizeof(expression));
  newNode->degree = data.degree;
  newNode->coefficient = data.coefficient;
  newNode->link = NULL;

  if (*headA == NULL) {
    *headA = newNode;
    return;
  }

  newNode->link = *headA;
  *headA = newNode;
}

void add_d(expression **headB, expression data) {
  expression *newNode = (expression *)malloc(sizeof(expression));
  newNode->degree = data.degree;
  newNode->coefficient = data.coefficient;
  newNode->link = NULL;

  if (*headB == NULL) {
    *headB = newNode;
    return;
  }

  expression *currentNode;

  currentNode = *headB;

  while (currentNode->link != NULL) {
    currentNode = currentNode->link;
  }

  currentNode->link = newNode;
}

void Input() {
  FILE *f;

  f = fopen("A-08/3/a.txt", "r");

  expression *headA = NULL;

  char typeA;

  fscanf(f, "%c", &typeA); // a가 내림차순인지 올림차순인지 파악

  if (typeA == 97) {
    while (!feof(f)) {
      expression a;
      fscanf(f, "%d %d", &a.coefficient, &a.degree);
      add_a(&headA, a);
    }
  }
  if (typeA == 100) {
    while (!feof(f)) {
      expression a;
      fscanf(f, "%d %d", &a.coefficient, &a.degree);
      add_d(&headA, a);
    }
  }

  fclose(f);

  f = fopen("A-08/3/b.txt", "r");

  char typeB;

  fscanf(f, "%c", &typeB); // a가 내림차순인지 올림차순인지 파악

  expression *headB = NULL;

  if (typeB == 97) {
    while (!feof(f)) {
      expression b;
      fscanf(f, "%d %d", &b.coefficient, &b.degree);
      add_a(&headB, b);
    }
  }
  if (typeB == 100) {
    while (!feof(f)) {
      expression b;
      fscanf(f, "%d %d", &b.coefficient, &b.degree);
      add_d(&headB, b);
    }
  }

  fclose(f);

  printA(&headA);
  printB(&headB);

  expression *headC = NULL;

  make_c(&headA, &headB, &headC);
  printC(&headC);

  // printf("coef : %d, degree : %d",headC->coefficient,headC->degree);
}