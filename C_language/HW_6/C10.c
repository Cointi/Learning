/*
 * C1.c
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
#include <math.h>

int n;

int simple_digit[]= {2,3,5,7,11,
13,17,19,23,29,31,37,41,43,
47,53,59,61,67,71,73};

void  print_simple(int n)
{
    int i=0;
    if(n==1)        printf("1");
    while(n!=1)
    {
        if(n%simple_digit[i]==0)
        {
            n/=simple_digit[i];
            printf("%d ", simple_digit[i]);
        }
        else i++;
    }
}

int main()
{
    scanf("%d", &n);
    print_simple(n);
    return 0;
}


