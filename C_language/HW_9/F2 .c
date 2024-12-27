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

#define SIZE 21


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
void sort_even_odd(int n, int a[])
{
    int even_num=0;
    int odd_num=0;
    int odd[n];
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            //printf("%d\n",i);
            a[even_num]=a[i];
            even_num++;
        }
        else
        {
            odd[odd_num]=a[i];
            odd_num++;
        }
    }
    for(int j=even_num, i=0;j<n;j++,i++)
    {
        a[j]=odd[i];
    }
}

int main(int argc, char **argv)
{
int arr[10]={0};
Input(arr, SIZE);
Print(arr, SIZE);
sort_even_odd(SIZE, arr);
Print(arr, SIZE);
    return 0;
}
