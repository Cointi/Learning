
//#define MAX_LENGTH 1000


struct sensor
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
};


size_t readInputFile(const char* , struct sensor**, size_t*);
void printSensorInfo(struct sensor*, int);
void Statistic_year(struct sensor* , size_t);
void Statistic_month(struct sensor* , int, size_t );
//void Sort_temp(struct sensor * , size_t);//функция сортировки по темп
