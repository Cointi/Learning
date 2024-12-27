#include <stdio.h>
#include <string.h>


void Print(int* arr, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}


int Input(int* s)
{
    int lenght=0;
    scanf("%[^.]",s);
    lenght=strlen(s);
    return lenght;
}
/*int Input(int* arr)
{
    int lenght=0;
    int size=0;
    int num=0;
    int flag=0;
    char s[5000]={0};
    scanf("%[^\n]",s);
    lenght=strlen(s);
    for(int i=0;i<lenght;i++)
    {
        if(s[i]==' ')
        {
            if(flag)
            {
                arr[size++]=num;
                num=0;
                flag=0;
            }
        }
        else
        {
            flag=1;
            num=num*10+(s[i]-'0');
        }

    }
    if(flag)
    {
        arr[size++]=num;
        num=0;
        flag=0;
    }
    return size;
}*/
void compression(char s[], int N)
{
    char s_out[100]={0};
    int size_out=0;
    int count=1;
    int flag=1;
    for(int i=0; i<N; i++)
    {
        if(flag==1)
        {
            s_out[size_out++]=s[i];
        }
        if((i+1)!=N && s[i]==s[i+1])
        {
            count++;
            flag=0;
        }
        else
        {
            char buf[10]={0};
            int u=0;
            while(count>0)
            {
                buf[u++]=(((char*)(count%10))+'0');
                count/=10;
            }
            for(int h=u-1;h>=0;h--)
            {
                s_out[size_out++]=buf[h];
            }
            flag=1;
            count=1;
        }
    }

    for(int j=0; j<size_out;j++)
        printf("%c", s_out[j]);
}



int main(int argc, char **argv)
{
    int size=0;
    char s[1000]={0};
    int size_out=0;
    size=Input(s);
    //for(int i=0; i<16;i++)
        //printf("%c", ((char*)i+'0'));
    compression(s, size);
    return 0;
}

