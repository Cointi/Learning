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

void writeOutputFile(const char *filename, const int *str, size_t Length)
{
    FILE *file = fopen(filename, "w");
    for(int i=0;i<Length;i++)
    {
        fprintf(file, "%d ", str[i]);
        printf("%d ", str[i]);
    }
    fclose(file);
}

int search_numbers( char* str, int size, int* numbers)
{
    int num_count=0;
    for(int i=0;i<size;i++)
    {
        if('0'<=str[i] && str[i]<='9')
        {
            int k=10;
            while('0'<=str[i] && str[i]<='9')
            {
                numbers[num_count]=numbers[num_count]*k+(str[i]-'0');
                i++;
            }
            num_count++;
        }
    }
    return num_count;
}

void sort_buf(int* arr, int size)
{
    int noSwap;
    for (int i = 0; i < size; i++)
    {
        noSwap = 1;
        for (int j = size-1; j > i; j--)
        {
            if(arr[j-1]>arr[j])
            {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
                noSwap = 0;
            }
        }
        if(noSwap)
            break;
    }
}

int main()
{
    FILE *out;
    char str[MAX_LENGTH + 1]={0};
    int numbers[1000]={0};
    size_t size_num=0;
    size_t size_str = readInputFile("input.txt", str, sizeof(str));
    size_num = search_numbers(str, size_str, numbers);
    sort_buf(numbers, size_num);
    writeOutputFile("output.txt", numbers, size_num);
    return 0;
}
