#include <stdio.h>
#include <string.h>

int main()
{
    int num=0,res=1;
    long long int max=-2147483660;
    scanf("%d", &num);
    for(int i=0;i<num;i++)
    {

        int dig=0;
        scanf("%d", &dig);
        if(max<dig)
        {
            res=1;
            max=dig;
        }
        else if(max==dig)
        {
            res++;
        }
    }
    printf("%d", res);
    return 0;

}
