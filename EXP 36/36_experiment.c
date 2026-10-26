#include <stdio.h>
struct Block{int id,next;};int main(void){struct Block b[]={{7,19},{19,3},{3,24},{24,-1}};puts("Linked file allocation (block -> next)");for(int i=0;i<4;i++)printf("%d -> %s",b[i].id,b[i].next<0?"NULL\n":"");for(int i=0;i<3;i++)printf("%d -> %d\n",b[i].id,b[i].next);printf("Start block: %d, End block: %d\n",b[0].id,b[3].id);return 0;}
