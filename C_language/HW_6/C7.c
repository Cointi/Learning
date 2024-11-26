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

int mainder;
int N,P;
int dex=0;
int result[32];

void system(int N, int P)
{
    if(N==0)
    {
        printf("%d",N);
    }
    while(N>0)
    {
        mainder=N%P;
        N/=P;
        result[dex]=mainder;
        dex++;
    }

    while(dex>0)
    {
        dex--;
        printf("%d", result[dex]);

    }

}

int main()
{
    scanf("%d%d", &N,&P);
    system(N,P);
    return 0;
}


