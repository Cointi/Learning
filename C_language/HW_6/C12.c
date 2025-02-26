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
float x,sim;


float sinus(float x)
{
    x=3.14157/180*x;
    sim=x-x*x*x/(1*2*3)+x*x*x*x*x/(1*2*3*4*5)-x*x*x*x*x*x*x/(1*2*3*4*5*6*7);
    return sim;
}

int main()
{
    scanf("%f", &x);
    sinus(x);
    printf("%.3f", sim);
    return 0;
}


