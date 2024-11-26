#include <stdio.h>
#include <math.h>

int is_digit(char c)
{
    int flag=0;
    if ((c>='0') && (c<='9'))
            flag=1;

    return flag;
}
int main(int argc, char **argv)
{
    char c;
    int cnt=0;
    while((c = getchar())!= '.')
    {
        if (is_digit(c) == 1)
            cnt++;
    }

    printf("%d", cnt);
    return 0;
}