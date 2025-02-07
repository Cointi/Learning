#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
// #include "temp_api.h"

#define SIZE 30
#define MAX_LENGTH 1000

struct sensor
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
};

int readInputFile(const char *filename, struct sensor *data, size_t bufferSize)
{

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Ошибка при открытии файла");
        return -1;
    }

    int index = 0;
    char line[100] = {0};

    while (fgets(line, sizeof(line), file))
    {
        uint16_t year;
        uint8_t month, day, hour, minute;
        int temp_read;

        // Проверка на корректный формат строки
        char *temp_ptr = strchr(line, '\n');
        if (temp_ptr)
            *temp_ptr = '\0'; // Удаление символа новой строки

        int items_read = sscanf(line, "%hu;%hhu;%hhu;%hhu;%hhu;%d",
                                &year, &month, &day, &hour, &minute, &temp_read);

        if (items_read == 6 && temp_read >= -99 && temp_read <= 99)
        {
            if (index < SIZE)
            {
                data[index].year = year;
                data[index].month = month;
                data[index].day = day;
                data[index].hour = hour;
                data[index].minute = minute;
                data[index].temperature = (int8_t)temp_read;
                index++;
            }
            else
            {
                printf("Достигнут лимит записей (%d).\n", SIZE);
                break;
            }
        }
        else
        {
            // Пропуск строки с некорректной температурой или отсутствующим значением
            continue;
        }
    }
    fclose(file);
    return index; // Возвращаем количество считанных записей
}

/*int AddInfo(struct sensor* info)
{
    int counter=0;
    AddRecord(info,counter++,2021,9,16,9);
    AddRecord(info,counter++,2022,9,2,-9);
    AddRecord(info,counter++,2021,1,7,8);
    AddRecord(info,counter++,2021,9,5,1);
    return counter;
}*/

/*void AddRecord(struct sensor* info,int number,uint16_t year,uint8_t month,uint8_t day,int8_t t)
{
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].t = t;
}*/

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

// среднемесячная температура
int Average_temp(struct sensor *info, int i, size_t index)
{
    // char temp=*i;
    //int mot = *i - '0';
    int mot = i;
    //printf("% d\n", mot);
    uint8_t number[SIZE] = {0};
    int sum = 0, count = 0, average = -1;

    for (int j = 0; j < index; j++)
    {
        if (info[j].month == mot)
        {
            sum += info[j].temperature;
            count++;
            // printf(" count = %d\n", count);
        }
    }
    average = sum / count;
    return average;
}
// минимальная температура
void Min_Temp(struct sensor *info, int i)
{
}
// максимальная температура
void Max_Temp(struct sensor *info, int i)
{
}
void Statistic_month(void)
{}
    // статистика за год
void Statistic_year(struct sensor *info, int i)
{
    /* int u=0;
     for(int j=1;j<=i;j++)
     {
         Average_temp(info,j);
         Min_Temp(info,j);
         Max_Temp(info,j);
     }*/
}

int main(int argc, char **argv)
{
    struct sensor info[SIZE];
    char *file_path = NULL;
    int rez = 0;
    int flag_m=0;

    


    while ((rez = getopt(argc, argv, "hf:m:")) != -1)
    {
        switch (rez)
        {
        case 'h':
        {
            printf("found argument \"h\".\n By default, the program outputs statistics for each month and year from a data file\n Command -f is the path to the data file\nCommand -m x is the statistics for month x only\n");
            break;
        }
        case 'f':
        {
            printf("found argument \"f\".\n");
            file_path=optarg;
            printf("file path %s\n",file_path);
            break;
        }   
        case 'm':
        {
            printf("found argument \"m = %s\".\n", optarg);
            flag_m=*optarg-'0';
            break;
        }
        case '?':
            printf("Error found !\n");
            break;
        }
    }
    size_t index = readInputFile(file_path, info, SIZE);// D:/Geany/Lesson/VS/temperature_small.csv
    if (index >= 0)
        printSensorInfo(info, index);
    /*for (int i = 0; i < argc; i++)
    {
        printf("\n%s \n", argv[i]);
    }*/
    if(flag_m!=0)
    {
            int a = Average_temp(info, flag_m, index);
            printf(" average_temp = %d\n", a);
    }

    // printf("%s\n",str_in);

    // struct sensor info[SIZE];
    // int number = 12;//AddInfo(info); //количество месяцев в году
    /*Average_temp(info,number);// среднемесячная температура
    Min_Temp(info,number);//минимальная температура в месяце
    Max_Temp(info,number);//максимальная температура в месяце
    Statistic_year(info,number);//статистика за год*/
    return 0;
}
