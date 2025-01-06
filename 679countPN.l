%{
#include <stdio.h>

int positive_count = 0;
int negative_count = 0;
%}

%%
[+]?[0-9]+  { positive_count++; }
[-][0-9]+  { negative_count++; }

%%
int yywrap(){}
int main() {

    yylex();
    printf("Positive numbers: %d\n", positive_count);
    printf("Negative numbers: %d\n", negative_count);
    return 0;
}