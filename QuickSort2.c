#include <stdio.h>

void quicksort(int x[], int first, int last);
int partition(int x[], int first, int last);

int main() {
    int size, i;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid size. Size should be greater than 0.\n");
        return 1;
    }

    int x[size];
    printf("Enter %d elements: ", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &x[i]);
    }
    
    printf("Entered Elements: ");
    for (i = 0; i < size; i++) {
        printf("%d ", x[i]);
    }
    printf("\n\n");

    quicksort(x, 0, size - 1);

    printf("Sorted elements: ");
    for (i = 0; i < size; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    return 0;
}

void quicksort(int x[], int first, int last) {
    if (first < last) {
        int pivotIndex = partition(x, first, last);
        quicksort(x, first, pivotIndex - 1);
        quicksort(x, pivotIndex + 1, last);
    }
}

int partition(int x[], int first, int last) {
    int pivot = x[first];
    int i = first + 1;
    int j = last;

    while (i <= j) {
        while (i <= j && x[i] <= pivot) i++;
        while (i <= j && x[j] > pivot) j--;

        if (i < j) {
            int temp = x[i];
            x[i] = x[j];
            x[j] = temp;
        }
    }

    int temp = x[first];
    x[first] = x[j];
    x[j] = temp;

    return j;
}
