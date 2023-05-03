#include<stdio.h>
#include<math.h>
int N;
int digits(int n){
int e=0;
int num;
e=(num==0)?1:log10(N)+1;
return e;
}
int power(int n,int e){
    while (e>0)
    {
        N=N*N;
        e--;
    }
    return N;
    
}
int main(){
    int res;
    scanf("%d",&N);
   while(N>0){
      res += power((N%10),digits(N));
      N /= 10;
   }
   if (N == res){
      printf("Armstrong");
   }
   else{
      printf( "Not Armstrong");
   }
   return 0;
}