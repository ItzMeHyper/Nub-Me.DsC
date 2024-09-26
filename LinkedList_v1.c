#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void traverse(struct Node* head) {
    struct Node* ptr = head;
    int count=0;
    if (ptr == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
        count++;
    }
    printf("NULL\n");
    printf("Number of nodes: %d\n", count);
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* ptr = *head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = newNode;
}


void deleteNode(struct Node** head, int key) {
    struct Node* ptr = *head;
    struct Node* prev = NULL;

 if (ptr != NULL && ptr->data == key) {
        *head = ptr->link; 
        printf("Node with value %d deleted.\n", ptr->data);
        free(ptr);       
        return;
    }

    while (ptr != NULL && ptr->data != key) {
        prev = ptr;
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }

    prev->link = ptr->link;
    printf("Node with value %d deleted.\n", ptr->data); 
    free(ptr);
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n====Linked List Operations====:\n");
        printf("1. Insert at end\n");
        printf("2. Delete a node\n");
        printf("3. Traverse the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                printf("%d inserted.\n", value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 3:
                printf("Linked List: ");
                traverse(head);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
