#include <stdio.h>
#include <string.h>


void Print(int* arr, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

int Input(int* arr)
{
    int lenght=0;
    int size=0;
    int num=0;
    int flag=0;
    char s[5000]={0};
    scanf("%[^\n]",s);
    lenght=strlen(s);
    for(int i=0;i<lenght;i++)
    {
        if(s[i]==' ')
        {
            if(flag)
            {
                arr[size++]=num;
                num=0;
                flag=0;
            }
        }
        else
        {
            flag=1;
            num=num*10+(s[i]-'0');
        }

    }
    if(flag)
    {
        arr[size++]=num;
        num=0;
        flag=0;
    }
    return size;
}

int find_pass_num(int* arr, int n)
{
    int pass_num=0;
    int flag=0;
    int min=arr[1];
    for(int j=1;j<n;j++)
    {
        if(arr[j]!=min)
        {
            pass_num=min;
            return pass_num;
        }
        min++;
    }
}

void sort_array(int size,int a[])
{
    for(int i=size-1;i>=0;i--)
    {

        for(int j=0;j<i;j++)
        {
             if(a[j]>a[j+1])
             {
                 int k=a[j];
                 a[j]=a[j+1];
                 a[j+1]=k;
             }

        }
    }
}

int main(int argc, char **argv)
{
    int arr[1000]= {0};
    int pass_num=0;
    int size=0;
    size=Input(arr);
    sort_array(size, arr);
    pass_num=find_pass_num(arr,size);
    printf("%d", pass_num);
    return 0;
}

