#include <stdio.h>
#include <string.h>

#define SIZE 10

void Print(int* arr, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}


void Input(int* arr, int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

}


void swap_negmax_last(int size, int a[])
{
    int max_negativ=-1000, flag=-1;
    for(int i=0;i<size;i++)
    {
        if(a[i]<0)
        {
            if(max_negativ<a[i])
            {
                flag=i;
                max_negativ=a[i];
            }

        }
    }
    if(flag>=0)
    {
        int tmp=a[size-1];
        a[size-1]=max_negativ;
        a[flag]=tmp;
    }
}

int main(int argc, char **argv)
{
    int arr[SIZE]= {0};
    int len;
    Input(arr, SIZE);
    swap_negmax_last(SIZE,arr);
    Print(arr, SIZE);
    return 0;
}

