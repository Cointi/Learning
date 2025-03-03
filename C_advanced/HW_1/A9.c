#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
/*Упаковать массив
В программе реализована структура данных:
struct pack_array {
uint32_t array; // поле для хранения упакованного массива из 0 и 1
uint32_t count0 : 8; // счетчик нулей в array
uint32_t count1 : 8; // счетчик единиц в array
}
Необходимо реализовать программу, которая упаковывает переданный ей массив из 32-ух элементов 0 и 1 в указанную структуру данных.
Функция должна строго соответствовать прототипу:*/

struct pack_array {
uint32_t array; // поле для хранения упакованного массива из 0 и 1
uint32_t count0 : 8; // счетчик нулей в array
uint32_t count1 : 8; // счетчик единиц в array
};

void array2struct(uint8_t arr[], struct pack_array* st)
{
    for(int i=0;i<32;i++)
    {
        st->array|=arr[i];
        //printf("arr[i] = %u\n",arr[i]);
        //printf("st->array = %u\n",st->array);
        if(i!=31)
            st->array=st->array<<1;

        //printf("\n");
        if(arr[i]==1)
            st->count1++;
        else
            st->count0++;
    }
    printf("%u %u %u",st->array,st->count0,st->count1);
}
int main()
{
    struct pack_array *st;
    uint8_t arr[32]={0};
    for(int i=0;i<32;i++)
        scanf("%d", &arr[i]);

    array2struct(arr,&st);
    return 0;
}
