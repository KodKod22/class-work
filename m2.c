#include<stdio.h>
int main(){
    int num1;
    int num2;
    int num3;
    printf("enter three numbers:");
    scanf("%d%d%d", &num1, &num2, &num3);
    if (num1 < num2 && num2 < num3){
        printf("%d",num2);
    }
    if (num1 < num3 && num3 < num2){
        printf("%d",num3);
    }
    if (num2 < num3 && num3 < num1)
    {
        printf("%d",num3);
    }
    if (num2 < num1 && num1 < num3)
    {
        printf("%d",num1);
    }
    if (num3 < num1 && num1 < num2)
    {
        printf("%d",num1);
    }
    if (num3 < num2 && num2 < num1)
    {
        printf("%d",num2);
    }
    return 0;
}