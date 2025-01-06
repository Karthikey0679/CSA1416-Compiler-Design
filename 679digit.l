%{
%}
%%
[0-9]+ {printf("\nit is a digit\n");}
.+ {printf("\nnot a digit\n");}
%%
int yywrap(void){}
int main()
{
printf("\nenter a digit:");
yylex();
printf("\n");
return 0;
}