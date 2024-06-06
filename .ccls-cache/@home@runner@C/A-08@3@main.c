/*
#include <stdio.h>
#include <stdlib.h>

typedef struct listNode listNode;

struct listNode {
    int data;
    listNode *link;
};

listNode *first = NULL;

void printNode();
void addNode(int data);
void deleteNode();
void Input();

int main(void) {
    Input();
    return 0;
}

void printNode() {
    if (first == NULL) {
        printf("The list is empty.\n");
        return;
    }

    listNode *currentNode = first;

    printf("The Circularly Linked List contains:\n");
    do {
        printf("(%4p, %4d, %4p)\n", currentNode, currentNode->data, currentNode->link);
        currentNode = currentNode->link;
    } while (currentNode != first);
}

void addNode(int data) {
    listNode *newNode = (listNode *)malloc(sizeof(listNode));

    newNode->data = data;
    newNode->link = NULL;

    if (first == NULL) {
        first = newNode;
        newNode->link = first;
    } else {
        newNode->link = first->link;
        first->link = newNode;
        first = newNode;
    }
}

void deleteNode() {
    if (first == NULL) {
        return;
    }

    listNode *currentNode = first;
    listNode *prevNode = NULL;

    // If the first node needs to be deleted
    while ((first->data) % 2 == 1) {
        if (first->link == first) {  // Only one node in the list
            free(first);
            first = NULL;
            return;
        }

        // Move to the last node to update its link
        listNode *lastNode = first;
        while (lastNode->link != first) {
            lastNode = lastNode->link;
        }

        listNode *delNode = first;
        first = first->link;
        lastNode->link = first;
        free(delNode);
        currentNode = first;
    }

    // For the rest of the nodes
    while (currentNode->link != first) {
        if ((currentNode->link->data) % 2 == 1) {
            listNode *delNode = currentNode->link;
            currentNode->link = delNode->link;
            free(delNode);
        } else {
            currentNode = currentNode->link;
        }
    }
}

void Input() {
    FILE *f;

    f = fopen("A-08/3/input.txt", "r");

    if (f == NULL) {
        printf("File does not open\n");
        exit(1);
    }

    while (!feof(f)) {
        int data;
        fscanf(f, "%d", &data);
        addNode(data);
    }

    fclose(f);

    printNode();
    deleteNode();
    //printf("%d",first->data);
    printf("\n\nAfter deleting nodes with odd value\n\n");
    printNode();
}
*/