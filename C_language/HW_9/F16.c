#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

int main()
{
    char str[3];
    scanf("%s", str);
    int x = (int)str[0]-'A';//j
    int y = (int)str[1]-'0';//i
    int arr[ROWS][COLS]={{0},{0}};
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            if(((j%2==0) && (i%2==0)) || ((j%2==1) && (i%2==1)))
               arr[i][j]=1;
            else
                arr[i][j]=0;
        }
    }
    if (arr[x][y-1] == 1)
        printf("BLACK");
    else if (arr[x][y-1] == 0)
        printf("WHITE");
    return 0;
}

