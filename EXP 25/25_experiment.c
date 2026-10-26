#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
int main(void){int fd=open("exp25.txt",O_CREAT|O_RDWR|O_TRUNC,0644);write(fd,"HELLO",5);printf("fcntl flags: %d\n",fcntl(fd,F_GETFL));lseek(fd,0,SEEK_SET);char b[6]={0};read(fd,b,5);printf("lseek/read: %s\n",b);struct stat s;if(stat("exp25.txt",&s)==0)printf("stat size: %ld bytes\n",(long)s.st_size);close(fd);DIR*d=opendir(".");struct dirent*e;puts("readdir sample:");int k=0;while(d&&(e=readdir(d))&&k<4){puts(e->d_name);k++;}if(d)closedir(d);return 0;}
