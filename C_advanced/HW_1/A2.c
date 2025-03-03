#include <stdio.h>
#include <string.h>
#include <inttypes.h>
struct cycsh
{
    uint8_t K;
    uint32_t N;

}st;

void cycle_shift(struct cycsh st)
{
     uint32_t res = (st.N>> st.K)|(st.N << (32 - st.K));
     printf("%u",res);
}
int main()
{

    //printf("%d",sizeof(st));
    scanf("%u%hhu", &(st.N), &(st.K));
    cycle_shift(st);
    return 0;
}
