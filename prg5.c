#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void push(int item, int s[], int *top) {
    if (*top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    (*top)++;
    s[*top] = item;
    printf("%d is successfully inserted\n", item);
}

void pop(int s[], int *top) {
    if (*top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d element is deleted\n", s[*top]);
    (*top)--;
}

void display(int s[], int top) {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack contains:\n");
    for (i = top; i >= 0; i--) {
        printf("%d\n", s[i]);
    }
}

int main() {
    int choice, item;
    int s[MAX];
    int top = -1;

    for (;;) {
        printf("\n*****************");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n*****************");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an item to be inserted: ");
                scanf("%d", &item);
                push(item, s, &top);
                break;

            case 2:
                pop(s, &top);
                break;

            case 3:
                display(s, top);
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
