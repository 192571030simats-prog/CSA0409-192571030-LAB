#include <stdio.h>
#include <dirent.h>
int main(void){DIR*d=opendir(".");if(!d){perror("opendir");return 1;}struct dirent*e;puts("Directory contents:");while((e=readdir(d))!=NULL)if(e->d_name[0]!='.')puts(e->d_name);closedir(d);return 0;}
