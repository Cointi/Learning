#include <stdio.h>
#include <math.h>

int is_happy_number(int n)
{
    int product=1,sum=0,r_digit;
    if (n==0) printf("YES");
    else
    {
        while(n>0)
        {
            r_digit=n%10;
            sum+=r_digit;
            product*=r_digit;
            n=n/10;
        }

    if (sum==product) printf("YES");
    else
        printf("NO");
    }
}
int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    is_happy_number(n);
    return 0;
}