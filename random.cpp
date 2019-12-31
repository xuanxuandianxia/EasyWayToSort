#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
using namespace std;
int main(int argc,char *argv[])
{
    int limit;
    std::cout<<"This program will make 10k random number for test"<<std::endl;
    limit = atoi(argv[1]);
    std::cout<<"Start to make number"<<std::endl;
    int fd = open("random_num.txt",O_CREAT|O_WRONLY);
    if(fd<=0)
    {
        std::cout<<"file open failed"<<std::endl;
        exit(-1);
    }
    int n = 1000000;
    char * p =NULL;
    while(n--)
    {
        int x  = random()%limit;
        std::string str = to_string(x);
        str+=" ";
        p = (char*)str.data();
        write(fd,p,strlen(p));
    }
    close(fd);
    std::cout << "Complete!" << std::endl;
    return 0;
}

