#include <stdio.h>
#include <string.h>


int main()
{
    FILE *in, *out;
    size_t size;
    int num=0;
    in=fopen("input.txt","r");
    fscanf(in,"%d",&num);
    //printf("%d", num);
    fclose(in);

    out=fopen("output.txt","w");

    for(int i=0, j=0;i<num;i++,j++)
    {
        if(j+1==10)
        {
            j=1;
        }
        if(i%2!=0)
        {
            fprintf(out,"%d", j+1);
        }
        else
        {
            fprintf(out,"%c", 'A'+i/2);
        }
    }
    fclose(out);
    return 0;
}
