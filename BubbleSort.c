#include <stdio.h>

void main() {
    int i, j, n, temp, time =0; 
    time++;

    printf("Enter the number of elements: ");
    time++;
    scanf("%d", &n);
    time++;

    int arr[n]; 

    printf("Enter the Elemnts: \n");
    time++;

    for(i = 0; i < n; i++) {
        time++;
        scanf("%d", &arr[i]);
        time++;
    }

    for(i = 0; i < n-1; i++) {
        time++;
        for(j = 0; j < n-i-1; j++) {
            time++;
            if(arr[j] > arr[j+1]) {
                time++;
                temp = arr[j];
                time++;
                arr[j] = arr[j+1];
                time++;
                arr[j+1] = temp;
                time++;
            }
        }
    }
    printf("The sorted elemts are: \n");
    time++;
    for(i = 0; i<n; i++){
        time++;
        printf("%d \t", arr[i]);
        time++;
    }
    time++;time++;
    printf("\nSpace complexity = %d\nTime complexity = %d\n", 20 + (4 * n), time);
}
