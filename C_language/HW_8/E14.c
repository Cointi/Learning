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
//сам не додумался, ИИ предложил вариант с огромным расточительством памяти...
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

void replay(int* arr,int* mas, int n, int* k)
 {
     int l=*k;
     int found[1000]={0};
     for(int j =0; j<n; j++)
        {
            if(found[arr[j]]==0)
                found[arr[j]]=1;
            else if(found[arr[j]]==1)
            {
                mas[l]=arr[j];
                l++;
                found[arr[j]]=2;
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
    replay(arr,mas,SIZE,&amount);
    Print(mas,amount);
    return 0;
}
