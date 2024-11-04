#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,d,res;
    int sum=0;
    int i=0;
   // printf("Enter  number: ");
    scanf("%d", &a );
    d=a;
    while(d>0)
    {
        d=d/10;
        i++;
    }
    for (int j=0;j<i;j++)
    {
        res=a%10;
        a=a/10;
        sum+=res;
    }
    printf("%d", sum);
    return 0;
}
