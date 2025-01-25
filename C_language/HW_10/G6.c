#include <stdio.h>
#include <string.h>

int is_palindrom(char* str)
{
    int size=strlen(str)-1;
    for(int i=0, j=size-1; i<size/2, j>=size/2;i++,j--)
    {
        if(str[i]!=str[j])
            return 0;
    }
    return 1;
}

int main()
{
    FILE *in, *out;
    char str[1000]={0};
    size_t size;
    int flag=0;
    in=fopen("input.txt","r");
    fscanf(in,"%[^EOF]s",str);
    fclose(in);
    out=fopen("output.txt","w");
    if(is_palindrom(str))
        {
            fprintf(out,"YES");
            printf("YES");
        }
    else
        fprintf(out,"NO");
    fclose(out);
    return 0;
}
