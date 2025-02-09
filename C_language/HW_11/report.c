#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_function.h"

int main(int argc, char **argv)
{
    size_t size=10;//начальное количество записей в массив 
    struct sensor *info = malloc(size*sizeof(struct sensor));
    if(!info)
    {
        printf("Error malloc");
        return 1;
    }
    char *file_path = NULL;
    int rez = 0;
    int flag_m = 0;

    while ((rez = getopt(argc, argv, "hf:m:")) != -1)
    {
        switch (rez)
        {
        case 'h':
        {
            printf("found argument \"h\".\n\
           \r By default, the program outputs statistics for each month and year from a data file\n\
           \r Command -f is the path to the data file\n\
           \r Command -m x is the statistics for month x only\n");
            return 0;
        }
        case 'f':
        {
            printf("found argument \"f\".\n");
            file_path = optarg;
            printf("file path %s\n", file_path);
            break;
        }
        case 'm':
        {
            printf("found argument \"m = %s\".\n", optarg);
            // flag_m = atoi(optarg);
            while (*optarg) // цикл перевода строки в число
            {
                if (*optarg < '0' || *optarg > '9')
                    return -1; // Ошибка, если не цифра
                flag_m = flag_m * 10 + (*optarg - '0');
                optarg++;
            }
            break;
        }
        case '?':
            printf("\nTry -h for help\n\n");
            return 0;
        }
    }
    size_t index = readInputFile(file_path, &info, &size); // D:/Geany/Lesson/VS/temperature_small.csv
    if(index == 0)
    {
        free(info);
        return -1; // выходим, если файл не считан
    }
    //else 
       // printSensorInfo(info, index);    //результат счиытвания
    if(flag_m != 0)
        Statistic_month(info, flag_m, index);
    else
    {
        for (int i = 1; i <= 12; i++)
            Statistic_month(info, i, index);
        Statistic_year(info, index);
    }
    //printf("%d",index);
    free(info);
    return 0;
}
