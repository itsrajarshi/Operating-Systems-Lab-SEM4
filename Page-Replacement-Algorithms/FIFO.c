#include <stdio.h>

int main() {
    int p[20], q[20], n, m, i, j, k, l = 0, fault = 0, z = 0;

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
            q[l] = p[i];
            l = (l + 1) % m;

            for (k = 0; k < m; k++)
                printf("%d\t", q[k]);
            printf("\n");
        }
    }

    printf("Number of Page faults: %d\n", fault);
    return 0;
}
