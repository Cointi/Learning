#include <stdio.h>

#define SIZE 10

void split(int N, int* arr, int* number_digits)
    {
        int val=N;
        int y=*number_digits;

        while(val>0)
            {
                arr[y]=val%10;
                val/=10;
                y++;
                //printf("%d", y);
            }
        *number_digits=y;
    }


void SwapArr(int *arr,int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort_massiv(int* arr, int n)
 {

    int noSwap;

    for (int i = 0; i < n; i++)
    {
        noSwap = 1;
        for (int j = n-1; j > i; j--)
        {
            //printf("%d\n",arr[j]);
            if(arr[j-1]>arr[j])
            {
                SwapArr(arr,j-1,j);
                noSwap = 0;
                //printf("  %d \n",arr[j]);
            }
        }
        if(noSwap)
            break;
    }
}

void Print(int *arr,int len)
{
    int i;
    for (i = len-1; i>=0; i--)
        printf("%d",arr[i]);
    printf("\n");
}


int main(int argc, char **argv)
{
    int N=0;
    int number_digits=0;
    int arr[SIZE]={0};
    scanf("%d", &N);
    split(N, arr, &number_digits);
        //for(int u=0; u<number_digits; u++)
           // printf("%d", arr[u]);
    sort_massiv(arr,number_digits);
    Print(arr,number_digits);
    return 0;
}
