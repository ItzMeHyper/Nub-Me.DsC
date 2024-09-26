#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->link = *head;
    *head = newNode;
}

void insertRan(struct Node** head, int data) {
    int pos, i = 1;
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    printf("Enter the position after which you want to insert the value: ");
    scanf("%d", &pos);

    if (pos == 0) {  // insert at the beginning
        insertFront(head, data);
        return;
    }

    while (i < pos && temp != NULL) {
        temp = temp->link;
        i++;
    }

    if (temp == NULL) {  // Insert at the end if position is out of bounds
        temp = *head;
        while (temp && temp->link != NULL) {
            temp = temp->link;
        }
        if (temp) {
            temp->link = newNode;  // Insert at the end
        } else {
            *head = newNode;  // If the list was empty
        }
    } else {
        newNode->link = temp->link;
        temp->link = newNode;
    }
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

void deleteFront(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->link;
    printf("Node with value %d deleted from the beginning.\n", temp->data);
    free(temp);
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

void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp->link == NULL) {  // Only one node in the list
        printf("Node with value %d deleted from the end.\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->link != NULL) {
        prev = temp;
        temp = temp->link;
    }

    prev->link = NULL;
    printf("Node with value %d deleted from the end.\n", temp->data);
    free(temp);
}

void traverse(struct Node* head) {
    struct Node* ptr = head;
    int count = 0;
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

void clearList(struct Node** head) {
    struct Node* current = *head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->link;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n=====Linked List Operations=====:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at a random space\n");
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
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertFront(&head, value);
            printf("%d inserted.\n", value);
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertRan(&head, value);
            printf("%d inserted.\n", value);
            break;
        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertEnd(&head, value);
            printf("%d inserted.\n", value);
            break;
        case 4:
            deleteFront(&head);
            break;
        case 5:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(&head, value);
            break;
        case 6:
            deleteEnd(&head);
            break;
        case 7:
            printf("Linked List: ");
            traverse(head);
            break;
        case 8:
            clearList(&head);
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
