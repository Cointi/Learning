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
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fclose(file);
    if(file_size==0)
    {
        return 0;
    }
    size_t length = strlen(buffer);
    if (buffer[length-1] == '\n')
    {
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

void replace_word(const char *source, const char *old_word, const char *new_word, char *result)
{
    const char *pos = source;// указатель на текущую позиции в строке в начале 0
    size_t old_len = strlen(old_word); // Длина слова для замены
    size_t new_len = strlen(new_word); // Длина нового слова
    while ((pos = strstr(pos, old_word)) != NULL)
    {
        strncat(result, source,pos-source);
        strcat(result, new_word);
        // Перемещаем указатель на конец заменённого слова
        pos += old_len;
        source = pos;// Обновляем начало оставшейся части строки переместив указатель нашего массива в новую точку
    }
    strcat(result, source);
}

int main()
{
    int flag=0;
    char str_in[MAX_LENGTH + 1];
    char str_out[MAX_LENGTH+1]={0};
    long position=0;
    size_t size_out=0;
    size_t size = readInputFile("input.txt", str_in, sizeof(str_in));
    if(size==0)
    {
        writeOutputFile("output.txt",str_out);
        return 0;
    }

    printf("%s\n",str_in);
    //printf("%d\n",size);
    replace_word(str_in, "Ling", "Cao", str_out);
    writeOutputFile("output.txt",str_out);
    return 0;
}
