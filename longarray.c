#include<stdio.h>
int long_array(int a[],int n1){
int i,line=0,old_line=0;
    for ( i = 0; i < n1; i++)
    {
      if (a[i]<a[i+1])
      {
        line++;
        i=i+2;
       } else if (a[i]>a[i+1])
      {
        old_line=line;
        i=i+2;
        line=0;
      }else if(a[i]=a[i+1]){
      i=i+2;
      }
      }    
    return line+2;
}
int main(){
    int n1;
    scanf("%d",&n1);
    int a[n1];
    int i;
    for (i = 0; i < n1; i++)
    {
    scanf("%d",&a[i]);
    }
    printf("%d",long_array(a,i));
}