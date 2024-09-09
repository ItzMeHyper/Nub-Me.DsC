#include <stdio.h>
#include <stdlib.h>

int Q[100], i, front = -1, rear = -1, MAX, dlt;

void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Circular Queue overflow\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        Q[rear] = value;
        printf("%d inserted into the queue\n", value);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Circular Queue underflow\n");
    } else {
        dlt = Q[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        printf("%d removed from the queue\n", dlt);
    }
}

void display() {
    if (front == -1) {
        printf("Circular Queue is empty\n");
    } else {
        printf("Circular Queue elements are:\n");
        for (i = front; i != rear; i = (i + 1) % MAX) {
            printf("%d  ", Q[i]);
        }
        printf("%d  ", Q[rear]);  // Print the last element
        printf("\n");
    }
}

int main() {
    int choice, value;

    printf("Enter the queue size: ");
    scanf("%d", &MAX);

    while (1) {
        printf("=================================\n");
        printf("    Circular Queue Operations    \n");
        printf("=================================\n");
        printf("---------------\n");
        printf("|1.| Enqueue  |\n");
        printf("|2.| Dequeue  |\n");
        printf("|3.| Display  |\n");
        printf("|4.| Exit     |\n");
        printf("---------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
