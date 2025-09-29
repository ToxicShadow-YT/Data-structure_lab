#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Stack;


void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

int evaluatePostfix(char *expression) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

      
        if (isdigit(ch)) {
            push(&stack, ch - '0');
        }
    
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (ch) {
                case '+': push(&stack, operand1 + operand2); break;
                case '-': push(&stack, operand1 - operand2); break;
                case '*': push(&stack, operand1 * operand2); break;
                case '/': 
                    if (operand2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    push(&stack, operand1 / operand2); 
                    break;
                case '^': push(&stack, pow(operand1, operand2)); break;
                default: 
                    printf("Invalid operator encountered\n");
                    exit(1);
            }
        }
    }

   
    return pop(&stack);
}

int main() {
    char expression[MAX];

    printf("Enter a postfix expression (e.g., 23*54*+): ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("The result of the postfix evaluation is: %d\n", result);

    return 0;
}
