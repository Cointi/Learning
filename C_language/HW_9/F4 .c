/*
 * F1 .c
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
#include <string.h>


void Print(int* arr, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d", *(arr+i));
    }
    printf("\n");
}

void print_digit(char* s)
{
    int a[80]= {0};
    int digit[80]= {0};
    int count=1,j=0,flag=1,size=0;
    int lenght=strlen(s);
    for(int i=0; i<lenght; i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[size]=(int)s[i]-48;
            size++;
        }
    }
    for(int i=size-1; i>=0; i--)
    {
        for(int u=0; u<i; u++)
        {
            if(a[u]>a[u+1])
            {
                int k=a[u];
                a[u]=a[u+1];
                a[u+1]=k;
            }
        }
    }
    int num_sort=0;
    for(int f=0; f<size; f++)
    {
        if(flag)
        {
            digit[num_sort++]=a[f];
            flag=0;
        }
        if(a[f]==a[f+1] && size!=1 && f!=size-1)
        {
            count++;
        }
        else if(a[f]!=a[f+1] && (f+1)<size)
        {
            flag=1;
            digit[num_sort++]=count;
            count=1;
        }
        if(f==size-1 && flag==0)
        {
            digit[num_sort++]=count;
            count=1;
        }
    }
    for(int k=0; k<num_sort; k++)
    {
        if(k%2==0 && k!=0)
        {
            printf("\n");
        }
        printf("%d ",digit[k]);
    }
}
int main(int argc, char **argv)
{
    char s[100];
    scanf("%[^\n]",s);
    print_digit(s);
    return 0;
}

