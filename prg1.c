#include <stdio.h>
struct distance
{
    int kms;
    int meters;
};

typedef struct distance DISTANCE;
DISTANCE add_distance(DISTANCE *, DISTANCE *);
DISTANCE subtract_distance(DISTANCE *, DISTANCE *);
DISTANCE d1, d2, d3, d4;

int main()
{
    int option;

    do
    {
        printf("\n******** MAIN MENU ********");
        printf("\n1. Read the distances");
        printf("\n2. Display the distances");
        printf("\n3. Add the distances");
        printf("\n4. Subtract the distances");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nEnter first distance (kms meters): ");
                scanf("%d %d", &d1.kms, &d1.meters);

                printf("Enter second distance (kms meters): ");
                scanf("%d %d", &d2.kms, &d2.meters);
                break;

            case 2:
                printf("\nFirst distance : %d kms %d meters", d1.kms, d1.meters);
                printf("\nSecond distance: %d kms %d meters", d2.kms, d2.meters);
                break;

            case 3:
                d3 = add_distance(&d1, &d2);
                printf("\nSum of distances: %d kms %d meters", d3.kms, d3.meters);
                break;

            case 4:
                d4 = subtract_distance(&d1, &d2);
                printf("\nDifference of distances: %d kms %d meters", d4.kms, d4.meters);
                break;

            case 5:
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid option! Try again.");
        }

    } while(option != 5);

    return 0;
}
DISTANCE add_distance(DISTANCE *d1, DISTANCE *d2)
{
    DISTANCE sum;

    sum.meters = d1->meters + d2->meters;
    sum.kms = d1->kms + d2->kms;

    if(sum.meters >= 1000)
    {
        sum.kms += sum.meters / 1000;
        sum.meters = sum.meters % 1000;
    }

    return sum;
}
DISTANCE subtract_distance(DISTANCE *d1, DISTANCE *d2)
{
    DISTANCE sub;
    int total1, total2, diff;

    total1 = d1->kms * 1000 + d1->meters;
    total2 = d2->kms * 1000 + d2->meters;

    if(total1 >= total2)
        diff = total1 - total2;
    else
        diff = total2 - total1;

    sub.kms = diff / 1000;
    sub.meters = diff % 1000;

    return sub;
}
