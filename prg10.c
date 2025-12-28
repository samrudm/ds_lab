#include <stdio.h>
#include <stdlib.h>

/* Structure declaration for a node */
struct node {
    int info;
    struct node *llink, *rlink;
};

typedef struct node *NODE;

/* Function to allocate memory for a node */
NODE getnode(void) {
    NODE x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Out of memory\n");
        exit(1);
    }
    return x;
}

/* Function to insert a node into BST */
NODE insert(NODE root, int item) {
    NODE temp, cur, prev;

    temp = getnode();
    temp->info = item;
    temp->llink = temp->rlink = NULL;

    if (root == NULL)
        return temp;

    prev = NULL;
    cur = root;

    while (cur != NULL) {
        prev = cur;
        if (item == cur->info) {
            printf("Duplicate items are not allowed\n");
            free(temp);
            return root;
        }
        if (item < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }

    if (item < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;

    return root;
}

/* Inorder traversal */
void in_order(NODE root) {
    if (root != NULL) {
        in_order(root->llink);
        printf("%d\t", root->info);
        in_order(root->rlink);
    }
}

/* Preorder traversal */
void pre_order(NODE root) {
    if (root != NULL) {
        printf("%d\t", root->info);
        pre_order(root->llink);
        pre_order(root->rlink);
    }
}

/* Postorder traversal */
void post_order(NODE root) {
    if (root != NULL) {
        post_order(root->llink);
        post_order(root->rlink);
        printf("%d\t", root->info);
    }
}

int main() {
    NODE root = NULL;
    int ch, item;

    for (;;) {
        printf("\n1. BST Insertion");
        printf("\n2. Preorder Traversal");
        printf("\n3. Inorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the item to be inserted: ");
                scanf("%d", &item);
                root = insert(root, item);
                break;

            case 2:
                printf("Preorder traversal is:\n");
                pre_order(root);
                printf("\n");
                break;

            case 3:
                printf("Inorder traversal is:\n");
                in_order(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder traversal is:\n");
                post_order(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
