
%{
#include<stdio.h>
 int vow_count=0;
 int const_count =0;
%}
%%
[aeiouAEIOU] {vow_count++;}
[a-zA-Z] {const_count++;}
%%

int yywrap()
{}
int main()
{

 yylex();
 printf("Number of vowels are: %d\n", vow_count);
 printf("Number of consonants are: %d\n", const_count);
 return 0;
}