#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int A1=0,A2=1,A3,i;
    int sum=1;
    for ( i = 1; i < N; i++)
    {   A3=A1+A2;
        A1=A2;
        A2=A3;
        sum=A3+sum;
    }
    printf("%d",sum);
    return 0;
}