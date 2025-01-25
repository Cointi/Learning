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
    //printf("%s\n",buffer);
    return strlen(buffer);
}

void writeOutputFile(const char *filename, const char *str)
{
    FILE *file = fopen(filename, "w");
        fprintf(file, "%s", str);
    fclose(file);
    printf("%s",str);
}

int is_palindrom(char* word)
{
    int num_res=0;
    char result[MAX_LENGTH]={0};
    int flag=0,num_letter=0,val=0,var=0;
    size_t size=strlen(word);
    int number[1000]={0};
    int hot=0;
    for(int i=0;i<size;i++)
    {
       for(int y=0;y<num_letter;y++)
        {
            if(word[i]==result[y])
                {
                    flag=1;
                    break;
                }
        }
        for(int j=size-1;j>=i;j--)
        {
            if(flag==1)
                break;
            if(word[j]==word[i])
            {
                result[num_letter]=word[i];
                number[num_letter]++;
                hot=1;
            }
        }
        if(hot==1)
            num_letter++;
        hot=0;
        flag=0;
    }
     //printf("%s\n", result);
     for(int i=0;i<num_letter;i++)
     {
         //printf(" res %c = %d\n",result[i], number[i]);
         if(number[i]==1)
             val++;
         else if(number[i]%2!=0)
            var++;
     }
     //printf("%d %d\n", var,val);
     if(var==1 && val==0)
        return 0;
     if(var==0 && val==1)
        return 0;
     return 1;
}

int main()
{
    char str_in[MAX_LENGTH + 1];
    size_t size=readInputFile("input.txt", str_in, sizeof(str_in));
    char string[MAX_LENGTH+ 1]={0};
    int flag=0;
    size_t num_letter=0;
    for(int i=0;i<size;i++)
    {
        if(str_in[i]>='a' && str_in[i]<='z')
            string[num_letter++]=str_in[i];
    }
    flag=is_palindrom(string);
    //printf("%s\n", string);
    if(flag)
        writeOutputFile("output.txt","NO");
    else
        writeOutputFile("output.txt","YES");
    return 0;
}
