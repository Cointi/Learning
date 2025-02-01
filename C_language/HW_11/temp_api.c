#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "temp_api.h"

#define SIZE 30



/*void print(struct sensor* info,int number){
    printf("===================================\n");
    for(int i=0;i<number;i++)
        printf("%04d-%02d-%02d t=%3d\n",
        info[i].year,
        info[i].month,
        info[i].day,
        info[i].t);
}*/

// среднемесячная температура
void Average_temp(struct sensor* info,int i)
{

}
//минимальная температура 
void Min_Temp(struct sensor* info,int i)
{

}
//максимальная температура 
void Max_Temp(struct sensor* info,int i)
{

}
//статистика за год
void Statistic_year(struct sensor* info,int i)
{
   /* int u=0;
    for(int j=1;j<=i;j++)
    {
        Average_temp(info,j);
        Min_Temp(info,j);
        Max_Temp(info,j);
    }*/

}


int main(void)
{
    struct sensor info[SIZE];
    int number = 12; //количество месяцев в году 
    Average_temp(info,number);// среднемесячная температура
    Min_Temp(info,number);//минимальная температура в месяце
    Max_Temp(info,number);//максимальная температура в месяце
    Statistic_year(info,number);//статистика за год
    return 0;
}