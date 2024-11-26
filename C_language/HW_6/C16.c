#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    int flag=0,i=1;
    while(n>i)
    {
        i++;
        if(i==n) break;
        if(n%i==0) flag=1;
    }
    if(flag==1 || n==1 || n==0)
    printf("NO");
    else
    printf("YES");

}

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    is_prime(n);
    return 0;
}