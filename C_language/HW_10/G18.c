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
    if (buffer[length-1] == '\n')
    {
        buffer[length - 1] = '\0';
    }
    printf("%s\n",buffer);
    return strlen(buffer);
}

void writeOutputFile(const char *filename, const char *str)
{
    FILE *file = fopen(filename, "w");
        fprintf(file, "%s", str);
    fclose(file);
    printf("%s",str);
}


void remove_excess_symbol(char *str_in, char *str_out, size_t size)
{
    int flag=0;
    int i=0;
    int num_out=0;
    while(str_in[i]==' ')
    {
        i++;
    }
    for(;i<size;i++)
    {
        if(str_in[i]!=' ')
            str_out[num_out++]=str_in[i];
        else if (str_in[i]==' ')
        {
            while(str_in[i]==' ')
            {
                i++;
            }
            str_out[num_out++]=' ';
            i--;
        }
    }
}

int main()
{
    int flag=0;
    char str_in[MAX_LENGTH + 1];
    char str_out[MAX_LENGTH+1]={0};
    size_t size = readInputFile("input.txt", str_in, sizeof(str_in));
    //printf("%d\n",size);
    remove_excess_symbol(str_in, str_out, size);
    writeOutputFile("output.txt",str_out);
    return 0;
}
