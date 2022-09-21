#include<stdio.h>
 
int main() {
 
    int i, j, n, time, remain, flag=0, quantum;
    int wait_time = 0,turnaround_time = 0, at[10], bt[10], rt[10];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    remain = n;
    for(i = 0; i < n; i++) {
        printf("\nEnter the details of Process %d:\n", i + 1);
        printf("Enter the arrival time: ");
        scanf("%d",&at[i]);
        printf("Enter the burst time: ");
        scanf("%d",&bt[i]);
        rt[i] = bt[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &quantum);
    printf("\nProcess\t Turnaround Time  Waiting Time\n");
    for(time = 0, i = 0; remain!=0;) {
        if(rt[i] <= quantum && rt[i] > 0) {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if(rt[i]>0) {
            rt[i] -= quantum;
            time += quantum;
        }
        if(rt[i]==0 && flag==1) {
            remain--;
            printf("P%d\t\t%d\t\t%d\n", i + 1, time - at[i], time - at[i] - bt[i]);
            wait_time += time - at[i] - bt[i];
            turnaround_time += time - at[i];
            flag = 0;
        }

        if(i == n-1)
            i = 0;
        else if(at[i+1] <= time)
            i++;
        else
            i = 0;
    }

    printf("\nAverage Waiting Time: %f", (wait_time * 1.0/n));
    printf("\nAverage Turnaround Time: %f\n", (turnaround_time * 1.0/n));

    return 0;
}