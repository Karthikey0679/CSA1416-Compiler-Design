
%{
#include<stdio.h>
%}
%%
[0-9]+ {printf("\n%s is number",yytext);}
[a-zA-Z][a-zA-Z0-9]* {printf("\n%s is word",yytext);}
%%
int yywrap(){}
int main()
{
printf("enter the statement\n");
yylex();
}