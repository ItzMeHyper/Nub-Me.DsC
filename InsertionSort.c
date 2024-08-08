#include <stdio.h>

int main() {
    int i = 1, n, j, temp, time = 0;
    time++;

    printf("Enter the size of array: ");
    time++;
    scanf("%d", &n);
    time++;

    int a[n];

    printf("Enter %d elements: \n", n);
    time++;

    for (i = 0;i < n;i++) {
        time++;
        scanf("%d", &a[i]);
        time++;
    }

    i = 0;
    while (i < n) {
        temp = a[i];
        time++;
        j = i - 1;
        time++;

        while ((j >= 0) && (temp < a[j])) {
            time++;
            a[j + 1] = a[j];
            time++;
            j--;
        }
        a[j + 1] = temp;
        time++;
        i++;
    }
    printf("The sorted elements are: \n");
    time++;
    for (i = 0;i < n;i++) {
        time++;
        printf("%d\n", a[i]);
        time++;
    }
    time++;
    printf("Space complexity = %d\nTime complexity = %d\n", 20 + (4 * n), time);
}