#include<stdio.h>
int findInsPoint(int *arr, int t, int p)
{
for (int i=0 ; i<=p ; ++i)
    if (*(arr+i)<t)
    return i ;
    return p+1 ;
}
void shiftArray( int *s, int *e)
{
    while (e>=s)
    {
        *(e+1)=*e;
        --e;
    } 
}
void insertionSortDown( int arr[], int n )
{
for (int p=0 ; p<(n-1) ; ++p)
{
    int temp = *(arr+p+1);
    int ins = findInsPoint(arr, temp, p);
    shiftArray(arr+ins, arr+p);
    *(arr+ins)= temp; 
}
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    insertionSortDown(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}