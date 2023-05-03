#include <stdio.h>
int main ()
{
    int a; //full number
    int b; //numerator
    int c; // denominator
    printf("enter full number: ");
    scanf("%d", &a);
    printf("enter a numerator:");
    scanf("%d", &b);
    printf("enter a denominator:");
    scanf("%d", &c);
    float z = ((float)(c * a) + b) / c;
    printf("z = %.6f",z);
    return 0;



}