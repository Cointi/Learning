#include <stdio.h>
#include <string.h>
#include <inttypes.h>
/*Подсчет битов
На вход программе подается беззнаковое 32-битное целое число N. Требуется найти количество единичных битов в двоичном представлении данного числа..*/
struct cycsh
{
   // uint8_t K;
    uint32_t N;

}st;

void count_bit(struct cycsh st)
{
    uint32_t val=1;
    uint8_t res=0;
    for(int i=0;i<32;i++)
    {
        if(st.N&val)
            res++;
        val=val<<1;
    }
    printf("%d",res);
}
int main()
{

    scanf("%u", &(st.N));
    count_bit(st);
    return 0;
}
