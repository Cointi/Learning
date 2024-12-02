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

int  is2pow(int n)
{
    static int flag=0;
     /*static int i=0;
    if (n==1 && i==0)
        {
            flag=1;
            return flag ;
        }
        i=1;*/
    if(n>1)
    {
        if(n%2==0)
        {
            n/=2;
            is2pow(n);
        }
        else
        {
            flag=1;
            return flag ;
        }
    }

return flag ;
}

int main()
{
    int n;
    scanf("%d",&n);
    if( is2pow(n)) printf("NO");
    else printf("YES");
    return 0;
}


