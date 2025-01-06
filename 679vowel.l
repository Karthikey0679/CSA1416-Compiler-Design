%{
int vowel=0;
int consonent=0;
%}
%%
[aeiouAEIOU] {vowel++;}
[a-zA-Z] {consonent++;}
%%
int yywrap(){}
int main()
{
printf("enter the string of vowels and consonents:");
yylex();
printf("number of vowels are:%d\n",vowel);
printf("number of consonents are:%d\n",consonent);
return 0;
}