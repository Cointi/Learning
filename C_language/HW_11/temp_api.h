

struct sensor {
 uint8_t day;
 uint8_t month;
 uint16_t year;
 int8_t t;
};


void Average_temp(struct sensor* info,int);
void Min_Temp(struct sensor* info,int );
void Max_Temp(struct sensor* info,int );
void Statistic_year(struct sensor* info,int );
