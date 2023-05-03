#include<stdio.h>
int main(){
    int n;
    int i=0; 
    int inc=1;
    scanf("%d",&n);
    for (int k = 0; k < 2*n+1; k++)
    {
        for (int j = 0; j < n-i; j++)
        {
            printf(" ");
        }
        for (int j = i;j>=0; j--)
        {
            printf("%d",j);
        }
        for ( int j = 1; j <= i; j++)
        {
            printf("%d",j);
        }
        printf("\n");
        if (i==n)
        {
            inc=-1;
        }
        i+=inc;
        
    }
    return 0;
    
}