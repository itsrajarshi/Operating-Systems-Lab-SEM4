#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int process_id[n], arrival_time[n], burst_time[n];
    int waiting_time[n], turnaround_time[n], completion_time[n];
    int total_wt = 0, total_tat = 0;

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        process_id[i] = i + 1;
        printf("Process P%d (Arrival Time, Burst Time): ", process_id[i]);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }

    // Sort based on Arrival Time first, then Burst Time (for SJF)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arrival_time[i] > arrival_time[j] || 
               (arrival_time[i] == arrival_time[j] && burst_time[i] > burst_time[j])) {
                // Swap Arrival Time
                int temp = arrival_time[i];
                arrival_time[i] = arrival_time[j];
                arrival_time[j] = temp;

                // Swap Burst Time
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                // Swap Process ID
                temp = process_id[i];
                process_id[i] = process_id[j];
                process_id[j] = temp;
            }
        }
    }

    int completed[n];
    for (i = 0; i < n; i++) completed[i] = 0;

    int current_time = 0, completed_processes = 0;

    while (completed_processes < n) {
        int idx = -1, min_bt = 9999;

        for (i = 0; i < n; i++) {
            if (arrival_time[i] <= current_time && !completed[i] && burst_time[i] < min_bt) {
                min_bt = burst_time[i];
                idx = i;
            }
        }

        if (idx != -1) {
            current_time += burst_time[idx];
            completion_time[idx] = current_time;
            turnaround_time[idx] = completion_time[idx] - arrival_time[idx];
            waiting_time[idx] = turnaround_time[idx] - burst_time[idx];
            total_wt += waiting_time[idx];
            total_tat += turnaround_time[idx];
            completed[idx] = 1;
            completed_processes++;
        } else {
            current_time++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", process_id[i], arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);

    return 0;
}
