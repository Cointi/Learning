
#include <stdio.h>

void function(int number)
    {
        int mas[9]={0};
        int val=0;
        int y=0;
        while(number>0)
            {
                val=number%10;
                mas[y]=val;
                number/=10;
                y++;

            }
        for(int j=y-1;j>=0;j--)
            {
                printf("%d ", mas[j]);
            }
    }


int main(int argc, char **argv)
{
    int N=0;
    scanf("%d", &N);
    function(N);
    return 0;
}
