#include <stdio.h>
int main ()
{
double a, b, area, perimeter;
printf("enter two numbers: ");
scanf("%lf %lf", &a, &b);
area = a * b;
perimeter = 2 * (a + b);
printf("area = %.2f\n",area);
printf("perimeter = %.2f",perimeter);
    return 0;
}