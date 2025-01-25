#include <stdio.h>
#include <string.h>


int main()
{
    FILE *in, *out;
    char str[1000]={0};
    size_t size;
    int flag=0;
    in=fopen("input.txt","r");
    fscanf(in,"%[^EOF]s",str);
    fclose(in);
    size=strlen(str);
    out=fopen("output.txt","w");
    for(int i=0;i<size;i++)
    {
        if(str[i]=='a')
            str[i]='b';
        else if(str[i]=='A')
            str[i]='B';
        else if(str[i]=='b')
            str[i]='a';
        else if(str[i]=='B')
            str[i]='A';
    }
    fprintf(out,"%s ", str);
    fclose(out);
    return 0;
}
