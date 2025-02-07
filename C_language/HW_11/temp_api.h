

struct sensor
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
};

int readInputFile(const char* , struct sensor*, size_t bufferSize)
void printSensorInfo(struct sensor*, int);
void Statistic_year(struct sensor* , int );
void Statistic_month(struct sensor* , int, size_t );
