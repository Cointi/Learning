#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    float x1,y1,x2,y2,k,b;
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2 );
    k=(y2-y1)/(x2-x1);
    b=y1-k*x1;
    printf("%.2f %.2f",k,b);
    return 0;
}


