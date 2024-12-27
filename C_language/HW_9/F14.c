#include <stdio.h>
#include <string.h>

#define SIZE 12

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

int sum_between_ab(int from, int to, int size, int a[])
{
    int sum=0;
    for(int i=from;i<=to;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(a[j]==i)
            {
                sum+=a[j];
            }
        }
    }
    return sum;
}

int main(int argc, char **argv)
{
    int arr[SIZE]= {0};
    int from=0, to=0, sum=0;
    Input(arr, SIZE);
    printf("Enter from and to ");
    scanf("%d %d", &from, &to);
    sum=sum_between_ab(from, to, SIZE, arr);
    printf("%d",sum);
    return 0;
}

