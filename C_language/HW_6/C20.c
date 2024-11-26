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





void correct (void)
{
    int flag=0;
    int state=0,count=0;
    char c,b;
     while((c=getchar())!='.')
    {
        b=c;
        if(c=='(')
        {

        flag++;

        }

        if(c==')')
        {

            flag--;
        }
        if(count==0 && c!='(') state=1;
        count++;
    }
    if( b!=')') state=1;
    if(flag==0 && state==0)    printf("YES");
    else printf("NO");
}

int main()
{

    correct();


    return 0;
}


