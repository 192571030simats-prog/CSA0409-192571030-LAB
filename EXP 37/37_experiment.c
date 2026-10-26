#include <stdio.h>
#include <stdlib.h>
int main(void){int q[]={98,183,37,122,14,124,65,67},head=53,total=0;printf("Head movement: %d",head);for(int i=0;i<8;i++){total+=abs(head-q[i]);head=q[i];printf(" -> %d",head);}printf("\nTotal head movement: %d cylinders\n",total);return 0;}
