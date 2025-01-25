#include <stdio.h>
#include <string.h>


int main()
{

    FILE *in, *out;
    char str[101]={0};
    size_t size;

    in=fopen("input.txt","r");
    fscanf(in,"%s",str);
    fclose(in);
    size=strlen(str);
    if(str[size-1]=='\n')
    {
        str[size-1]=='0';
        size--;
    }
    out=fopen("output.txt","w");
    fprintf(out,"%s, %s, %s", str,str,str);
    fprintf(out," %d", size);
    fclose(out);
    return 0;
}
