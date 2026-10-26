#include <stdio.h>
#include <string.h>
int main(void){char key[]="OS",line[120];int n=0;FILE*f=fopen("grep_sample.txt","w+");fputs("Operating Systems\nComputer Networks\nOS Lab Experiment\nBiology\n",f);rewind(f);printf("Lines containing '%s':\n",key);while(fgets(line,sizeof line,f))if(strstr(line,key)){printf("%s",line);n++;}printf("Matches: %d\n",n);fclose(f);return 0;}
