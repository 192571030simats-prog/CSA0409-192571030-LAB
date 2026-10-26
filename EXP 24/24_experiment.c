#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(void){char *f="exp24.txt",msg[]="File system calls demo\n",buf[100]={0};int fd=open(f,O_CREAT|O_WRONLY|O_TRUNC,0644);if(fd<0){perror("open");return 1;}write(fd,msg,strlen(msg));close(fd);fd=open(f,O_RDONLY);int n=read(fd,buf,99);if(n>=0)buf[n]=0;close(fd);printf("Created and read %s: %s",f,buf);return 0;}
