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

int main()
{
    int massiv[10];
    int min=65536;
    int max=-65536;
    int num_min, num_max;
    for(int i=0;i<10;i++)
    {
        scanf("%d",&massiv[i]);
        if(min>massiv[i])
        {
            min=massiv[i];
            num_min=i+1;
        }
        if(max<massiv[i])
        {
            max=massiv[i];
            num_max=i+1;
        }
    }
    printf("%d %d %d %d", num_max,max,num_min, min );
    return 0;
}
