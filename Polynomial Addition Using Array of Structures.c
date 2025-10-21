#include <stdio.h>

struct term {
    int coeff;
    int exp;
};

int main() {
    struct term p1[10], p2[10], result[20];
    int n1, n2, i, j, k = 0;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    printf("Enter coefficient and exponent for each term:\n");
    for (i = 0; i < n1; i++)
        scanf("%d%d", &p1[i].coeff, &p1[i].exp);

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    printf("Enter coefficient and exponent for each term:\n");
    for (i = 0; i < n2; i++)
        scanf("%d%d", &p2[i].coeff, &p2[i].exp);

    i = j = 0;
    while (i < n1 && j < n2) {
        if (p1[i].exp == p2[j].exp) {
            result[k].coeff = p1[i].coeff + p2[j].coeff;
            result[k].exp = p1[i].exp;
            i++; j++;
        } else if (p1[i].exp > p2[j].exp) {
            result[k] = p1[i++];
        } else {
            result[k] = p2[j++];
        }
        k++;
    }

    while (i < n1) result[k++] = p1[i++];
    while (j < n2) result[k++] = p2[j++];

    printf("\nResultant Polynomial: ");
    for (i = 0; i < k; i++) {
        printf("%dx^%d", result[i].coeff, result[i].exp);
        if (i != k - 1) printf(" + ");
    }
    return 0;
}
