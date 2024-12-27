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

void function(int size, int a[])
{
    int even_num=0,odd_num=0;
    for(int i=0;i<size;i++)
    {
        if(a[i]%2==0)
            even_num++;
        else
            odd_num++;
    }
    if(even_num>odd_num)
    {
        for(int j=0;j<size;j++)
        {
            if(a[j]%2>0)
            {
                int val=a[j];
                int prod=1;
                while(val>0)
                {
                    if(val%2>0)
                    {
                        prod=prod*(val%10);
                    }
                    val/=10;
                }
                a[j]=prod;
            }
        }
    }
    else
    {
        for(int u=0;u<size;u++)
        {
            if(a[u]%2==0)
            {
                int val=a[u];
                int prod=1;
                while(val>0)
                {
                    if(val%2==0)
                    {
                        prod=prod*(val%10);
                    }
                    val/=10;
                }
                a[u]=prod;
            }
        }
    }
}

int main(int argc, char **argv)
{
    int arr[SIZE]= {0};
    Input(arr, SIZE);
    function(SIZE, arr);
    Print(arr, SIZE);
    return 0;
}

