#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue {
    struct Node** arr;
    int front, rear, size;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->size = size;
    q->front = q->rear = -1;
    q->arr = (struct Node**)malloc(size * sizeof(struct Node*));
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == q->size - 1)
        return;
    if (isEmpty(q))
        q->front = 0;
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q))
        return NULL;
    struct Node* node = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return node;
}

struct Node* insertNode() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1)
        return NULL;
    struct Node* newNode = createNode(data);
    printf("Enter left child of %d:\n", data);
    newNode->left = insertNode();
    printf("Enter right child of %d:\n", data);
    newNode->right = insertNode();
    return newNode;
}

void levelOrder(struct Node* root) {
    if (root == NULL)
        return;
    struct Queue* q = createQueue(100);
    enqueue(q, root);
    printf("\nBFS: ");
    while (!isEmpty(q)) {
        struct Node* current = dequeue(q);
        printf("%d ", current->data);
        if (current->left)
            enqueue(q, current->left);
        if (current->right)
            enqueue(q, current->right);
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    printf("Create the binary tree:\n");
    root = insertNode();
    levelOrder(root);
    return 0;
}
