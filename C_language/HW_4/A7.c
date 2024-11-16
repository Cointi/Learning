#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(int argc, char **argv)
{
    int a,b;
   // printf("¬ведите массив чисел: \n");
    scanf("%d %d" , &a, &b);
    if(a>b) printf("%d", a);
    else printf("%d", b);
    return 0;
}

