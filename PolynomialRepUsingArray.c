#include <stdio.h>

int main() {
    int n, i;
    struct polynomial {
        int coeff;
        int expo;
    } poly[50];

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the coefficient and exponent of term %d: ", i + 1);
        scanf("%d %d", &poly[i].coeff, &poly[i].expo);
    }

    printf("The entered polynomial is: \n");
  
    for (i = 0; i < n; i++) {
        if (poly[i].expo != 0){
            printf("(%dx^%d)", poly[i].coeff, poly[i].expo);
         } else {
            printf("(%d)", poly[i].coeff);
         }
        if (i != n - 1){
            printf(" + ");
        }
    }
}
