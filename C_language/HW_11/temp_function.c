/*All function app*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "temp_function.h"

//функция считывания с файла
size_t readInputFile(const char* filename, struct sensor** data, size_t* bufferSize)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("\nError open file\nTry -h for help\n\n");
        return 0;
    }
    int index = 0;
    char line[100] = {0};
    int num_str=0;// хранение количества итераций для отслеживания номер строки с ошибкой
    
    while (fgets(line, sizeof(line), file))
    {
        if(index >= *bufferSize)// проврека на необходимость расширения памяти
        {
            *bufferSize*=2;
            struct sensor *vary = realloc(*data, *bufferSize*(sizeof(struct sensor)));
            if(!vary)
            {
                printf("Error realloc\n");
                free(vary);
                fclose(file);
                return index;
            }
            *data=vary;
        }
        uint16_t year;
        uint8_t month, day, hour, minute;
        int temp_read;
        
        int items_read = sscanf(line, "%hu;%hhu;%hhu;%hhu;%hhu;%d",
                                &year, &month, &day, &hour, &minute, &temp_read);
        num_str++;
        if (items_read == 6)
        {
            if (index < *bufferSize)
            {
                (*data)[index].year = year;
                (*data)[index].month = month;
                (*data)[index].day = day;
                (*data)[index].hour = hour;
                (*data)[index].minute = minute;
                (*data)[index].temperature = (int8_t)temp_read;
                index++;
            }
        }
        else
        {
            printf("\nError data string %d\n", num_str); // string с некорректным значением
            continue;     
        }
    }
    fclose(file);
    return index; // Возвращаем количество считанных записей
}

//функция вывода данных
void printSensorInfo(struct sensor *info, int number)
{
    printf("===================================\n");
    for (int i = 0; i < number; i++)
        printf("%04d-%02d-%02d hour - %02d, minute - %02d, t = %3d\n",
               info[i].year,
               info[i].month,
               info[i].day,
               info[i].hour,
               info[i].minute,
               info[i].temperature);
}

// статистика за месяц
void Statistic_month(struct sensor *info, int i, size_t index)
{
    int sum = 0, count = 0, average = -1, min = 100, max = -100;
    static int num_cc=0;// счетчик пункта месяцев
    for (int j = 0; j < index; j++)
    {
        if(info[j].month == i)
        {
            sum += info[j].temperature;
            count++;
            if (min > info[j].temperature)
                min = info[j].temperature;
            if (max < info[j].temperature)
                max = info[j].temperature;
        }            
    }
    average = sum / count;
    num_cc++;
    printf("\n\
# Year Month Month_avg Month_max Month_min\n\
%d %d  %d      %d        %d        %d     \n",  num_cc, info->year, i, average, max, min);
}

// статистика за год
void Statistic_year(struct sensor *info, size_t index)
{
    int sum = 0, count = 0, average = -1, min = 100, max = -100;
    for (int j = 0; j < index; j++)
    {
        if(info[j].temperature>-99 && info[j].temperature<99)
        {
            sum += info[j].temperature;
            count++;
            if (min > info[j].temperature)
                min = info[j].temperature;
            if (max < info[j].temperature)
                max = info[j].temperature;
        }
    }
    average = sum / count;
    
   printf("Year statistics:\n\
            \r  average temp = %d\n\
            \r  max = %d\n\
            \r  min = %d\n", average, max, min);
}

//сортировка по температуре 
/*void Sort_temp(struct sensor *info, size_t index)
{
    for(int i=0;i<index;i++)
    {
        for(int j=i;j<index;j++)
        {
            if(info[i].temperature>info[j].temperature)
            {
                struct sensor template = info[i];
                info[i] = info[j];
                info[j] = template;
            }
        }
    }
}*/