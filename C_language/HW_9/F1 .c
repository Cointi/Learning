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

#define SIZE 5


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
void sort_array(int size,int a[])
{
    for(int i=size-1;i>=0;i--)
    {

        for(int j=0;j<i;j++)
        {
           // printf("%d>%d\n",arr[j],arr[i]);
             if(a[j]>a[j+1])
             {
                 int k=a[j];
                 a[j]=a[j+1];
                 a[j+1]=k;
                 //printf("%d\n",arr[i]);
             }

        }
    }
}

int main(int argc, char **argv)
{
int arr[10]={0};
Input(arr, SIZE);
Print(arr, SIZE);
sort_array(SIZE, arr);
Print(arr, SIZE);
    return 0;
}

