#include <stdio.h>

int waitingtime(int proc[], int n, int burst_time[], int wait_time[]) {
    wait_time[0] = 0;
    for (int i = 1; i < n ; i++ )
    wait_time[i] = burst_time[i-1] + wait_time[i-1] ;
    return 0;
}

int turnaroundtime( int proc[], int n, int burst_time[], int wait_time[], int tat[]) {
    int i;
    for ( i = 0; i < n ; i++)
    tat[i] = burst_time[i] + wait_time[i];
    return 0;
}

int avgtime( int proc[], int n, int burst_time[]) {
    int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
    int i;

    waitingtime(proc, n, burst_time, wait_time);
    turnaroundtime(proc, n, burst_time, wait_time, tat);
    printf("Processes\tBurst\tWaiting\tTurn around \n");

    for (i=0; i<n; i++) {
        total_wt = total_wt + wait_time[i];
        total_tat = total_tat + tat[i];
        printf(" %d\t %d\t %d \t%d\n", i+1, burst_time[i], wait_time[i], tat[i]);
    }
    printf("Average waiting time = %f\n", (float)total_wt / (float)n);
    printf("Average turn around time = %f\n", (float)total_tat / (float)n);
    return 0;
}

int main() {

    int n;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    int proc[n], burst_time[n];
    printf("\nEnter the burst time for all the processes: \n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        scanf("%d", &burst_time[i]);            
    }
    avgtime(proc, n, burst_time);
    return 0;
}