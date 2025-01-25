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

void Swap(char* str)
{

    int size=strlen(str);
    int i=0;
    int flag=1;
    //printf("%s   %d\n", str, size);
    while(flag)
    {
        if(str[i]!= ' ')
        {
            char  tmp  = str[size-1];
            str[size-1] =  str[i];
            str[i]   =   tmp;
            flag=0;
        }
        else  i++;
    }
    //printf("%s   %d\n", str, size);
}

void replace_symbol(char *str_in, char *str_out, size_t size)
{
    char arr[30]={0};
    int num=0;
    int num_out=0;
    int flag=0;
    for(int i=0;i<size;i++)
    {
        while(flag<2)
        {
            if(str_in[i]!=' ')
            {
                flag++;
            }
            arr[num++]=str_in[i++];
        }

        Swap(arr);
        for(int u=0;u<num;u++)
        {
            str_out[num_out++]=arr[u];
            arr[u]=0;
        }
        num=0;
        flag=0;
        i--;

    }
    //Swap(arr);
    //printf("%s", str_out);
}

int main()
{
    int flag=0;
    char str_in[MAX_LENGTH + 1];
    char str_out[MAX_LENGTH+1]={0};
    size_t size = readInputFile("input.txt", str_in, sizeof(str_in));
    //printf("%d\n",size);
    replace_symbol(str_in, str_out, size);
    writeOutputFile("output.txt",str_out);
    return 0;
}
