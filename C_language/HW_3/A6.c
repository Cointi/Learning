#include <stdio.h>
#include <math.h>
#include <locale.h>
int main ()
{
    int a,b,dif;
    setlocale(LC_ALL,"Rus");
    scanf("%d %d", &a,&b);
    dif=a-b;
    printf("%d" , dif);
return 0;
    }
