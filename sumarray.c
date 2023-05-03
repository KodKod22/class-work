#include<stdio.h>
int main(){
    int N,i;
    scanf("%d",&N);
    int a[N];
    for (i = 0; i < N; ++i)
    {
        scanf("%d",&a[i]);
    }
    int L;
    scanf("%d",&L);
    int sum, tempSum;
    int twleves ;
    for (int i = 0; i< N; i++)
    {
        if ( a[i] == L){
            twleves++;
            tempSum+=a[i];
            sum=tempSum;
        }
        if (a[i] != L && twleves > 0)
        {
            tempSum+=a[i];
        }
    }
    if (twleves == 1)
    {
         sum = 0;
    }
    printf("%d",sum);
    return 0;
}