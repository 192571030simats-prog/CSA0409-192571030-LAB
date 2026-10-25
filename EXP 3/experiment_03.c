#include <stdio.h>
int main(void) {
    int n, bt[20], wt[20], tat[20], i;
    float awt = 0, atat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    for (i = 1; i < n; i++) wt[i] = wt[i-1] + bt[i-1];
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        awt += wt[i]; atat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time = %.2f\n", awt/n);
    printf("Average turnaround time = %.2f\n", atat/n);
    return 0;
}
