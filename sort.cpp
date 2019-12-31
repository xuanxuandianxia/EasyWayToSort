#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
using std::cout;
using std::cin;
using std::string;
using std::endl;

const int num_size = 1000000;
const int max_size =1024;
const char * file_name  ="Sorted_num.txt";


int* buffer;
int result;
int x;

void made_array(int);
void let_input();
void get_resultASC();
void get_resultDESC();

int main(int argc,char * argv[])
{
    if(argc<2)
    {
        cout<<"To use this program must input at least one parama as The biggest number"<<endl;
        return -1;
    }
    
    if(argv[1][0]>'0'&&argv[1][0]<='9')
    {
        string str = argv[1];
        result = atoi(str.c_str());
        cout<<"cur array lenth is "<<result<<endl;
        made_array(result);
        let_input();
        while(1){
        cout<<"Which order you want?ASC or DESC ：（a|d)"<<endl;
        char a;
        cin>>a;
        if(a == 'a')
        {
            get_resultASC();
            break;
        }
        else if(a=='d')
        {
            get_resultDESC();
            break;
        }
        
    }
    }
    else if(argv[1][0]=='0')
    {
        cout<<"Nothing to do!"<<endl;
    }
    else 
    {
        cout<<"You should put a number as a parama!"<<endl;
        return -2;
    }
    return 0;
}


void made_array(int size)
{
    const int sizes=size +1;
    buffer = new int[size];
}

void let_input()
{
    cout<<"Got it !Start reading files!"<<endl;

    x = num_size;
    int cur = 0;
    int fd = open("./random_num.txt",O_RDONLY);

    if(fd<0)
    {
        cout<<"open file failed"<<endl;
        exit(-1);
    }

    int seeker=0;
    char * buf = new char[max_size];
    string value = "";
    while(read(fd,buf,max_size))
    {
        seeker+=1024;
        for(int i =0;i<max_size;i++)
        {
           
            if(buf[i]!=' ')
            {
                value+= buf[i];
            }
            else 
            {
                int x = atoi(value.c_str());
                buffer[x]++;
                value = "";
            }
        }
        lseek(fd,seeker,SEEK_SET);
    }
}

void get_resultASC()
{
    int fd = open(file_name,O_RDWR|O_CREAT);
    if(fd<0)
    {
        perror("open");
        exit(-1);
    }
    cout<<"Now get the result:"<<endl;
   for(int i =0;i<=result;i++)
   {
       while(buffer[i]!=0)
       {
           string value = std::to_string(i);
           value += " ";
           write(fd,value.c_str(),value.length());
           --buffer[i];
       }
   }
  cout<<"The Result saved at current dir which named Sorted_num.txt"<<endl;
}

void get_resultDESC()
{
    int fd = open(file_name,O_RDWR|O_CREAT);
    if(fd<0)
    {
        perror("open");
        exit(-1);
    }
    cout<<"Now get the result!"<<endl;
    for(int i=result;i>=0;i--)
    {
        while(buffer[i]!=0)
        {

           string value = std::to_string(i);
           value += " ";
           write(fd,value.c_str(),value.length());
           --buffer[i];

        }
    }
    cout<<"The Result saved at current dir which named Sorted_num.txt"<<endl;
}





