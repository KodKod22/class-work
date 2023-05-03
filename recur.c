#include<stdio.h>
//a=rmul(x-1,y)
//b=y+rmul(x-1,y)
//c=x=1->y
/*long rMull(int x,int y){
if (x==1)
{
    return y;
}else
{
    return y+rMull(x-1,y);
}
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",rMull(a,b));
    return 0;
}*/
//a=sumlng(a,n-1,min)
//b=sumlrg(a,n,min)=sumlrg(a,n-1,min)+(a[n-1]>min?a[n-1])
//c=n=0=>0
/*int sumlrg(int a[],int n,int min){
    if (n==0)
    {
        return 0;
    }
    else
    {
        int oldsum=sumlrg(a,n-1,min);
        if (a[n-1>min])
        {
            oldsum+=a[n-1];
        }
        return oldsum;
    }
    
}
int main(){
int n;
scanf("%d",&n);
int min;
scanf("%d",&min);
int a[n];
for (int i = 0; i < n; i++)
{
    scanf("%d",&a[i]);
}
printf("%d",sumlrg(a,n,min));

}*/
//a=sumofdigits(n/10)
//b=sumofdigits(n)=sumofdigits(n/10)+n%10
//c=n=0=>0
/*int sumofDigits(unsigned long n){
    if (n==0)
    {
        return 0;
    }else
    {
        return n%10+sumofDigits(n/10);
    }
}
int main(){
    int n;
scanf("%d",&n);
printf("%d",sumofDigits(n));
}*/
int upnumber(int a){
    if (a<10)
    {
        return 1;
    }
    if (a%10<a/10%10)
    {
        return 0;
    }
    return upnumber(a/10);
}
int main(){
    int n,a;
    scanf("%d",&n);
    a=upnumber(n);
    if (a==1){
        printf("yes");
    }else
    {
        printf("no");
    }
    
}