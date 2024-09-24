#include <stdio.h>
#include <string.h>
#include <ctype.h>

void push(char);
char pop();
int precedence(char);

int top = -1, j = 0, i;
char inf[50], pos[50], stack[50];

void main() {
    printf("Enter the expression: ");
    scanf("%s", inf);
    printf("Infix expression: %s\n", inf);

    int n = strlen(inf);
    for (i = 0; i < n; i++) {
        if (isalnum(inf[i])) {
            pos[j] = inf[i];
            j++;
        } else if (inf[i] == '(') {
            push(inf[i]);
        } else if (inf[i] == ')') {
            while (stack[top] != '(') {
                pos[j] = pop();
                j++;
            }
            pop();
        } else {
            while ((top != -1) && (precedence(inf[i]) <= precedence(stack[top]))) {
                pos[j] = pop();
                j++;
            }
            push(inf[i]);
        }
    }
    
    while (top != -1) {
        pos[j] = pop();
        j++;
    }
    
    pos[j] = '\0';
    printf("Postfix Expression is: %s\n", pos);
}

void push(char item) {
    top++;
    stack[top] = item;
}

char pop() {
    char item;
    item = stack[top];
    top--;
    return item;
}

int precedence(char x) {
    switch (x) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}