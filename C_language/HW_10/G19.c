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


void num_repeat(char* arr, char* letter, int* number)
{
    int num=1,flag=0,num_letter=0, num_number=0;
    size_t size=strlen(arr);
    for(int i=0;i<size;i++)
    {
        for(int y=0;y<num_letter;y++)
        {
            if(arr[i]==letter[y])
                {
                    flag=1;
                    break;
                }
        }
        for(int j=size-1;j>i;j--)
        {
            if(flag==1)
                break;
            if(arr[j]==arr[i])
                num++;
        }
        if(flag==0)
        {
            letter[num_letter]=arr[i];
            printf("letter = %c ",letter[num_letter]);
            num_letter++;
            number[num_number]=num;
            printf("number = %d\n",number[num_number]);
            num_number++;
        }
        num=1;
        flag=0;
    }
}
void lex_order(char* word,int* num)
{
    int size = strlen(word);
    int flag=0;
    for(int i=size-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if((num[i]>=2))
            {
                char tmp=word[i];
                word[i]=word[j];
                word[j]=tmp;
                int h=num[i];
                num[i]=num[j];
                num[j]=h;
            }
            if((word[j]>word[i])&&(num[i]>=2))
            {
                char tmp=word[i];
                word[i]=word[j];
                word[j]=tmp;
                int h=num[i];
                num[i]=num[j];
                num[j]=h;
            }

           if((word[j]>word[i])&&(num[i]==1)&&(num[j]==1))
            {
                char tmp=word[i];
                word[i]=word[j];
                word[j]=tmp;
                flag=1;
            }
            if((num[i]==1)||(num[j]==1))
                flag=1;

        }
    }
    printf("%s\n",word);
        for(int j=0;j<size;j++)
        {
            if(num[j]%2!=0)
            {
                word[size]=word[j];
                num[size]=1;
                num[j]--;
                break;
            }
        }

}

void palindrom(char* word, int* num)
{
    int num_res=0;
    int size = strlen(word);
    char result[MAX_LENGTH]={0};
        for(int i=0;i<size;i++)
        {
           if(num[i]==1)
            {
                break;
            }
            if(num[i]==2)
                result[num_res++]=word[i];
            if(num[i]>2)
            {
                int tmp=num[i];
                while(num[i]>=2)
                {
                   result[num_res++]=word[i];
                   num[i]-=2;
                }
                num[i]=tmp;
            }
        }
        int hot=0;
        for(int i=size-1;i>=0;i--)
        {

            if(num[i]==1 && hot==0)
            {
                result[num_res++]=word[i];
                hot=1;
            }
            if(num[i]==2)
                result[num_res++]=word[i];
            if(num[i]>2)
            {
                int tmp=num[i];
                while(num[i]>=2)
                {
                    //printf("%d ", num[i]);
                   result[num_res++]=word[i];
                   num[i]-=2;
                }
                num[i]=tmp;
            }
        }
    }
    printf("%s\n",result);
    writeOutputFile("output.txt",result);
}

int main()
{
    char str_in[MAX_LENGTH + 1];
    readInputFile("input.txt", str_in, sizeof(str_in));
    char letter[MAX_LENGTH+ 1]={0};
    int number[MAX_LENGTH+ 1]={0};
    //printf("%d\n",size);
    num_repeat(str_in, letter, number);
    lex_order(letter,number);
    printf("%s\n", letter);
    for(int i=0;i<strlen(letter);i++)
    printf("%d",number[i]);
    printf("\n");
    palindrom(letter, number);
    //writeOutputFile("output.txt",str_out);
    return 0;
}
