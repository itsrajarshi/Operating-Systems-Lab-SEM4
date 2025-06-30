#include <stdio.h>
#include <limits.h> // For INT_MAX

int main() {
    int n, i, smallest, time = 0, completed = 0;
    int arrival_time[20], burst_time[20], remaining_time[20];
    int waiting_time[20], turnaround_time[20], completion_time[20];
    int total_wt = 0, total_tat = 0;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input arrival time and burst time for each process
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process P%d (Arrival Time, Burst Time): ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        remaining_time[i] = burst_time[i];  // Initialize remaining time as burst time
    }

    // SRTF Scheduling Algorithm (Preemptive SJF)
    while (completed != n) {
        smallest = -1;
        int min_time = INT_MAX;

        // Find process with the shortest remaining time at current time
        for (i = 0; i < n; i++) {
            if (arrival_time[i] <= time && remaining_time[i] > 0 && remaining_time[i] < min_time) {
                min_time = remaining_time[i];
                smallest = i;
            }
        }

        if (smallest == -1) {
            time++;  // No available process, CPU is idle
            continue;
        }

        // Run the selected process for 1 unit time
        remaining_time[smallest]--;
        time++;

        // If process completed
        if (remaining_time[smallest] == 0) {
            completed++;

            completion_time[smallest] = time;
            turnaround_time[smallest] = completion_time[smallest] - arrival_time[smallest];
            waiting_time[smallest] = turnaround_time[smallest] - burst_time[smallest];

            total_wt += waiting_time[smallest];
            total_tat += turnaround_time[smallest];
        }
    }

    // Output results
    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_tat / n);

    return 0;
}
