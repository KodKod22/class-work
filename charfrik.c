#include<stdio.h>
void swap(int *c, int *g){
    int tamp=*c;
    *c=*g;
    *g=tamp;
}
void bubbleSortDown(int arr[], int b){
    int x,y;
    for ( x = 0; x < b-1; x++)
    {
        for ( y = 0; y <b-x-1 ; y++)
        {
            if (*(arr+y)<*(arr+y+1))
            {
                swap(arr+y,arr+y+1);
            }
            
        }
        
    }
    
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    int arr[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    bubbleSortDown(arr,n);
    for ( i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0; 
}