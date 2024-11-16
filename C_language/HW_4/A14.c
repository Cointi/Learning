#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,max;
    scanf("%d", &a );
    d=a%10;
    c=(a%100)/10;
    b=(a%1000)/100;
    max=(b>c)?b:c;
    max=(max>d)?max:d;
    printf("%d",max);
    return 0;
}
