#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], arrival_time[n], waiting_time[n], turnaround_time[n], completion_time[n];
    int total_wt = 0, total_tat = 0;

    // Input: Arrival Time and Burst Time
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process P%d (Arrival Time, Burst Time): ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }

    // Sort processes by Arrival Time (FCFS Scheduling Rule)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arrival_time[i] > arrival_time[j]) {
                // Swap Arrival Times
                int temp = arrival_time[i];
                arrival_time[i] = arrival_time[j];
                arrival_time[j] = temp;

                // Swap corresponding Burst Times
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
            }
        }
    }

    // Calculate Completion Time (CT), Turnaround Time (TAT), Waiting Time (WT)
    int current_time = 0;
    for (i = 0; i < n; i++) {
        if (current_time < arrival_time[i]) {
            current_time = arrival_time[i]; // CPU idle till process arrives
        }

        completion_time[i] = current_time + burst_time[i];
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];

        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];

        current_time = completion_time[i];
    }

    // Output: Process Details
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], completion_time[i], turnaround_time[i], waiting_time[i]);
    }

    // Output: Average Waiting Time and Turnaround Time
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
