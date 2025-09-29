#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full! Cannot enqueue.\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty! Cannot dequeue.\n");
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void isEmpty() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
}

void isFull() {
    if (rear == SIZE - 1) {
        printf("Queue is full\n");
    } else {
        printf("Queue is not full\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("5. Is Empty\n");
        printf("6. Is Full\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
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
                printf("Exiting...\n");
                exit(0);
            case 5:
                isEmpty();
                break;
            case 6:
                isFull();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}