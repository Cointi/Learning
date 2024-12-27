#include <stdio.h>
#include <string.h>

#define SIZE 30

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

void change_max_min(int size, int a[])
{
    int max=-30000,min=30000;
    int min_num=0, max_num=0;
    for(int i=0;i<size;i++)
    {
        if(max<a[i])
        {
            max=a[i];
            max_num=i;
        }
        if(min>a[i])
        {
            min=a[i];
            min_num=i;
        }
    }
    a[min_num]=max;
    a[max_num]=min;
}

int main(int argc, char **argv)
{
    int arr[SIZE]= {0};
    int min=0;
    Input(arr, SIZE);
    change_max_min(SIZE, arr);
    Print(arr, SIZE);
    return 0;
}

