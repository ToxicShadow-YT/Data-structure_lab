#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* insertFront(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head) head->prev = newNode;
    return newNode;
}

Node* insertEnd(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (!head) {
        newNode->prev = NULL;
        return newNode;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* deleteNode(Node* head, int key) {
    Node* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) return head;
    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
    return head;
}


void displayForward(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward(Node* head) {
    Node* temp = head;
    if (!temp) return;
    while (temp->next) temp = temp->next;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main(){
    int choice,value,position;
    Node* head = NULL;
    do {
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node by Value\n");
        printf("4. Display List Forward\n");
        printf("5. Display List Backward\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertFront(head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;
            case 4:
                displayForward(head);
                break;
            case 5:
                displayBackward(head);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0); 
    freeList(head);
    return 0;
}