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

void writeOutputFile(const char *filename, const char *str)
{
    FILE *file = fopen(filename, "w");
        fprintf(file, "%s", str);
    fclose(file);
    printf("%s",str);
}

void func_large_word( char* str, int size, char* str_out)
{
    int num=0;
    int i=size-1;
    int pos=0;
    while(str[i--]!='/')
    {
        pos++;
    }
    i=0;
    for(i=0; i<size-pos;i++)
    {
            str_out[num++]=str[i];
    }
    //printf("%d\n",i);
    //printf("%s",str_out);
    while(str[i]!='.' && i<size)
    {
        str_out[num++]=str[i++];
    }
    strcat(str_out, ".html");
}

int main()
{
    char str_in[MAX_LENGTH + 1];
    char str_out[MAX_LENGTH+1]={0};
    size_t size = readInputFile("input.txt", str_in, sizeof(str_in));
    func_large_word(str_in, size, str_out);
    writeOutputFile("output.txt",str_out);
    //printf("%s",str_in);
    return 0;
}
