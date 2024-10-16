#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* Lchild, * Rchild;
};

struct node* root = NULL;

void insert();
void traversal();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);

int main() {
    int ch;
    do {
        printf("\nMenu\n1. Insertion\n2. Traversal\n3. Exit\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1: insert(); break;
        case 2: traversal(); break;
        default: break;
        }
    } while (ch != 3);
    return 0;
}

void traversal() {
    int ch;
    do {
        printf("\nMenu\n1. Inorder\n2. Preorder\n3. Postorder\n4. Exit\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1: inorder(root); break;
        case 2: preorder(root); break;
        case 3: postorder(root); break;
        default: break;
        }
    } while (ch != 4);
}

void insert() {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->Lchild = newNode->Rchild = NULL;

    if (root == NULL) {
        root = newNode;
    }
    else {
        struct node* ptr = root, * parent = NULL;
        while (ptr != NULL) {
            parent = ptr;
            if (newNode->data < ptr->data)
                ptr = ptr->Lchild;
            else if (newNode->data > ptr->data)
                ptr = ptr->Rchild;
            else {
                printf("Data already exists\n");
                free(newNode);
                return;
            }
        }
        if (newNode->data < parent->data)
            parent->Lchild = newNode;
        else
            parent->Rchild = newNode;
    }
}

void inorder(struct node* ptr) {
    if (ptr == NULL) {
        if (root == NULL) {
            printf("Tree is empty\n");
        }
        return;
    }
    inorder(ptr->Lchild);
    printf("%d\t", ptr->data);
    inorder(ptr->Rchild);
}

void preorder(struct node* ptr) {
    if (ptr == NULL) {
        if (root == NULL) {
            printf("Tree is empty\n");
        }
        return;
    }
    printf("%d\t", ptr->data);
    preorder(ptr->Lchild);
    preorder(ptr->Rchild);
}

void postorder(struct node* ptr) {
    if (ptr == NULL) {
        if (root == NULL) {
            printf("Tree is empty\n");
        }
        return;
    }
    postorder(ptr->Lchild);
    postorder(ptr->Rchild);
    printf("%d\t", ptr->data);
}
