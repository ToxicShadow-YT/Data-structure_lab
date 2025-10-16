#include <stdio.h>
#include <stdlib.h>


typedef struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode* next;
} PolyNode;


PolyNode* createNode(int coeff, int exp) {
    PolyNode* node = (PolyNode*)malloc(sizeof(PolyNode));
    node->coeff = coeff;
    node->exp = exp;
    node->next = NULL;
    return node;
}

void insertTerm(PolyNode** head, int coeff, int exp) {
    if (coeff == 0) return;
    PolyNode *prev = NULL, *curr = *head;
    while (curr && curr->exp > exp) {
        prev = curr;
        curr = curr->next;
    }
    if (curr && curr->exp == exp) {
        curr->coeff += coeff;
        if (curr->coeff == 0) { 
            if (prev) prev->next = curr->next;
            else *head = curr->next;
            free(curr);
        }
    } else {
        PolyNode* node = createNode(coeff, exp);
        node->next = curr;
        if (prev) prev->next = node;
        else *head = node;
    }
}


PolyNode* multiplyPoly(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;
    for (PolyNode* p1 = poly1; p1; p1 = p1->next) {
        for (PolyNode* p2 = poly2; p2; p2 = p2->next) {
            insertTerm(&result, p1->coeff * p2->coeff, p1->exp + p2->exp);
        }
    }
    return result;
}

void printPoly(PolyNode* head) {
    if (!head) {
        printf("0\n");
        return;
    }
    PolyNode* curr = head;
    while (curr) {
        printf("%dx^%d", curr->coeff, curr->exp);
        if (curr->next && curr->next->coeff > 0) printf(" + ");
        else if (curr->next && curr->next->coeff < 0) printf(" - ");
        curr = curr->next;
    }
    printf("\n");
}


void freePoly(PolyNode* head) {
    while (head) {
        PolyNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    PolyNode* poly1 = NULL;
    PolyNode* poly2 = NULL;

    
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 2, 1);
    insertTerm(&poly1, 1, 0);

    insertTerm(&poly2, 2, 1);
    insertTerm(&poly2, 4, 0);

    printf("Polynomial 1: ");
    printPoly(poly1);
    printf("Polynomial 2: ");
    printPoly(poly2);

    PolyNode* result = multiplyPoly(poly1, poly2);
    printf("Product: ");
    printPoly(result);

    freePoly(poly1);
    freePoly(poly2);
    freePoly(result);
    return 0;
}