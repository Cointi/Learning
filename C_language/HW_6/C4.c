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
int x=1;
int equation;
int max;
int b=0;
int f(int x)
{

if(x>=(-2) && x<2)
b=1;
if(x>=2)
b=2;
if(x<(-2))
b=3;
    switch(b)
    {
    case 1:
    equation=x*x;
    break;
    case 2:
    equation=x*x+4*x+5;
    break;
    case 3:
    equation=4;
    break;
    default:
    }
return equation;
}

int main()
{
   /* while(1)
    {
        scanf("%d", &x);
         if(x==0) break;
        f(x);
        if (x>max) max=x;
    }
     printf("%d", max);*/
    while(x!=0)
    {
    scanf("%d", &x);
    f(x);
    if (equation>max) max=equation;
    }
    printf("%d", max);
    return 0;
}


