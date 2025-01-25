/*В файле input.txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'. Ответ записать в файл output.txt.*/
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

void writeOutputFile(const char *filename, int num)
{
    FILE *file = fopen(filename, "w");
        fprintf(file, "%d", num);
    fclose(file);
    printf("%d",num);
}

int func( char* str, int size)
{
    int num=0;
    for(int i=0;i<size;i++)
    {

        while(str[i]!=' ' && i < size)
        {
            i++;
        }
        if(str[i-1]=='a')
        {
            num++;
        }

    }


    return num;
}

int main()
{
    char str_in[MAX_LENGTH + 1];
    char str_out[MAX_LENGTH+1]={0};
    size_t size = readInputFile("input.txt", str_in, sizeof(str_in));
    size_t num=func(str_in, size);
    writeOutputFile("output.txt",num);
    //printf("%s",str_in);
    return 0;
}
