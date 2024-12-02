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

void print_num(int num)
{
    int r_digit=0;
    static int i=0;
    if(num==0 && i==0) printf("%d ", num);
    i++;
    if(num>0)
    {
        r_digit=num%10;
        print_num(num/=10);
        printf("%d ", r_digit);
    }
    /*while(P>0)
    {
        r_digit=P%10;
        P/=10;
        printf("%d ", r_digit);
    }*/
}

int main()
{
    int n;
    scanf("%d", &n);
    print_num(n);
    return 0;
}

