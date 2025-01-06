
%{
%}
%%
[0-9]|[.0-9]+ {printf("given is a constant");}
.+ {printf("not a constant");}
%%
int yywrap() {}
int main()
{
printf("enter input");
yylex();
}