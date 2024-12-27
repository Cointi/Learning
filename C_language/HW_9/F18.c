#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void Input(int arr[][COLS],int N, int M)
{
    for(int i=0;i<N; i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}
 void Print(int arr[][COLS],int N, int M)
{
    printf("\n");
    for(int i=0;i<N; i++)
    {
        for(int j=0;j<M;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
 void Find_Max_Row(int arr[][COLS],int N, int M)
 {
     int max_row=-20000;
     int sum_max=0;
     for(int i=0;i<N; i++)
     {
        for(int j=0;j<M;j++)
        {
            //printf("%d\n", arr[i][j]);
            if(max_row<arr[i][j])
            {
                max_row=arr[i][j];
            }

        }
        sum_max+=max_row;
        max_row=-20000;
     }
     printf("%d",sum_max);
 }
int main()
{
    int arr[ROWS][COLS]={{0},{0}};
    Input(arr,ROWS,COLS);

    Find_Max_Row(arr,ROWS,COLS);
    return 0;
}

