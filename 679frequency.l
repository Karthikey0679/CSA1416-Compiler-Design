%{
#include<stdio.h>
#include<string.h>
 
char word [] = "digit";
int count = 0;
 
 
%}
%%
[a-zA-Z]+    { if(strcmp(yytext, word)==0)
                   count++; }
.  ;         
%%
 
 
int yywrap()
{
    return 1;
}
 
/* code section */
int main()
{
        extern FILE *yyin, *yyout;
        yyin=fopen("digit.l.txt", "r");
        yylex();
          
        printf("%d", count);
     
}