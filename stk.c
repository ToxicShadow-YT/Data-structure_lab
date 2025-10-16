#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;
void initStack(Stack* s) {
    s->top = NULL;
}

void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node* temp = s->top;
    int value = temp->data;
    s->top = temp->next;
    free(temp);
    return value;
}

int peek(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

void display(Stack* s) {
    Node* current = s->top;
    printf("Stack: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    display(&s);

    printf("Popped: %d\n", pop(&s));
    printf("Top element: %d\n", peek(&s));

    display(&s);

    return 0;
}