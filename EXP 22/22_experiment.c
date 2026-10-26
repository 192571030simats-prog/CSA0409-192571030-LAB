#include <stdio.h>
int main(void){int b[]={100,500,200,300,600},p[]={212,417,112,426},n=5,m=4,a[4];for(int i=0;i<m;i++)a[i]=-1;for(int i=0;i<m;i++){int w=-1;for(int j=0;j<n;j++)if(b[j]>=p[i]&&(w<0||b[j]<b[w]))w=j;if(w>=0){a[i]=w;b[w]-=p[i];}}puts("Process\tSize\tBlock");for(int i=0;i<m;i++){printf("P%d\t%d\t",i+1,p[i]);if(a[i]<0)puts("Not allocated");else printf("B%d\n",a[i]+1);}return 0;}
