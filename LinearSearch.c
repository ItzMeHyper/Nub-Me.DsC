#include<stdio.h>

int main() {

    int n, i, x, count = 0, time = 0;
    time++;
    time++;

    printf("Enter the number of elements: ");
    time++;
    scanf("%d", &n);
    time++;

    int a[n];

    printf("Enter the elements: ");
    time++;

    for (i = 0;i < n;i++) {
        time++;
        scanf("%d", &a[i]);
        time++;
    }
    time++;

    printf("Enter the element to be searched: ");
    time++;
    scanf("%d", &x);
    time++;

    for (i = 0;i < n;i++) {
        time++;
        if (a[i] == x) {
            time++;
            count++;
            printf("Element is found at %d position\n", i + 1);
            time++;
        }
    }
    time++;

    if (count > 0) {
        time++;
            printf("Element is found %d times \n", count);
        time++;
    }
    else {
        printf("Element is not found\n");
        time++;
    }

    time++;
    printf("Space complexity = %d\nTime complexity = %d\n", 20 + (4 * n), time);
}