#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main(void){const char*f="exp40_permissions.txt";FILE*p=fopen(f,"w");if(!p)return 1;fputs("permission demo\n",p);fclose(p);chmod(f,0640);struct stat s;if(stat(f,&s)==0){printf("File: %s\nPermissions: %04o\n",f,s.st_mode&0777);puts("Owner: read/write; Group: read; Others: no access");puts("Users: owner (u), group (g), others (o)");puts("Example command: chmod 640 exp40_permissions.txt");}return 0;}
