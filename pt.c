#include<stdio.h>
int sumALL(int n){
    int sum=0;
    int curr=n;
    for (int i = 0; i < n; i++)
    {
        sum+=curr;
        curr+=n;
    }
    return sum;
}
int main(){ 
    int nlow;
    int nhigh;
    int sum;
    scanf("%d %d",&nlow,&nhigh);
    for (int n = nlow; n <= nhigh; n++)
    {
        sum+=sumALL(n);
    }
    printf("%d",sum);
    return 0;
}