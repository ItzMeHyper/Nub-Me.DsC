#include <stdio.h>
#include <stdlib.h>

int Q[100], i, front = -1, rear = -1, MAX, dlt;

void enqueue() {
    int value;
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        printf("Enter the value to be inserted: ");
        scanf("%d", &value);
        rear++;
        Q[rear] = value;
        printf("%d inserted onto the Queue\n", value);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue underflow\n");
    }
    else {
        dlt = Q[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
        printf("%d removed from the queue\n", dlt);
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++) {
            printf("%d  ", Q[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    printf("Enter the queue size: ");
    scanf("%d", &MAX);

    while (1) {
        printf("=================================\n");
        printf("         Queue Operations        \n");
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
            enqueue();
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
