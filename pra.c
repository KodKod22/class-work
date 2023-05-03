#include<stdio.h>
int removeDuplicates(int* nums, int size)
{
    int arry2[size];
    int count=0;
    for (int i = 0; i < size; i++)
    {
        int dupla=0;
        for ( int j = 0; j < i; j++)
        {
            if (nums[i]==nums[j])
            {
                dupla=1;
                break;
            }
            
        }
        if(!dupla)
        {
            arry2[count]=nums[i];
            count++;
        }
        
    }
    for(int i=0;i<count;i++)
    {
        printf("%d ",arry2[i]);
    }
    
}
int main()
{
    int arry[]={3,2,2,9,2,1};
    int b=sizeof(arry)/sizeof(int);
    removeDuplicates(arry,b);
    return 0;
}

    