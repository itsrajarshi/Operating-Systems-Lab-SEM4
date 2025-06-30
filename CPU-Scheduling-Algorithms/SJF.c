#include <stdio.h>

int main() {
    int n, i, j, a[100], wt[100], ct[100], temp[100], tat[100], twt = 0, ttat = 0;
    float awt, atat;

    temp[0] = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    // Insertion Sort: Sort burst times (SJF)
    for (i = 1; i < n; i++) {
        int key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    // Calculating Waiting Time, Completion Time, and Turnaround Time
    for (i = 0; i < n; i++) {
        wt[i] = temp[i];
        twt += wt[i];

        ct[i] = temp[i] + a[i];
        temp[i + 1] = ct[i];

        tat[i] = ct[i];  // Assuming Arrival Time = 0
        ttat += tat[i];
    }

    awt = (float)twt / n;
    atat = (float)ttat / n;

    printf("\nProcess\tBurst Time\tWaiting Time\tCompletion Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, a[i], wt[i], ct[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", awt);
    printf("Average Turnaround Time: %.2f\n", atat);

    return 0;
}
