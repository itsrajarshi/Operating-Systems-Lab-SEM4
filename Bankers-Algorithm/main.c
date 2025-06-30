#include <stdio.h>

int main() {
    int n, m, i, j, k;
    int alloc[10][10], max[10][10], avail[10];
    int need[10][10], finish[10], safeSeq[10];
    int count = 0, flag, found;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    printf("Enter allocation matrix:\n");
    for (i = 0; i < n; i++) {
        printf("Allocation for process %d: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }

    printf("Enter maximum demand matrix:\n");
    for (i = 0; i < n; i++) {
        printf("Maximum for process %d: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    printf("Enter available resources: ");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Calculate need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Initialize finish array
    for (i = 0; i < n; i++)
        finish[i] = 0;

    // Banker's Algorithm
    while (count < n) {
        found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                flag = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 0;
                        break;
                    }
                }

                if (flag == 1) {
                    for (k = 0; k < m; k++)
                        avail[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("\nSystem is not in a safe state! Deadlock may occur.\n");
            return 1;
        }
    }

    // Safe sequence exists
    printf("\nSystem is in a safe state.\nSafe sequence: ");
    for (i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}
