#include <stdio.h>
#include <math.h>
#include <locale.h>
int main ()
{
    int a,b,c,sum,pr;
    setlocale(LC_ALL,"Rus");
    scanf("%d %d %d", &a,&b,&c);
    sum=a+b+c;
    pr=a*b*c;
    printf("%d+%d+%d=%d\n" , a, b, c, sum);
    printf("%d*%d*%d=%d" , a, b, c, pr);
return 0;
    }
