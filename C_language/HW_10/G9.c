#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int readInputFile(const char *filename, char *buffer, size_t bufferSize)
{

    FILE *file = fopen(filename, "r");
    fgets(buffer, bufferSize, file);
    fclose(file);
    size_t length = strlen(buffer);
    if (buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0';
    }

    return strlen(buffer);
}

void writeOutputFile(const char *filename, const char *str, size_t Length)
{
    FILE *file = fopen(filename, "w");
        fprintf(file, "%s", str);
    fclose(file);
    printf("%s",str);
}

int func_remove_repeat( char* str, int size, char* str_out)
{

    int num_out=0;
    int flag=0;
    for(int i=0; i<size;i++)
    {
        flag=0;
        if(str[i]==' ')
                continue;
        for(int j=0;j<num_out;j++)
        {
            if(str_out[j]==str[i])
                flag=1;
        }
        if(flag==0)
            str_out[num_out++]=str[i];

    }
    return num_out;
}

int main()
{
    FILE *out;
    char str_in[MAX_LENGTH + 1];
    char str_out[MAX_LENGTH+1]={0};
    size_t size = readInputFile("input.txt", str_in, sizeof(str_in));
    size_t size_out=func_remove_repeat(str_in, size, str_out);
    writeOutputFile("output.txt",str_out,size_out);

    return 0;
}
