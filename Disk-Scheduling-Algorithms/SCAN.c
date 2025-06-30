#include <stdio.h>

int main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], sum = 0, p;
    
    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the initial position of the head: ");
    scanf("%d", &h);

    t[0] = 0;          // Assuming disk start (track 0)
    t[1] = h;          // Current head position

    printf("Enter the track numbers: ");
    for (i = 2; i < n + 2; i++)
        scanf("%d", &t[i]);

    // Total elements = n + 2 (0 + head + n tracks)
    int totalTracks = n + 2;

    // Sort the tracks (including head and 0)
    for (i = 0; i < totalTracks - 1; i++) {
        for (j = 0; j < totalTracks - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find index of head position after sorting
    for (i = 0; i < totalTracks; i++) {
        if (t[i] == h) {
            j = i;
            break;
        }
    }

    // SCAN movement: first left from head to 0, then right till end
    p = 0;

    // Move left from head to 0
    for (k = j; k >= 0; k--)
        atr[p++] = t[k];

    // Move right from head to highest track
    for (k = j + 1; k < totalTracks; k++)
        atr[p++] = t[k];

    // Calculate total head movements
    for (i = 0; i < totalTracks - 1; i++) {
        d[i] = (atr[i] > atr[i + 1]) ? (atr[i] - atr[i + 1]) : (atr[i + 1] - atr[i]);
        sum += d[i];
    }

    printf("\nTrack Traversal Order:\n");
    for (i = 0; i < totalTracks; i++)
        printf("%d ", atr[i]);

    printf("\n\nTotal Head Movements: %d", sum);
    printf("\nAverage Head Movement: %.2f\n", (float)sum / n);

    return 0;
}
