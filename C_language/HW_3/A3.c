#include <stdio.h>
#include <math.h>
#include <locale.h>
int main ()
{
    int a,b,c,sum;
    setlocale(LC_ALL,"Rus");

    scanf("%d %d %d", &a,&b,&c);
    sum=a+b+c;
    printf("%d+%d+%d=%d" , a, b, c, sum);
return 0;
    }
