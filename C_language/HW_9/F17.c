#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

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
    for(int i=0;i<N; i++)
    {
        for(int j=0;j<M;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
 void Trace_matrix(int arr[][COLS],int N, int M)
 {
     int sum=0;
     for(int i=0;i<N; i++)
     {
        for(int j=0;j<M;j++)
        {
           if(i==j)
            sum+=arr[i][j];
        }
     }
     printf("%d",sum);
 }
int main()
{
    int arr[ROWS][COLS];//={{0},{0}};
    Input(arr,ROWS,COLS);
    //Print(arr,ROWS,COLS);
    Trace_matrix(arr,ROWS,COLS);
    return 0;
}

