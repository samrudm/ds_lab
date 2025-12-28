#include <stdio.h>
#include <stdlib.h>

/* Structure declaration */
struct node {
    int data;
    int priority;
    struct node *link;
};

typedef struct node *NODE;

/* Function to allocate memory for a node */
NODE getnode(void) {
    NODE x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("\nOut of memory");
        exit(1);
    }
    return x;
}

/* Function to insert a node based on priority */
NODE insert_priority(NODE first) {
    int val, pri;
    NODE temp, cur, prev;

    printf("\nEnter the value: ");
    scanf("%d", &val);

    printf("Enter the priority: ");
    scanf("%d", &pri);

    temp = getnode();
    temp->data = val;
    temp->priority = pri;
    temp->link = NULL;

    /* Insert at front if queue empty or higher priority */
    if (first == NULL || pri < first->priority) {
        temp->link = first;
        return temp;
    }

    prev = NULL;
    cur = first;

    while (cur != NULL && cur->priority <= pri) {
        prev = cur;
        cur = cur->link;
    }

    prev->link = temp;
    temp->link = cur;

    return first;
}

/* Function to delete from front */
NODE delete_node(NODE first) {
    NODE temp;

    if (first == NULL) {
        printf("\nQUEUE UNDERFLOW");
        return first;
    }

    temp = first;
    printf("\nDeleted item is: %d", temp->data);
    first = first->link;
    free(temp);

    return first;
}

/* Function to display queue */
void display(NODE first) {
    NODE temp;

    if (first == NULL) {
        printf("\nQUEUE IS EMPTY");
        return;
    }

    printf("\nTHE CONTENTS OF PRIORITY QUEUE IS:");
    temp = first;

    while (temp != NULL) {
        printf("\n%d [priority=%d]", temp->data, temp->priority);
        temp = temp->link;
    }
}

int main() {
    NODE first = NULL;
    int option;

    do {
        printf("\n\n***** MAIN MENU *****");
        printf("\n1. INSERT");
        printf("\n2. DELETE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                first = insert_priority(first);
                break;

            case 2:
                first = delete_node(first);
                break;

            case 3:
                display(first);
                break;

            case 4:
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid option");
        }

    } while (option != 4);

    return 0;
}
