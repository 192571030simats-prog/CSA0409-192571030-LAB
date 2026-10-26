#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}int main(void){int q[]={98,183,37,122,14,124,65,67},n=8,head=53,max=199,total=0;qsort(q,n,sizeof(int),cmp);printf("C-SCAN path: %d",head);for(int i=0;i<n;i++)if(q[i]>=head){total+=abs(head-q[i]);head=q[i];printf(" -> %d",head);}total+=max-head;head=0;total+=max;printf(" -> 199 -> 0");for(int i=0;i<n;i++)if(q[i]<53){total+=abs(head-q[i]);head=q[i];printf(" -> %d",head);}printf("\nTotal head movement (including wrap): %d\n",total);return 0;}
