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

void sort_massiv(int* arr,int* mas, int n, int *k)
 {
     int l=*k;
     int val;
     for(int j =0; j<n; j++)
     {
        val=arr[j]/10;
        if(val%10==0)
            {
                mas[l]=arr[j];
                l++;
            }
     }
     *k=l;
}



int main()
{
    int arr[SIZE]={0};
    int mas[SIZE]={0};
    int amount=0;
    Input(arr,SIZE);
    sort_massiv(arr,mas,SIZE,&amount);
    Print(mas,amount);
    return 0;
}
