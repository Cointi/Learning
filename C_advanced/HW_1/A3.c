#include <stdio.h>
#include <string.h>
#include <inttypes.h>
/*Извлечение бит
На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
Требуется взять K младших битов числа N и вывести полученное таким образом число.*/
struct cycsh
{
    uint8_t K;
    uint32_t N;

}st;

void shift(struct cycsh st)
{
    uint32_t val=2;
    for(int i=1;i<st.K;i++)
        val*=2;
    val--;
    uint32_t res = st.N & val;
    printf("%u",res);
}
int main()
{

    scanf("%u%hhu", &(st.N), &(st.K));
    shift(st);
    return 0;
}
