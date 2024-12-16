/*
 * D1.c
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

#define SIZE 10



void Input(int* arr, int n)
{
    for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
}

void Print(int *arr,int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%d ",arr[i]);
    printf("\n");
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
        int val_1,val_2;
        noSwap = 1;
        for (int j = n-1; j > i; j--)
        {
            val_1=arr[j]%10;
            val_2=arr[j-1]%10;
           // printf("%d %d \n", val_1,val_2);
            if(val_2>val_1)
            {
                SwapArr(arr,j-1,j);
                noSwap = 0;
            }
        }
        if(noSwap)
            break;
    }
}



int main()
{
    int arr[SIZE]={0};
    Input(arr,SIZE);
    sort_massiv(arr,SIZE);
    Print(arr,SIZE);
    return 0;
}
