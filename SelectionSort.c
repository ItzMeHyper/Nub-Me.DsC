#include <stdio.h>

int main() {
    int i = 0, n, j, small, temp, time=0;
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
        time++;
        small = i;
        j = i + 1;
        time++;time++;

        while (j < n) {
            time++;
            if (a[small] > a[j]) {
                small = j;
                time++;
            }
            j++;
        }

        if (i != small) {
            temp = a[i];
            time++;
            a[i] = a[small];
            time++;
            a[small] = temp;
            time++;
        }
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
    printf("Space complexity = %d\nTime complexity = %d\n", 24 + (4 * n), time);
    return 0;
}
