#include "functions.h"

int main2(void) {
    struct Node *head = NULL;

    insert(&head, 1, 10);
    insert(&head, 2, 20);
    insert(&head, 3, 30);
    insert(&head, 4, 40);
    insert(&head, 5, 50);

    printf("Initial list: ");
    printList(head);

    insert(&head, 3, 25);

    printf("After inserting 25 at position 3: ");
    printList(head);

    delete(&head, 4);

    printf("After deleting element at position 4: ");
    printList(head);

    int position = lookup(head, 30);

    if (position != -1) {
        printf("Element 30 found at position: %d\n", position);
    } else {
        printf("Element 30 not found in the list.\n");
    }

    int element = getItem(head, 2);

    if (element != -1) {
        printf("Element at position 2: %d\n", element);
    } else {
        printf("No element found at position 2.\n");
    }

    int listSize = size(head);
    printf("Current list size: %d\n", listSize);

    return 0;
}
