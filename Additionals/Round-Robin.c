#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, quantum, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burstTime[n], arrivalTime[n], remainingTime[n];
    int waitTime[n], turnaroundTime[n];
    int time = 0, completed = 0;
    bool inQueue[n];

    printf("Enter Burst Time and Arrival Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &burstTime[i], &arrivalTime[i]);
        remainingTime[i] = burstTime[i];
        waitTime[i] = 0;
        inQueue[i] = false;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    int queue[100], front = 0, rear = 0;

    // Initially add processes that arrived at time 0
    for (i = 0; i < n; i++) {
        if (arrivalTime[i] == 0) {
            queue[rear++] = i;
            inQueue[i] = true;
        }
    }

    while (completed < n) {
        if (front == rear) {  // Queue empty (CPU idle time)
            time++;
            for (i = 0; i < n; i++) {
                if (!inQueue[i] && arrivalTime[i] <= time) {
                    queue[rear++] = i;
                    inQueue[i] = true;
                }
            }
            continue;
        }

        int idx = queue[front++];  // Dequeue

        if (remainingTime[idx] > quantum) {
            time += quantum;
            remainingTime[idx] -= quantum;
        } else {
            time += remainingTime[idx];
            waitTime[idx] = time - burstTime[idx] - arrivalTime[idx];
            remainingTime[idx] = 0;
            completed++;
        }

        // Enqueue newly arrived processes during this time
        for (j = 0; j < n; j++) {
            if (!inQueue[j] && arrivalTime[j] <= time) {
                queue[rear++] = j;
                inQueue[j] = true;
            }
        }

        // If not completed, put back in queue
        if (remainingTime[idx] > 0) {
            queue[rear++] = idx;
        }
    }

    for (i = 0; i < n; i++) {
        turnaroundTime[i] = burstTime[i] + waitTime[i];
    }

    printf("\nProcess\tBT\tAT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, burstTime[i], arrivalTime[i], waitTime[i], turnaroundTime[i]);
    }

    float avgWait = 0, avgTat = 0;
    for (i = 0; i < n; i++) {
        avgWait += waitTime[i];
        avgTat += turnaroundTime[i];
    }
    printf("\nAverage Waiting Time: %.2f", avgWait / n);
    printf("\nAverage Turnaround Time: %.2f\n", avgTat / n);

    return 0;
}
