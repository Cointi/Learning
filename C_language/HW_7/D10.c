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

int is_prime(int n)
{
    static int i=2;
    static int flag=0;
    int b;
    if(i==2 && n==1) return 1;
    if(i<n)
    {
        b=n%i;
        if(b==0) flag=1;
        i++;
        is_prime(n);
    }

    return flag;
}

int main()
{
    int A;
    scanf("%d", &A);
    //is_prime(A);
    if(is_prime(A)) printf("NO");
    else printf("YES");
    return 0;
}

