#include <stdio.h>
#include <string.h>
int main(void){FILE*f=fopen("exp26.txt","w+");if(!f){perror("fopen");return 1;}fputs("Operating Systems Lab",f);printf("File created and written.\n");rewind(f);char b[80];fgets(b,sizeof b,f);printf("Read: %s\n",b);fclose(f);if(remove("exp26.txt")==0)puts("File deleted successfully.");return 0;}
