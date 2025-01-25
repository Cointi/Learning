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

void count_small_big_letter( char* str, int size, int* num_letter)
{
    int small_num=0,big_num=0;
    for(int i=0; i<size;i++)
    {
        if('a'<=str[i] && str[i]<='z')
            small_num++;
        if('A'<=str[i] && str[i]<='Z')
            big_num++;
    }
    num_letter[0]=small_num;
    num_letter[1]=big_num;
}

int main()
{
    FILE *out;
    char str[MAX_LENGTH + 1];
    int num_letter[2]={0};
    size_t size = readInputFile("input.txt", str, sizeof(str));
    count_small_big_letter(str, size, num_letter);
    printf("%d %d",num_letter[0], num_letter[1] );
    out=fopen("output.txt","w");
    fprintf(out,"%d %d", num_letter[0], num_letter[1]);
    fclose(out);
    return 0;
}
