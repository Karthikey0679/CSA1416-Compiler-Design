#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Structure to store an expression
struct Expression {
    char result[10];
    char arg1[10];
    char op[10];
    char arg2[10];
};

struct Expression expressions[MAX];
int expressionCount = 0;

void eliminateCommonSubexpressions();
void addExpression(char *result, char *arg1, char *op, char *arg2);
int isDuplicate(char *arg1, char *op, char *arg2, char *result);

int main() {
    char choice;

    printf("Enter expressions in the form result = arg1 op arg2\n");
    do {
        char result[10], arg1[10], op[10], arg2[10];
        printf("Enter expression: ");
        scanf("%s = %s %s %s", result, arg1, op, arg2);

        addExpression(result, arg1, op, arg2);

        printf("Do you want to enter another expression? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nBefore Optimization:\n");
    for (int i = 0; i < expressionCount; i++) {
        printf("%s = %s %s %s\n", expressions[i].result, expressions[i].arg1, expressions[i].op, expressions[i].arg2);
    }

    eliminateCommonSubexpressions();

    printf("\nAfter Optimization:\n");
    for (int i = 0; i < expressionCount; i++) {
        printf("%s = %s %s %s\n", expressions[i].result, expressions[i].arg1, expressions[i].op, expressions[i].arg2);
    }

    return 0;
}

void addExpression(char *result, char *arg1, char *op, char *arg2) {
    strcpy(expressions[expressionCount].result, result);
    strcpy(expressions[expressionCount].arg1, arg1);
    strcpy(expressions[expressionCount].op, op);
    strcpy(expressions[expressionCount].arg2, arg2);
    expressionCount++;
}

int isDuplicate(char *arg1, char *op, char *arg2, char *result) {
    for (int i = 0; i < expressionCount; i++) {
        if (strcmp(expressions[i].arg1, arg1) == 0 && strcmp(expressions[i].op, op) == 0 &&
            strcmp(expressions[i].arg2, arg2) == 0) {
            strcpy(result, expressions[i].result);
            return 1;
        }
    }
    return 0;
}

void eliminateCommonSubexpressions() {
    for (int i = 0; i < expressionCount; i++) {
        char duplicateResult[10];
        if (isDuplicate(expressions[i].arg1, expressions[i].op, expressions[i].arg2, duplicateResult)) {
            printf("Eliminating common subexpression: %s = %s %s %s\n", expressions[i].result, expressions[i].arg1, expressions[i].op, expressions[i].arg2);
            strcpy(expressions[i].arg1, duplicateResult);
            strcpy(expressions[i].op, "");
            strcpy(expressions[i].arg2, "");
        }
    }
}

