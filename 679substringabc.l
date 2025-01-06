
%{
#include <ctype.h>
%}
%%
[a-z] { printf("%c", toupper(yytext[0])); }
.|\n { printf("%s", yytext); }
%%
int yywrap(){}
int main() 
{
 printf("enter the string\n");
 yylex();
 return 0;
}