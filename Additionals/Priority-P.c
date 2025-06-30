#include <stdio.h>
#include <limits.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n], remaining_bt[n], ct[n], tat[n], wt[n];
    int is_completed[n];
    float avg_tat = 0, avg_wt = 0;

    printf("Enter Arrival Time, Burst Time, and Priority for each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        remaining_bt[i] = bt[i];
        is_completed[i] = 0;
    }

    int completed = 0, current_time = 0;

    while (completed != n) {
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
            remaining_bt[idx]--;

            if (remaining_bt[idx] == 0) {
                ct[idx] = current_time + 1;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                avg_tat += tat[idx];
                avg_wt += wt[idx];
                is_completed[idx] = 1;
                completed++;
            }
            current_time++;
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
