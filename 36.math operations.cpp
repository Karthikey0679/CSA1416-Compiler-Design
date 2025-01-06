#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

// Function to evaluate expressions with operator precedence
float evaluateExpression(const char *expression);
float parseTerm(const char **expression);
float parseFactor(const char **expression);
float parseNumber(const char **expression);

int main() {
    char expression[100];

    printf("Enter a mathematical expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Evaluate the expression
    float result = evaluateExpression(expression);

    printf("Result: %.2f\n", result);

    return 0;
}

// Function to evaluate an expression with addition and subtraction
float evaluateExpression(const char *expression) {
    const char *current = expression;
    float result = parseTerm(&current);

    while (*current) {
        if (*current == '+') {
            current++;
            result += parseTerm(&current);
        } else if (*current == '-') {
            current++;
            result -= parseTerm(&current);
        } else {
            break;
        }
    }

    return result;
}

// Function to parse a term with multiplication and division
float parseTerm(const char **expression) {
    const char *current = *expression;
    float result = parseFactor(&current);

    while (*current) {
        if (*current == '*') {
            current++;
            result *= parseFactor(&current);
        } else if (*current == '/') {
            current++;
            float divisor = parseFactor(&current);
            if (divisor == 0) {
                printf("Error: Division by zero!\n");
                exit(1);
            }
            result /= divisor;
        } else {
            break;
        }
    }

    *expression = current;
    return result;
}

// Function to parse a factor with parentheses or numbers
float parseFactor(const char **expression) {
    const char *current = *expression;

    if (*current == '(') {
        current++;
        float result = evaluateExpression(current);
        if (*current == ')') {
            current++;
        } else {
            printf("Error: Mismatched parentheses!\n");
            exit(1);
        }
        *expression = current;
        return result;
    } else if (isdigit(*current) || *current == '.') {
        return parseNumber(expression);
    } else {
        printf("Error: Unexpected character '%c' in expression!\n", *current);
        exit(1);
    }
}

// Function to parse a number
float parseNumber(const char **expression) {
    char *end;
    float value = strtof(*expression, &end);
    *expression = end;
    return value;
}

