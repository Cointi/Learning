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

void sort(int* arr,int* positiv_mas,int* negativ_mas, int n, int* positiv, int* negativ)
 {
     int num_pos=*positiv;
     int num_neg=*negativ;
     for(int j =0; j<n; j++)
        {
            if(arr[j]>0)
                {
                    positiv_mas[num_pos]=arr[j];
                    num_pos++;
                }
            else if(arr[j]<0)
            {
                negativ_mas[num_neg]=arr[j];
                    num_neg++;
            }
        }
     *positiv=num_pos;
     *negativ=num_neg;
}



int main()
{
    int arr[SIZE]={0};
    int positiv_mas[SIZE]={0};
    int negativ_mas[SIZE]={0};
    int amount_negativ=0;
    int amount_positiv=0;
    Input(arr,SIZE);
    sort(arr,positiv_mas,negativ_mas,SIZE,&amount_positiv, &amount_negativ);
    Print(positiv_mas,amount_positiv);
    Print(negativ_mas,amount_negativ);
    return 0;
}
