#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,d,res;
    int product=1;
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
        product*=res;
    }
    printf("%d", product);
    return 0;
}
