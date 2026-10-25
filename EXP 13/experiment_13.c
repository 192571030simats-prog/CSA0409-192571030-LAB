#include <stdio.h>
int main(void) {
    int b[10], p[10], nb, np, i, j, choice, alloc[10];
    printf("Number of memory blocks: "); scanf("%d",&nb);
    printf("Enter block sizes: ");
    for(i=0;i<nb;i++) scanf("%d",&b[i]);
    printf("Number of processes: "); scanf("%d",&np);
    printf("Enter process sizes: ");
    for(i=0;i<np;i++) scanf("%d",&p[i]);
    printf("1.First Fit 2.Best Fit 3.Worst Fit: "); scanf("%d",&choice);
    for(i=0;i<np;i++) alloc[i]=-1;
    for(i=0;i<np;i++){
        int idx=-1;
        for(j=0;j<nb;j++) if(b[j]>=p[i]){
            if(choice==1){idx=j;break;}
            if(choice==2 && (idx==-1 || b[j]<b[idx])) idx=j;
            if(choice==3 && (idx==-1 || b[j]>b[idx])) idx=j;
        }
        if(idx!=-1){alloc[i]=idx;b[idx]-=p[i];}
    }
    printf("\nProcess\tSize\tBlock\n");
    for(i=0;i<np;i++) if(alloc[i]!=-1) printf("P%d\t%d\t%d\n",i+1,p[i],alloc[i]+1);
        else printf("P%d\t%d\tNot allocated\n",i+1,p[i]);
    return 0;
}
