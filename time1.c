#include<stdio.h>
int main()
{
    int H1, M1, S1;
    int H2, M2, S2;
    int H3, M3, S3;
    printf("ENTER HOURS,MINETS,SECENDS: \n");
    scanf("%d %d %d",&H1,&M1,&S1);
    printf("ENTER YOUR GAP TIME:");
    scanf("%d %d %d",&H2,&M2,&S2);
    H3=M3=S3=0;
    S3=S1+S2;
    if (S3>=60)
    {
        S3=S3-60;
        M3=M3+1;
    }
    M3=M1+M2;
    if (M3>=60)
    {
        M3=M3-60;
        H3=H3+1;
    }
    H3=H1+H2;
    if (H3>=24)
    {
        H3=H3-24;
    }
    printf("your new time:%d:%d:%d",H3,M3,S3);
    
}