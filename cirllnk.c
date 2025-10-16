#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* rear;
} CircularQueue;


void initQueue(CircularQueue* q) {
    q->rear = NULL;
}

void enqueue(CircularQueue* q, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    if (!q->rear) {
        temp->next = temp;
        q->rear = temp;
    } else {
        temp->next = q->rear->next;
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(CircularQueue* q) {
    if (!q->rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    Node* front = q->rear->next;
    int value = front->data;
    if (front == q->rear) {
        q->rear = NULL;
    } else {
        q->rear->next = front->next;
    }
    free(front);
    return value;
}

void display(CircularQueue* q) {
    if (!q->rear) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->rear->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->rear->next);
    printf("\n");
}
void isEmpty(CircularQueue* q) {
    if (q->rear == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
}
void isfull(CircularQueue* q) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Queue is full\n");
    } else {
        printf("Queue is not full\n");
        free(temp);
    }
}

int main() {
    CircularQueue q;
    initQueue(&q);
    int choice, value;
    while (1) {
        printf("\n------Circular Queue Operations----------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Check if Empty\n");
        printf("5. Check if Full\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                isEmpty(&q);
                break;
            case 5:
                isfull(&q);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}