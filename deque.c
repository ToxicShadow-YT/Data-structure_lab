#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int front, rear;
} Deque;

void initializeDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isFull(Deque *dq) {
    return ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1));
}

int isEmpty(Deque *dq) {
    return (dq->front == -1);
}

void insertFront(Deque *dq, int data) {
    if (isFull(dq)) {
        printf("Deque is full! Cannot insert at front.\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = data;
    printf("Inserted %d at the front.\n", data);
}

void insertRear(Deque *dq, int data) {
    if (isFull(dq)) {
        printf("Deque is full! Cannot insert at rear.\n");
        return;
    }
    if (dq->front == -1) { 
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = data;
    printf("Inserted %d at the rear.\n", data);
}

void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from front.\n");
        return;
    }
    printf("Deleted %d from the front.\n", dq->arr[dq->front]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty! Cannot delete from rear.\n");
        return;
    }
    printf("Deleted %d from the rear.\n", dq->arr[dq->rear]);
    if (dq->front == dq->rear) {
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear--;
    }
}

void displayDeque(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initializeDeque(&dq);

    int choice, data;
    while (1) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertFront(&dq, data);
                break;
            case 2:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                insertRear(&dq, data);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                displayDeque(&dq);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
