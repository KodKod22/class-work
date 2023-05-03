#include<stdio.h>
int my_strcmp(char *s,char *t){
    int flag=0;
    while (*s != '\0' && *t != '\0')
    {
        if (*s > *t)
        {
            flag=1;
        }else if (*s < *t)
        {
            flag=-1;
        }
        
        s++;
        t++;
    }
    if (flag==0)
    {
        return 0;
    }
    else if(flag>0)
    {
        return 1;
    }else
    {
        return -1;
    }
}
int main(void){
    
    char s1[100];
    char s2[100];
    gets(s1);
    gets(s2);
    printf("%d",my_strcmp(s1,s2));
    return 0;
}