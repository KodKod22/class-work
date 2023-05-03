#include<stdio.h>
char isPalindromeInt(int a[], int n){
    if (n<=1)
    {
        return 'y';
    }
    if (a[0] != a[n-1])
    {
        return 'n';
    }
    return isPalindromeInt(a+1, n - 2);
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    char resolt=isPalindromeInt(a,n);
    if (resolt == 'y')
    {
        printf("polidrom");
    }else
    {
        printf("not polidrom");
    }
    return 0;
}