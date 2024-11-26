#include <stdio.h>
#include <math.h>

int grow_up(int n)
{
    int b=0,c=0,d=0;
    while(n>0)
    {
        b=n%10;
        c=n/10;
        while (c>0)
            {
                d=c%10;
                if(b<=d)
                {
                    printf("NO");
                    return 0;
                }
                    c=c/10;
            }
        n=n/10;
    }
    printf("YES");
}
int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    grow_up(n);

return 0;
}