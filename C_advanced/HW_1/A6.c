#include <stdio.h>
#include <string.h>
#include <inttypes.h>
/*Инверсия старших
На вход программе подается беззнаковое 32-битное целое число N.
Требуется изменить значения всех битов старшего байта числа на противоположные и вывести полученное таким образом число..*/
struct cycsh
{
    uint8_t K;
    uint32_t N;

}st;

void count_bit(struct cycsh st)
{
    uint32_t res=0;
    res=~st.N;
    res=res&(0xFF000000);
    st.N=st.N&(0xFFFFFF);
    st.N=st.N|res;
    printf("%u",st.N);
}
int main()
{

    scanf("%u", &(st.N));
    count_bit(st);
    return 0;
}
