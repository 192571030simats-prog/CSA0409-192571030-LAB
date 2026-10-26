#include <stdio.h>
int main(void){int b[]={100,500,200,300,600},p[]={212,417,112,426},n=5,m=4,a[4];for(int i=0;i<m;i++)a[i]=-1;for(int i=0;i<m;i++){int w=-1;for(int j=0;j<n;j++)if(b[j]>=p[i]&&(w<0||b[j]>b[w]))w=j;if(w>=0){a[i]=w;b[w]-=p[i];}}puts("Process\tSize\tBlock");for(int i=0;i<m;i++)printf("P%d\t%d\t%s%d\n",i+1,p[i],a[i]<0?"Not allocated":"B",a[i]<0?0:a[i]+1);return 0;}
