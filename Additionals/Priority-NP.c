#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, count;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n], ct[n], tat[n], wt[n], is_completed[n];
    float avg_tat = 0, avg_wt = 0;

    printf("Enter Arrival Time, Burst Time, and Priority for each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        is_completed[i] = 0;
    }

    int current_time = 0;

    for (count = 0; count < n; count++) {
        int idx = -1;
        int highest_priority = INT_MAX;

        for (i = 0; i < n; i++) {
            if (at[i] <= current_time && !is_completed[i]) {
                if (pr[i] < highest_priority) {
                    highest_priority = pr[i];
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            current_time = (current_time < at[idx]) ? at[idx] : current_time;
            ct[idx] = current_time + bt[idx];
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            is_completed[idx] = 1;
            current_time = ct[idx];
            avg_tat += tat[idx];
            avg_wt += wt[idx];
        } else {
            current_time++;
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    avg_tat /= n;
    avg_wt /= n;
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);

    return 0;
}
