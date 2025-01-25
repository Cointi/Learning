#include <stdio.h>
#include <string.h>


int main()
{
    FILE *in, *out;
    char str[101]={0};
    size_t size;
    int num=0;
    in=fopen("input.txt","r");
    fscanf(in,"%s",str);
    fseek(in,0,SEEK_END);
    size = ftell(in);
    fclose(in);
    out=fopen("output.txt","w");
    for(int i=0;i<size-1;i++)
    {
        if(str[i]==str[size-1])
        {
            fprintf(out,"%d ", i);
            printf("%d ", i);
        }
    }
    fclose(out);
    return 0;
}
