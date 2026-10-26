#include <stdio.h>
int main(void){int r[]={7,0,1,2,0,3,0,4,2,3,0,3,2},f[3]={-1,-1,-1},last[3]={0},fault=0;for(int i=0;i<13;i++){int k=-1;for(int j=0;j<3;j++)if(f[j]==r[i])k=j;if(k<0){k=0;for(int j=1;j<3;j++)if(last[j]<last[k])k=j;f[k]=r[i];fault++;}last[k]=i+1;printf("%d -> %d %d %d\n",r[i],f[0],f[1],f[2]);}printf("Page faults: %d\n",fault);return 0;}
