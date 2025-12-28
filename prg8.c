#include <stdio.h>
#include <stdlib.h>

/* Function to find maximum amongst n elements (recursive) */
int findMaxElement(int arr[], int size) {
    static int i = 0;
    static int max = -999;

    if (i < size) {
        if (max < arr[i]) {
            max = arr[i];
        }
        i++;
        findMaxElement(arr, size);
    }
    return max;
}

/* Reset helper to keep SAME output every time */
void resetMaxFinder(void) {
    findMaxElement(NULL, 0);   // dummy call
}

/* Function to find product of two natural numbers */
int product(int a, int b) {
    if (a < b)
        return product(b, a);
    else if (b != 0)
        return a + product(a, b - 1);
    else
        return 0;
}

/* Tower of Hanoi */
void tower(int n, char src, char aux, char dest) {
    if (n == 1) {
        printf("Move disk %d from peg %c to peg %c\n", n, src, dest);
        return;
    }
    tower(n - 1, src, dest, aux);
    printf("Move disk %d from peg %c to peg %c\n", n, src, dest);
    tower(n - 1, aux, src, dest);
}

int main() {
    int arr[20];
    int i, n, max;
    int a, b, res;
    int num, ch;

    for (;;) {
        printf("\n******************************************\n");
        printf("1 : Find Max Element\n");
        printf("2 : Multiplication of two natural numbers\n");
        printf("3 : Tower of Hanoi\n");
        printf("4 : Exit\n");
        printf("******************************************\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {

            case 1:
                printf("Enter the size of the array: ");
                scanf("%d", &n);

                printf("Enter %d elements of the array:\n", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }

                /* Reset static values */
                resetMaxFinder();

                max = findMaxElement(arr, n);
                printf("Maximum element in the array is %d\n", max);
                break;

            case 2:
                printf("Enter two numbers to find their product:\n");
                scanf("%d %d", &a, &b);

                res = product(a, b);
                printf("Product of %d and %d is %d\n", a, b, res);
                break;

            case 3:
                printf("Enter the number of disks:\n");
                scanf("%d", &num);

                printf("The sequence of moves involved in the Tower of Hanoi are:\n");
                tower(num, 'S', 'T', 'D');
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
