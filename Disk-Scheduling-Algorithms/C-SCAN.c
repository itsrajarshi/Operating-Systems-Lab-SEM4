#include <stdio.h>

int main() {
    int t[50], atr[50], d[50];
    int n, i, j, temp, h, tot, headIndex = 0, p = 0, sum = 0;

    printf("Enter the number of track requests: ");
    scanf("%d", &n);

    printf("Enter the current position of the head: ");
    scanf("%d", &h);

    printf("Enter total number of tracks (disk size): ");
    scanf("%d", &tot);

    t[0] = 0;        // Start of disk
    t[1] = h;        // Current head position
    t[2] = tot - 1;  // End of disk

    printf("Enter the track numbers to be accessed: ");
    for (i = 3; i < n + 3; i++)
        scanf("%d", &t[i]);

    int totalTracks = n + 3;  // Total elements including 0, head, and tot-1

    // Sort the track array
    for (i = 0; i < totalTracks - 1; i++) {
        for (j = 0; j < totalTracks - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find head index after sorting
    for (i = 0; i < totalTracks; i++) {
        if (t[i] == h) {
            headIndex = i;
            break;
        }
    }

    // C-SCAN: From head towards end, then jump to start, then from start up to before head
    p = 0;

    // From head to highest track
    for (i = headIndex; i < totalTracks; i++)
        atr[p++] = t[i];

    // From start (0) to just before head
    for (i = 0; i < headIndex; i++)
        atr[p++] = t[i];

    // Calculate total head movement
    for (i = 0; i < p - 1; i++) {
        d[i] = (atr[i] > atr[i + 1]) ? (atr[i] - atr[i + 1]) : (atr[i + 1] - atr[i]);
        sum += d[i];
    }

    // Output
    printf("\nC-SCAN Track Traversal Order:\n");
    for (i = 0; i < p; i++)
        printf("%d ", atr[i]);

    printf("\n\nTotal Head Movements: %d", sum);
    printf("\nAverage Head Movement: %.2f\n", (float)sum / n);

    return 0;
}
