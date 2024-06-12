#include "functions.h"

int main(void) {
    struct Node *head = NULL;
    int choice, value, position;

    while (1) {
        printf("\nOperations on Singly Linked List:\n");
        printf("1. Insert\n2. Lookup\n3. Get Item\n4. Delete\n5. Next\n6. Prev\n7. Size\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insert(&head, position, value);
                break;

            case 2:
                printf("Enter the value to lookup: ");
                scanf("%d", &value);
                position = lookup(head, value);

                if (position == -1) {
                    printf("Element not found\n");
                } else {
                    printf("Element found at position %d\n", position);
                }

                break;

            case 3:
                printf("Enter the position to get item: ");
                scanf("%d", &position);
                value = getItem(head, position);

                if (value == -1) {
                    printf("Invalid position\n");
                } else {
                    printf("Value at position %d is %d\n", position, value);
                }

                break;

            case 4:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                delete(&head, position);
                break;

            case 5:
                printf("Enter the position to get next: ");
                scanf("%d", &position);
                value = next(head, position);

                if (value == -1) {
                    printf("Invalid position\n");
                } else {
                    printf("Next position of %d is %d\n", position, value);
                }

                break;

            case 6:
                printf("Enter the position to get previous: ");
                scanf("%d", &position);
                value = prev(head, position);

                if (value == -1) {
                    printf("Invalid position\n");
                } else {
                    printf("Previous position of %d is %d\n", position, value);
                }

                break;

            case 7:
                printf("Size of the list is %d\n", size(head));
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
