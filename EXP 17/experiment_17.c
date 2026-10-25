#include <stdio.h>
int main(void) {
    int n,m,i,j,alloc[10][10],max[10][10],avail[10],need[10][10],finish[10]={0},safe[10],count=0;
    printf("Processes and resources: "); scanf("%d%d",&n,&m);
    printf("Enter allocation matrix:\n");
    for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&alloc[i][j]);
    printf("Enter maximum matrix:\n");
    for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&max[i][j]);
    printf("Enter available resources: ");
    for(j=0;j<m;j++) scanf("%d",&avail[j]);
    for(i=0;i<n;i++) for(j=0;j<m;j++) need[i][j]=max[i][j]-alloc[i][j];
    while(count<n){
        int found=0;
        for(i=0;i<n;i++) if(!finish[i]){
            for(j=0;j<m;j++) if(need[i][j]>avail[j]) break;
            if(j==m){for(j=0;j<m;j++) avail[j]+=alloc[i][j];safe[count++]=i;finish[i]=1;found=1;}
        }
        if(!found) break;
    }
    if(count==n){printf("Safe sequence: ");for(i=0;i<n;i++)printf("P%d%s",safe[i],i==n-1?"\n":" -> ");}
    else printf("System is not in a safe state.\n");
    return 0;
}
