/*
 * B1.c
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
int main(int argc, char **argv)
{
    int number,i=10,product=1,sum=0,r_digit,b;
    scanf("%d", &number);
    while(number>i)
    {
        i++;
        b=i;
        while(b>0)
        {
            r_digit=b%10;
            sum+=r_digit;
            product*=r_digit;

            b=b/10;

        }
        if (sum==product) printf("%d\n",i);
        sum=0;
        product=1;
    }
return 0;
}
