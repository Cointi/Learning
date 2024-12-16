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

#define SIZE 12


void Input(int* arr, int n)
{
    for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
}

 void sort_massiv(int* arr, int n)
 {
    int sort[n];
    for( int i=n-1, y=0;i>=0;i--,y++)
        {
            if(y<4)
                sort[y]=arr[i-8];
            else if(y>=4 && y<8)
                sort[y]=arr[i];
            else if(y>=8 && y<12)
                sort[y]=arr[i+8];
         printf("%d ",sort[y]);
        }
}



int main()
{
    int arr[SIZE]={0};
    Input(arr,SIZE);
    sort_massiv(arr,SIZE);

    return 0;
}
