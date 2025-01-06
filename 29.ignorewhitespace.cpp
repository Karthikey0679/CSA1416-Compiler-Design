#include<stdio.h>
    #include<ctype.h>
    int main(void){
      char str[1000];
      int x,lowerCase,upperCase,digit,specialCharacter,total;
      printf("Enter a string: ");
      gets(str);
      x = lowerCase = upperCase = digit = specialCharacter = total =0;
      for(;str[x]!='\0';x++){
        if(str[x] >= 'A' && str[x] <='Z') upperCase++;
        else if(str[x] >= 'a' && str[x] <='z') lowerCase++;
        else if(str[x] >= '0' && str[x] <='9') digit++;
        else if(str[x] == '\n' || str[x] == '\t' || str[x] == ' '){}
        else specialCharacter++;
      }
      total = lowerCase + upperCase + digit + specialCharacter;
      printf("lowercase= %d , uppercase=%d , digit=%d , special=%d \n", lowerCase,upperCase,digit,specialCharacter );
      printf("tatal :%d",total);
      return 0;
    }
