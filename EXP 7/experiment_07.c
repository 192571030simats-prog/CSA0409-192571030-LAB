#include <stdio.h>
int main(void) {
    int n, at[20], bt[20], p[20], done[20]={0}, wt[20]={0}, tat[20]={0};
    int time=0, completed=0, i, k;
    float awt=0, atat=0;
    printf("Enter number of processes: "); scanf("%d",&n);
    for(i=0;i<n;i++){p[i]=i+1;printf("Arrival and burst time for P%d: ",i+1);scanf("%d%d",&at[i],&bt[i]);}
    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    while(completed<n){
        k=-1;
        for(i=0;i<n;i++) if(!done[i] && at[i]<=time && (k==-1 || bt[i]<bt[k])) k=i;
        if(k==-1){time++;continue;}
        wt[k]=time-at[k]; time+=bt[k]; tat[k]=time-at[k]; done[k]=1; completed++;
        awt+=wt[k]; atat+=tat[k];
        printf("P%d\t%d\t%d\t%d\t%d\n",p[k],at[k],bt[k],wt[k],tat[k]);
    }
    printf("Average WT = %.2f\nAverage TAT = %.2f\n",awt/n,atat/n);
    return 0;
}
