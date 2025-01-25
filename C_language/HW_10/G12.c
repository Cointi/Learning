/*В файле input.txt дана строка слов, разделенных пробелами.
Найти самое длинное слово и вывести его в файл output.txt.
Случай, когда самых длинных слов может быть несколько, не обрабатывать.*/
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

int func_large_word( char* str, int size, char* str_out)
{

    int num=0;
    int flag=0;
    for(int i=0; i<size;i++)
    {
        while(str[i]!=' ' && i<size)
        {
            str_out[num++]=str[i++];
            flag=1;
        }
        if(flag==1)
        {
            str_out[num++]='\n';
            flag=0;
        }
    }

    return num;
}

int main()
{
    char str_in[MAX_LENGTH + 1];
    char str_out[MAX_LENGTH+1]={0};
    size_t size = readInputFile("input.txt", str_in, sizeof(str_in));
    size_t size_out=func_large_word(str_in, size, str_out);
    writeOutputFile("output.txt",str_out,size_out);
    //printf("%s",str_in);
    return 0;
}
