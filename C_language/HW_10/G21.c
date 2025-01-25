#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 2500

int readInputFile(const char *filename, char *buffer, size_t bufferSize)
{
    char line[MAX_LENGTH]={0};
    FILE *file = fopen(filename, "r");
    while(fgets(line, bufferSize, file))
    {
        strcat(buffer, line);
    }
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
    FILE *file = fopen(filename, "a");
        fprintf(file, "%s", str);
    fclose(file);
    printf("%s",str);
}


int func(char *str_in, size_t size_in)
{
    size_t num_stone=0;
    for (int i=0;i<size_in; i++)
    {
        if(str_in[i]== '*')
            num_stone++;
    }
    printf("%llu\n",num_stone);
    return num_stone;
}
int check(size_t num_stone)
{
    int val=3,i=3;
    while(val!=num_stone)
    {
        if(val>num_stone)
            return 0;
        val=val+i;
        i++;
    }
    if(val==3 && i==3)
        return 2;
    else
        return i-1;
}

void out_mas_func(size_t num_str)
{

    int num_mas=0,count=0;
    for(int i=0;i<=num_str;i++)
    {
        char mas[MAX_LENGTH]={0};
        int probel=num_str-i;
        while(probel!=0)
        {
            mas[num_mas++]=' ';
            probel--;
        }
        for(int j=0;j<=count;j++)
        {
            mas[num_mas++]='*';
            mas[num_mas++]=' ';
        }
        while(probel!=num_str-i)
        {
            mas[num_mas++]=' ';
            probel++;
        }
        mas[num_mas++]='\n';
        writeOutputFile("output.txt",mas);
        num_mas=0;
        count++;
    }

}
int main()
{
    char str_in[MAX_LENGTH + 1];
    size_t size_in=readInputFile("input.txt", str_in, sizeof(str_in));
    size_t num_stone=func(str_in,size_in);
    int num_str=check(num_stone);
    printf("%d\n",num_str);
    if(num_str==0)
        writeOutputFile("output.txt","NO");
    else
    {
        out_mas_func(num_str-1);
    }
    return 0;
}
