#include <stdio.h>

int main() {
    int r, c, i, j, k;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    int A[r][c], B[r * c + 1][3];

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Entered Matrix is:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    k = 1;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (A[i][j] != 0) {
                B[k][0] = i;
                B[k][1] = j;
                B[k][2] = A[i][j];
                k++;
            }
        }
    }
    B[0][0] = r;
    B[0][1] = c;
    B[0][2] = k - 1;

    printf("Triplet representation is:\n");
    printf("Row\tColumn\tValue\n");
    for (i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", B[i][0], B[i][1], B[i][2]);
    }
    return 0;
}