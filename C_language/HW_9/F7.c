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

#define SIZE 100

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


int compression(int a[], int b[], int N)
{
    int size_arr_out=0;
    int count=1;
    if(a[0]==1)
        {
            b[size_arr_out++]=0;
        }
    for(int i=0; i<N; i++)
    {
        if(a[i]==a[i+1] && (i+1)!=N)
        {
            count++;
        }
        else
        {
            b[size_arr_out++]=count;
            count=1;
        }
    }

    return size_arr_out;
}


int main(int argc, char **argv)
{
    int arr_in[SIZE]= {0};
    int arr_out[SIZE]= {0};
    int len;
    Input(arr_in, SIZE);
    len=compression(arr_in,arr_out,SIZE);
    printf("%d\n",len);
    Print(arr_out,len);
    return 0;
}

