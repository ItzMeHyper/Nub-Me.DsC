#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* link;
} *head = NULL;

void insertFront() {
    int item;
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value to insert: ");
    scanf("%d", &item);
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return; 
    }
    temp->data = item;
    temp->link = head;
    head = temp;
    printf("%d inserted at the front.\n", item);
}

void insertRandom() {
    int item, key;
    struct Node* temp, * ptr;
    if (head == NULL) {
        insertFront();
    } else {
        printf("Enter value to insert: ");
        scanf("%d", &item);
        temp = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the value after which you want to insert the new value: ");
        scanf("%d", &key);
        ptr = head;
        while (ptr != NULL && ptr->data != key) {
            ptr = ptr->link;
        }
        if (ptr == NULL) {
            printf("Key %d not found in the list. Insertion failed.\n", key);
            free(temp);
        } else {
            temp->data = item;
            temp->link = ptr->link;
            ptr->link = temp;
            printf("%d inserted after %d.\n", item, key);
        }
    }
}

void insertEnd() {
    int item;
    struct Node* temp, * ptr;
    if (head == NULL) {
        insertFront();
    } else {
        printf("Enter value to insert: ");
        scanf("%d", &item);
        temp = (struct Node*)malloc(sizeof(struct Node));
        ptr = head;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = temp;
        temp->data = item;
        temp->link = NULL;
        printf("%d inserted at the end.\n", item);
    }
}

void deleteFront() {
    struct Node* ptr;
    if (head == NULL)
        printf("The list is empty.\n");
    else {
        ptr = head;
        head = ptr->link;
        printf("Node with value %d deleted from the beginning.\n", ptr->data);
        free(ptr);
    }
}

void deleteRandom() {
    struct Node* ptr, * temp;
    int key;
    printf("Enter value to delete: ");
    scanf("%d", &key);
    if (head == NULL) {
        printf("The list is empty.\n");
    } else if (head->link == NULL) {
        deleteFront();
        head = NULL;
    } else if (head->data == key) {
        deleteFront();
    } else {
        temp = head;
        ptr = temp->link;
        while (ptr != NULL && ptr->data != key) {
            temp = ptr;
            ptr = ptr->link;
        }
        if (ptr == NULL) {
            printf("Key %d not found in the list.\n", key);
        } else {
            temp->link = ptr->link;
            printf("Node with value %d deleted.\n", ptr->data);
            free(ptr);
        }
    }
}

void deleteEnd() {
    struct Node* temp, * ptr;
    if (head == NULL) {
        printf("The list is empty.\n");
    } else if (head->link == NULL) {
        ptr = head;
        head = NULL;
        printf("Node with value %d deleted from the end.\n", ptr->data);
        free(ptr);
    } else {
        ptr = head;
        temp = head->link;
        while (temp->link != NULL) {
            ptr = temp;
            temp = temp->link;
        }
        ptr->link = NULL;
        printf("Node with value %d deleted from the end.\n", temp->data);
        free(temp);
    }
}

void traverse() {
    struct Node* ptr = head;
    int count = 0;

    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        printf("Linked list: ");
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->link;
            count++;
        }
        printf("NULL\n");
        printf("Number of nodes: %d\n", count);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n=====Linked List Operations=====:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert after a specific node\n");
        printf("3. Insert at end\n");
        printf("4. Delete from front\n");
        printf("5. Delete from random\n");
        printf("6. Delete from end\n");
        printf("7. Traverse/Display the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insertFront();
            break;
        case 2:
            insertRandom();
            break;
        case 3:
            insertEnd();
            break;
        case 4:
            deleteFront();
            break;
        case 5:
            deleteRandom();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            traverse();
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
