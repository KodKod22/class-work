#include<stdio.h>
#define aa 100
#define bb 256
void charFrequency(char *s){
int index, freq[bb] = {0};
 for ( index = 0; s[index] != '\0'; index++)
    {
        freq[s[index]]=freq[s[index]]+1;
    }
    for ( index = 0; index < 256; index++)
    {
        if (freq[index]!=0)
        {
            printf("%c %d\n",index,freq[index]);
        }
        
    }
}
int main(){
    char string[aa];
    gets(string);
    charFrequency(string);
    return 0;
}