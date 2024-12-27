/*
 * F1 .c
 *
 * Copyright 2024 hoste <hoste@DESKTOP-OA2VJ92>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


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


void function(int* arr, int size)
{
    int digit[40]={0};
    int count=1,j=0,flag=1;
    for(int i=0; i<size; i++)
    {
        if(flag)
        {
            digit[j++]=arr[i];
            flag=0;
        }
        if(arr[i]==arr[i+1])
        {
            count++;
        }
        else
        {
            flag=1;
            digit[j++]=count;
            count=1;
        }
    }
    if(size==1 && j==1)
    {
        digit[1]=1;
        j++;
    }
        for(int k=0;k<j;k++)
        {

            if(k%2==0 && k!=0)
            {
                printf("\n");
            }
        printf("%d ",digit[k]);
        }
}
void Split(int* arr, int *n)
{
    char  c;
    int size=*n;
    while( (c=getchar())!='\n' )
    {
        arr[size]=(int)c-48;
        size++;
    }
    *n=size;

}
int main(int argc, char **argv)
{
int arr[100]={0};
int size=0;
Split(arr,&size);
sort_array(size, arr);
function(arr, size);
    return 0;
}

