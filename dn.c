#include<stdio.h>
int first_digits(int first){
    while (first>10)
    {
        first=first/10;
    }
    return first;
}
int main(){
    int num1;
    int num2;
    int sum=0;
    scanf("%d%d",&num1,&num2);
    sum=first_digits(num1)+first_digits(num2);
    printf("%d",sum);
    return 0;
}