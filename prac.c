#include<stdio.h>
int sum_allDgits(int n){
    int sum=0;
    int num;
    while (n>0)
    {
        num=n%10;
        sum=sum+num;
        n=n/10;
    }
    return sum;
}
int main(){
    int N1;
    int N2;
    scanf("%d %d",&N1,&N2);
    int a=sum_allDgits(N1)%sum_allDgits(N2);
    if (a==0)
    {
    printf("Divides");
    }
    else{
    printf("Not Divides");
    }
}