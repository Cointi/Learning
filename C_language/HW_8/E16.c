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
#define BIG 255

void Input(int* arr, int n)
{
    for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
}

int replay(int* arr, int n)
 {
    int max=0;
    int maxs=0;
    int found[BIG]={0};
    for(int j =0; j<n; j++)
        {
            found[arr[j]]++;
        }
    for(int i=0; i<BIG; i++)
        {
            if(found[i]>max)
                {
                    max=found[i];
                    maxs=i;
                }
        }
     return maxs;
}


int main()
{
    int arr[SIZE]={0};
    Input(arr,SIZE);
    printf("%d",replay(arr,SIZE));
    return 0;
}

