#include<stdio.h>
int main() {

    int  i, n, x, flag = 0, time=0;
    time++;

    printf("Enter the number of elements: ");
    time++;
    scanf("%d", &n);
    time++;

    int a[n], mid, left = 0, right = n - 1;
    time++; time++;

    printf("Enter the elements: ");
    time++;

    for (i = 0;i < n;i++) {
        time++;
        scanf("%d", &a[i]);
        time++;
    }

    printf("Enter the element to be searched: ");
    time++;
    scanf("%d", &x);
    time++;

    while (left <= right) {
        mid = (left + right) / 2;
        time++;

        if (x == a[mid]) {
            flag = 1;
            break;
        }
        else if (x > a[mid]) {
            left = mid + 1;
            time++;
        }
        else if (x < a[mid]) {
            right = mid - 1;
            time++;
        }
    }
    if (flag == 0) {
        printf("Element not found\n");
        time++;
    }
    else if (flag == 1) {
        printf("Element found at location %d\n", mid + 1);
        time++;
    }

    time++;
    printf("Space complexity = %d\nTime complexity = %d\n", 32 + (4 * n), time);
}
