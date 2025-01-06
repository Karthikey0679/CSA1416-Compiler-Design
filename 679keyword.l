%{
%}
%%
"if"|"else"|"auto"|"break" {printf("\nit is an keyword\n");}
.+ {printf("\nit is an identifier\n");}
%%
int yywrap(void){}
int main()
{
printf("\nenter the word: \n");
yylex();
printf("\n");
return 0;
}