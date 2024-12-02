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

void sequence(int Aa, int Bb)
{
    static int less=0;
    static int flag =0;
    if(Aa>Bb && flag==0) less=1;
    flag=1;

    if(less==1)
    {
        if(Aa>=Bb)
        {
            printf("%d ", Aa);
            Aa--;
            sequence(Aa,Bb);
        }
    }
    else
    {
        if(Aa<=Bb)
        {
            Bb--;
            sequence(Aa,Bb);
            printf("%d ", Bb+1);
        }
    }
}

int main()
{
    int A,B;
    scanf("%d%d", &A,&B);
    sequence(A,B);
    return 0;
}

