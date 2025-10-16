#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(Node** poly, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        Node* curr = *poly;
        while (curr->next && curr->next->exp > exp)
            curr = curr->next;
        if (curr->next && curr->next->exp == exp) {
            curr->next->coeff += coeff;
            free(newNode);
        } else {
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
}

Node* addPoly(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node *p1 = poly1, *p2 = poly2;
    while (p1 && p2) {
        if (p1->exp > p2->exp) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            insertTerm(&result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1) {
        insertTerm(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2) {
        insertTerm(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}


void displayPoly(Node* poly) {
    while (poly) {
        printf("%dx^%d", poly->coeff, poly->exp);
        if (poly->next && poly->next->coeff >= 0)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;

    
    insertTerm(&poly1, 3, 3);
    insertTerm(&poly1, 2, 2);
    insertTerm(&poly1, 1, 0);

    insertTerm(&poly2, 4, 2);
    insertTerm(&poly2, 2, 1);
    insertTerm(&poly2, 5, 0);

    printf("Polynomial 1: ");
    displayPoly(poly1);

    printf("Polynomial 2: ");
    displayPoly(poly2);

    sum = addPoly(poly1, poly2);

    printf("Sum: ");
    displayPoly(sum);

   
    return 0;
}