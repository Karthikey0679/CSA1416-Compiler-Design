%option noyywrap
%{
#include<stdio.h>
#include<stdlib.h>
%}
%%
[a-zA-ZA0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA.Z]{2,4} printf("%s is a valid email address.\n",yytext);
.printf("%s is not a valid email address.\n",yytext);
%%

int main(void){
    printf("enter an email address: ");
    yylex();
    return 0;
}