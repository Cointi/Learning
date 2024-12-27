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

void find_two_min_num_array(int size, int a[])
{
    int min1=30000,min2=30000;
    int min_num1=0,min_num2=0;
    for(int i=0;i<size;i++)
    {
        if(min1>a[i])
        {
            min1=a[i];
            min_num1=i;
        }
        //printf("%d %d\n", min_num1, min_num2);
    }
    for(int j=0;j<size;j++)
    {
        if(min2>a[j] && j!=min_num1)
        {
            min2=a[j];
            min_num2=j;
        }
    }
    if(min_num1>min_num2)
        printf("%d %d", min_num2, min_num1);
    else
        printf("%d %d", min_num1, min_num2);

}

int main(int argc, char **argv)
{
    int arr[SIZE]= {0};
    int min=0;
    Input(arr, SIZE);
    find_two_min_num_array(SIZE,arr);
    return 0;
}

