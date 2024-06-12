#include "functions.h"

struct Node * createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node **head, int i, int x) {
    struct Node *newNode = createNode(x);

    if (i == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node *temp = *head;

        for (int j = 1; j < i - 1 && temp != NULL; j++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Invalid position\n");
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

int lookup(struct Node *head, int x) {
    int pos = 1;
    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->data == x) {
            return pos;
        }

        temp = temp->next;
        pos++;
    }
    return -1;
}

int getItem(struct Node *head, int i) {
    struct Node *temp = head;

    for (int j = 1; j < i && temp != NULL; j++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return -1;
    }

    return temp->data;
}

void delete(struct Node **head, int i) {
    if (*head == NULL) {
        return;
    }

    if (i == 1) {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        struct Node *temp = *head;

        for (int j = 1; j < i - 1 && temp != NULL; j++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position\n");
        } else {
            struct Node *nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
        }
    }
}

int next(struct Node *head, int i) {
    struct Node *temp = head;

    for (int j = 1; j < i && temp != NULL; j++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return -1;
    }

    if (temp->next == NULL) {
        return i + 1;
    }

    for (int j = i + 1; temp != NULL; j++) {
        temp = temp->next;

        if (temp != NULL) {
            return j;
        }
    }

    return -1;
}

int prev(struct Node *head, int i) {
    if (i == 1) {
        return -1;
    }

    struct Node *temp = head;

    for (int j = 1; j < i - 1 && temp != NULL; j++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return -1;
    }

    return i - 1;
}

int size(struct Node *head) {
    int count = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printList(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
