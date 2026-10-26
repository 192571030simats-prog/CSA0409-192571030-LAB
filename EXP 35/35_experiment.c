#include <stdio.h>
int main(void){int index[]={9,16,1,10,25};puts("Index block contains:");for(int i=0;i<5;i++)printf("Record/block %d -> disk block %d\n",i+1,index[i]);printf("Access record 3: disk block %d\n",index[2]);return 0;}
