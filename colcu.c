#include<stdio.h>
int main(){
int number1;
int number2;
int c = 0;
char op;
scanf("%d %c %d",&number1,&op,&number2);
switch (op)
{
case '+':
    c=number1+number2;
    printf("%d",c);
    break;

case '-':
   c=number1-number2;
   printf("%d",c);
   break;
 case '*':
 c=number1*number2;
 printf("%d",c);
 break;
 case '/':
 if (number2==0)
 {
    printf("erro");
 }
 else
 {
    c=number1/number2;
    printf("%d",c);
 }
   break;
}
return 0;
}