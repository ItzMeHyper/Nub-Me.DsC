#include <stdio.h>
#include <stdlib.h>

struct node {
    int coef;
    int expo;
    struct node* link;
};
struct node* createNode(int coef, int expo) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coef = coef;
    newNode->expo = expo;
    newNode->link = NULL;
    return newNode;
}
void printPolynomial(struct node* head) {
    struct node* p = head;
    while (p != NULL) {
        if (p->link == NULL) {
            printf("(%dX^%d)", p->coef, p->expo);
        } else {
            printf("(%dX^%d) + ", p->coef, p->expo);
        }
        p = p->link;
    }
    printf("\n");
}
int main() {
    int no1, no2, i, coef1, expo1;
    struct node* rhead = NULL;
    struct node* phead = NULL;
    struct node* qhead = NULL;
    struct node* r = NULL;
    struct node* p = NULL;
    struct node* q = NULL;

    // Input first polynomial
    printf("Enter the number of terms in polynomial 1: ");
    scanf("%d", &no1);
    if (no1 != 0) {
        printf("Enter the terms of the 1st polynomial in descending order:\n");
        for (i = 0; i < no1; i++) {
            printf("Enter the coefficient of term %d: ", i + 1);
            scanf("%d", &coef1);
            printf("Exponent of term %d: ", i + 1);
            scanf("%d", &expo1);
            struct node* temp = createNode(coef1, expo1);
            if (phead == NULL) {
                phead = temp;
                p = temp;
            } else {
                p->link = temp;
                p = temp;
            }
        }
    }
    printf("First Polynomial: ");
    printPolynomial(phead);

    // Input second polynomial
    printf("Enter the number of terms in polynomial 2: ");
    scanf("%d", &no2);
    if (no2 != 0) {
        printf("Enter the terms of the 2nd polynomial in descending order:\n");
        for (i = 0; i < no2; i++) {
            printf("Enter the coefficient of term %d: ", i + 1);
            scanf("%d", &coef1);
            printf("Exponent of term %d: ", i + 1);
            scanf("%d", &expo1);
            struct node* temp = createNode(coef1, expo1);
            if (qhead == NULL) {
                qhead = temp;
                q = temp;
            } else {
                q->link = temp;
                q = temp;
            }
        }
    }
    printf("Second Polynomial: ");
    printPolynomial(qhead);

    // Add the two polynomials
    p = phead;
    q = qhead;

    while (p != NULL || q != NULL) {
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        if (p != NULL && (q == NULL || p->expo > q->expo)) {
            temp->coef = p->coef;
            temp->expo = p->expo;
            p = p->link;
        } else if (q != NULL && (p == NULL || q->expo > p->expo)) {
            temp->coef = q->coef;
            temp->expo = q->expo;
            q = q->link;
        } else {
            temp->coef = p->coef + q->coef;
            temp->expo = p->expo;
            p = p->link;
            q = q->link;
        }
        temp->link = NULL;
        if (rhead == NULL) {
            rhead = temp;
            r = temp;
        } else {
            r->link = temp;
            r = temp;
        }
    }

    printf("Resultant Polynomial: ");
    printPolynomial(rhead);
    
    return 0;
}
