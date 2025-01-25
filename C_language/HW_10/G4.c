#include <stdio.h>
#include <string.h>


int main()
{
    FILE *in, *out;
    char str1[100]={0},str2[100]={0};
    size_t size1, size2;
    int flag=0;
    in=fopen("input.txt","r");
    fscanf(in,"%s",str1);
    fscanf(in,"%s",str2);
    fclose(in);
    size1=strlen(str1);
    size2=strlen(str2);
    out=fopen("output.txt","w");
    if(size2>size1)
    {
        size1=size2;
    }
    for(int i=0; i<size1;i++)
    {
        for(int j=0;j<size1;j++)
        {
            if(str1[i]==str1[j] && i!=j)
                flag=2;
            if(str1[i]==str2[j])
                flag++;

        }
        if(flag==1)
        fprintf(out,"%c ", str1[i]);
        flag=0;

    }
    return 0;
}
