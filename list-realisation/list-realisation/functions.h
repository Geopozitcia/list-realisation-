
#ifndef functions_h
#define functions_h

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node * createNode(int value);
void insert(struct Node **head, int i, int x);
int lookup(struct Node *head, int x);
int getItem(struct Node *head, int i);
void delete(struct Node **head, int i);
int next(struct Node *head, int i);
int prev(struct Node *head, int i);
int size(struct Node *head);
void printList(struct Node *head);



#endif /* functions_h */
