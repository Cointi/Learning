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

void pass_letter(char* str_in)
{
    char str_out[MAX_LENGTH]={0};
    int num_out=0;
    size_t size = strlen(str_in);
    for(int i=0;i<size;i++)
    {
        if(i==0)
            str_out[num_out++]=str_in[i];
        if(str_in[i]!='a' && str_in[i]!='e' && str_in[i]!='h' && str_in[i]!='i' && str_in[i]!='o' && str_in[i]!='u' && str_in[i]!='w' && str_in[i]!='y')
        {
            if(str_out[num_out-1]!=str_in[i])
                str_out[num_out++]=str_in[i];
        }
    }
    if(strlen(str_out)==1 && strlen(str_in)>2)
        str_out[1]=str_out[0];
    strcpy(str_in, str_out);
}

void replace_letter(char* str_in)
{
    size_t size=strlen(str_in);

    for(int i=1;i<size;i++)
    {
        if(str_in[i] == 'b' || str_in[i] == 'f' || str_in[i] == 'p' || str_in[i] == 'v' )
            str_in[i]='1';
        if(str_in[i] == 'c' || str_in[i] == 'g' || str_in[i] == 'j' || str_in[i] == 'k' || str_in[i] == 'q' || str_in[i] == 's' || str_in[i] == 'x' || str_in[i] == 'z')
            str_in[i]='2';
        if(str_in[i] == 'd' || str_in[i] == 't')
            str_in[i]='3';
        if(str_in[i] == 'm' || str_in[i] == 'n' )
            str_in[i]='5';
        if(str_in[i] == 'l')
            str_in[i]='4';
        if(str_in[i] == 'r')
            str_in[i]='6';
    }
}
void replay_letter(char* str_in)
{
    size_t size = strlen(str_in);
    char str_out[MAX_LENGTH]={0};
    int num_out=1,flag=0,i=1;
    str_out[0]=str_in[0];
    while(num_out!=4)
    {
        if(i<size)
        {
            if(str_in[i]==str_in[i+1])
            {
                str_out[num_out]=str_in[i];
                while(str_out[num_out]==str_in[i])
                    i++;
                num_out++;
                i--;
            }
            else
                str_out[num_out++]=str_in[i];
            i++;
        }
        else
        {
            for(int i=num_out;i<4;i++)
            {
                str_out[i]='0';
            }
            num_out=4;
        }
    }
    strcpy(str_in, str_out);
}

void soundex(char* str_in)
{
    pass_letter(str_in);
    printf("%s\n",str_in);
    replace_letter(str_in);
    printf("%s\n",str_in);
    replay_letter(str_in);
}

int main()
{
    char str_in[MAX_LENGTH + 1];
    size_t size=readInputFile("input.txt", str_in, sizeof(str_in));
    char str_out[10]={0};
    soundex(str_in);
    writeOutputFile("output.txt",str_in);
    return 0;
}
