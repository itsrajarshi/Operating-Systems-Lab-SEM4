#include <stdio.h>

int main() {
    int p[20], q[20], x[20];
    int n, m, i, j, k, l = 0, fault = 0, z = 0;
    int max, c, b, a;

    printf("Enter No. of Pages: ");
    scanf("%d", &n);

    printf("Enter Pages: ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter No. of Frames: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
        q[i] = -1;

    for (i = 0; i < n; i++) {
        int hit = 0;
        for (j = 0; j < m; j++) {
            if (p[i] == q[j]) {
                hit = 1;
                break;
            }
        }

        if (!hit) {
            fault++;

            // If frame full
            if (i >= m) {
                for (a = 0; a < m; a++)
                    x[a] = 0;

                for (c = 0; c < m; c++) {
                    x[c] = 0;
                    for (b = i + 1; b < n; b++) {
                        x[c]++;
                        if (q[c] == p[b])
                            break;
                    }
                    // If page not found in future, set distance very high
                    if (b == n)
                        x[c] = 999;
                }

                // Find the frame with maximum distance (farthest future use)
                max = x[0];
                l = 0;
                for (k = 1; k < m; k++) {
                    if (x[k] > max) {
                        max = x[k];
                        l = k;
                    }
                }
            }

            // Replace
            q[l] = p[i];

            // If frames not yet full
            if (i < m)
                l++;

            // Print frame state
            for (k = 0; k < m; k++)
                printf("%d\t", q[k]);
            printf("\n");
        }
    }

    printf("No. of Page faults: %d\n", fault);
    return 0;
}
