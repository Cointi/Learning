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

int count_between(int from, int to, int size, int a[])
{
    int num=0;
    for(int i=from;i<=to;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(a[j]==i)
            {
                num++;
            }
        }

    }
    return num;
}


int main(int argc, char **argv)
{
    int arr[SIZE]= {0};
    int from=0, to=0, num=0;
    Input(arr, SIZE);
    printf("Enter from and to ");
    scanf("%d %d", &from, &to);
    num=count_between(from, to, SIZE, arr);
    printf("%d",num);
    return 0;
}

