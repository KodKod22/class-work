#include<stdio.h>
int *subArray( int *a, int n1, int *b, int n2)
{
    int d=0 ;int i=0; int conter=0;
    while(conter!=n2)
    {
        if (d == n1)
        {
            return NULL;
        }else if (*(a+d) == *(b+i))
        {
            conter++;
            d++;
            i++;
        }else{
            conter=0;
            d=d-i+1;
            i=0;
        }
    } return a+(d-n2);
}          
int main(){
    int n1;
    int i,j;
    scanf("%d",&n1);
    int a[n1];
    for (i = 0; i < n1; i++)
    {
        scanf("%d",&a[i]);
    }
    int n2;
    scanf("%d",&n2);
    int b[n2];
    for (j = 0; j < n2; j++)
    {
        scanf("%d",&b[j]);
    }
    int *c=subArray(a,n1,b,n2);
    if (c==NULL)
    {
        printf("-1");
    }else
    {
        printf("%d",(int)(c-a));
    }
    return 0;
}