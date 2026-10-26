#include <stdio.h>
int main(void){int ref[]={7,0,1,2,0,3,0,4,2,3,0,3,2},f[3]={-1,-1,-1},next=0,fault=0;for(int i=0;i<13;i++){int hit=0;for(int j=0;j<3;j++)if(f[j]==ref[i])hit=1;if(!hit){f[next]=ref[i];next=(next+1)%3;fault++;}printf("%d -> %d %d %d %s\n",ref[i],f[0],f[1],f[2],hit?"Hit":"Fault");}printf("Page faults: %d\n",fault);return 0;}
