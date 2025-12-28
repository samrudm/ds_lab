#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int info;
    struct node *link;
};

typedef struct node* NODE;

/* Allocate memory for a node */
NODE getnode(void) {
    NODE x = (NODE)malloc(sizeof(struct node));

    if (x == NULL) {
        printf("\nOut of memory");
        exit(1);
    }
    return x;
}

/* Insert node at the rear */
NODE insert_rear(int item, NODE first) {
    NODE temp, cur;

    temp = getnode();
    temp->info = item;
    temp->link = NULL;

    if (first == NULL)
        return temp;

    cur = first;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;

    return first;
}

/* Delete specified item */
NODE delete_item(NODE first, int item) {
    NODE prev, cur;

    if (first == NULL) {
        printf("\nList is empty");
        return first;
    }

    prev = NULL;
    cur = first;

    /* Search for item */
    while (cur != NULL && cur->info != item) {
        prev = cur;
        cur = cur->link;
    }

    if (cur == NULL) {
        printf("\nItem not found in the list");
        return first;
    }

    /* If first node is to be deleted */
    if (prev == NULL) {
        first = cur->link;
    } else {
        prev->link = cur->link;
    }

    free(cur);
    printf("\nItem deleted successfully");

    return first;
}

/* Display list */
void display(NODE first) {
    NODE temp;

    if (first == NULL) {
        printf("\nList is empty");
        return;
    }

    printf("\nThe contents of the list:\n");
    temp = first;

    while (temp != NULL) {
        printf("%d\t", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    NODE first = NULL;
    int choice, item, n, i;

    do {
        printf("\n1: Create List");
        printf("\n2: Delete specified item");
        printf("\n3: Display");
        printf("\n4: Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter number of nodes: ");
                scanf("%d", &n);

                for (i = 1; i <= n; i++) {
                    printf("Enter item %d: ", i);
                    scanf("%d", &item);
                    first = insert_rear(item, first);
                }
                break;

            case 2:
                printf("\nEnter item to be deleted: ");
                scanf("%d", &item);
                first = delete_item(first, item);
                break;

            case 3:
                display(first);
                break;

            case 4:
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid choice");
        }

    } while (choice != 4);

    return 0;
}
