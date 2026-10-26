#include <stdio.h>
int main(void){int start=4,len=5;printf("Sequential allocation\nFile starts at block %d, length %d\n",start,len);printf("Allocated blocks: ");for(int i=0;i<len;i++)printf("%d ",start+i);printf("\nRecord 4 is at block %d\n",start+3);return 0;}
