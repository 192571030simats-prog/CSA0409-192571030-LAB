#include <stdio.h>
int main(void) {
    int n, i, time=0, done=0, bt[20], rem[20], pr[20], wt[20]={0}, tat[20]={0};
    printf("Enter number of processes: "); scanf("%d",&n);
    for(i=0;i<n;i++){printf("Burst time and priority for P%d: ",i+1);scanf("%d%d",&bt[i],&pr[i]);rem[i]=bt[i];}
    while(done<n){
        int k=-1;
        for(i=0;i<n;i++) if(rem[i]>0 && (k==-1 || pr[i]<pr[k])) k=i;
        if(k==-1) break;
        rem[k]--; time++;
        if(rem[k]==0){done++;tat[k]=time;wt[k]=tat[k]-bt[k];}
    }
    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for(i=0;i<n;i++) printf("P%d\t%d\t%d\t\t%d\t%d\n",i+1,bt[i],pr[i],wt[i],tat[i]);
    return 0;
}
