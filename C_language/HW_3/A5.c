#include <stdio.h>
#include <locale.h>
#include <math.h>
int main ()
{
    float a,b,c, med;
    scanf("%f %f %f", &a,&b, &c);
    med=(a+b+c)/3;
    printf("%.2f", med);
    return 0;
    }
