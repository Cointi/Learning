#include <stdio.h>
#include <string.h>
#include <inttypes.h>
/*Поиск последовательности бит
На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31).
Требуется взять K подряд идущих битов числа N так, чтобы полученное число было максимальным. Программа должна вывести полученное число.*/
struct cycsh
{
    uint8_t K;
    uint32_t N;

}st;

void shift(struct cycsh st)
{
    uint32_t max=0;
    uint32_t res=0; ;
    uint32_t val=2;
    uint32_t var=0;
    for(int i=1;i<st.K;i++)
        val*=2;
    val--;
    var=val;
    for(int i=0;i<32;i++)
    {
        res=(st.N)&(val);
        res=res>>i;
        res=res&(var);
        if(res>max)
        {
            max=res;
        }

        val=val<<1;
        res=0;
    }
    printf("%u",max);
}
int main()
{
    scanf("%u%hhu", &(st.N), &(st.K));
    shift(st);
    return 0;
}
