#include <stdio.h>
#include <string.h>

// Function prototype
int isValidGrammar(const char *str, int start, int end);

int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    int length = strlen(input);

    if (isValidGrammar(input, 0, length - 1)) {
        printf("The string is valid according to the grammar.\n");
    } else {
        printf("The string is invalid according to the grammar.\n");
    }

    return 0;
}

// Recursive function to check grammar S -> aSb | e
int isValidGrammar(const char *str, int start, int end) {
    if (start > end) {
        // Base case: empty string (e)
        return 1;
    }

    if (str[start] == 'a' && str[end] == 'b') {
        // Recursive case: Check inner substring
        return isValidGrammar(str, start + 1, end - 1);
    }

    // If not matching grammar rules
    return 0;
}

