#include<stdio.h>
void swap(int *c, int *g){
    int tamp=*c;
    *c=*g;
    *g=tamp;
}
int findMinIndex(int *arr,int p,int last){
    int r;
    int min = *(arr+(r=p));
    while (++p<=last)
        if (*(arr+p)>min)
        min = *(arr+(r=p));
    
    return r;
}
void selectionSortDown(int arr[], int n){
for (int pivot=0 ; pivot < (n-1) ; ++pivot) 
{
    int m = findMinIndex( arr,pivot,n-1 );
    swap( arr+pivot, arr+m );
}
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    selectionSortDown(a,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}