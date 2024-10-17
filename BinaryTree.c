#include<stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n + 1];

    printf("Enter the elements: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Elements in the array:\n ");
    for (int i = 1; i <= n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    while (1) {
        printf("Enter any node (or 0 to exit): ");
        int node;
        scanf("%d", &node);

        if (node == 0) {
            break;
        }

        if (node < 1 || node > n) {
            printf("Invalid node. Please enter a valid node between 1 and %d.\n", n);
            continue;
        }

        if (node == 1) {
            printf("This is the root node.\n");
        }
        else {
            printf("The parent node is: %d\n", node / 2);
            printf("The value of parent node is: %d\n", arr[node / 2]);
            printf("The value of node is: %d\n", arr[node]);

            int Lchild = 2 * node;
            int Rchild = (2 * node) + 1;

            if (Lchild > n && Rchild > n) {
                printf("This node has no child\n");
            }
            else {
                if (Lchild <= n) {
                    printf("The left child node is: %d and the value at the node is: %d\n",
                        Lchild, arr[Lchild]);
                }
                else {
                    printf("This node has no left child.\n");
                }

                if (Rchild <= n) {
                    printf("The right child node is: %d and the value at the node is: %d\n",
                        Rchild, arr[Rchild]);
                }
                else {
                    printf("This node has no right child.\n");
                }
            }
        }
    }
    return 0;
}
