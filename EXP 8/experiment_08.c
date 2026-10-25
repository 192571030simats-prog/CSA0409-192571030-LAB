#include <stdio.h>
int main(void) {
    int n, q, bt[20], rem[20], wt[20]={0}, tat[20], i, time=0, left;
    float awt=0, atat=0;
    printf("Enter number of processes: "); scanf("%d",&n);
    for(i=0;i<n;i++){printf("Burst time for P%d: ",i+1);scanf("%d",&bt[i]);rem[i]=bt[i];}
    printf("Enter time quantum: "); scanf("%d",&q);
    if(q<=0){printf("Time quantum must be positive.\n");return 1;}
    left=n;
    while(left>0) for(i=0;i<n;i++) if(rem[i]>0){
        int run = rem[i]<q ? rem[i] : q;
        time+=run; rem[i]-=run;
        if(rem[i]==0){left--;tat[i]=time;wt[i]=tat[i]-bt[i];}
    }
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++){awt+=wt[i];atat+=tat[i];printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);}
    printf("Average WT = %.2f\nAverage TAT = %.2f\n",awt/n,atat/n);
    return 0;
}
