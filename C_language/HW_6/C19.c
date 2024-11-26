#include <stdio.h>
#include <math.h>

int digit_to_num(char c)
{
    int num;
    num = c-48;
    return num;
}
int main(int argc, char **argv)
{
    char c;
    int sum=0;
    while((c = getchar())!= '.')
    {
            if ((c>='0') && (c<='9'))
            sum=sum+(digit_to_num(c));

    }
    printf("%d ", sum);

    return 0;
}