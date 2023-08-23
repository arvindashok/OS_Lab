#include <stdio.h>

int main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum = 0;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of the head: ");
    scanf("%d", &h);

    t[0] = 0;
    t[1] = h;

    printf("Enter total tracks: ");
    scanf("%d", &tot);

    t[2] = tot - 1;

    printf("Enter the tracks:\n");
    for (i = 3; i <= n + 2; i++) {
        scanf("%d", &t[i]);
    }

    // Bubble sort the tracks array
    for (i = 0; i <= n + 2; i++) {
        if (t[i] == h) {
            j = i;
            break;
        }
    }

    for (i = 0; i <= n + 2; i++) {
        for (j = 0; j <= (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    p = 0;
    while (t[j] != tot - 1) {
        atr[p] = t[j];
        j++;
        p++;
    }
    atr[p] = t[j];
    p = p + 1;
    i = 0;
    while (p != (n + 3) && t[i] != t[h]) {
        atr[p] = t[i];
        i++;
        p++;
    }

    for (j = 0; j < n + 2; j++) {
        if (atr[j] > atr[j + 1]) {
            d[j] = atr[j] - atr[j + 1];
        } else {
            d[j] = atr[j + 1] - atr[j];
        }
        sum += d[j];
    }

    printf("Total header movements: %d\n", sum);
    printf("Average is: %f\n", (float)sum / n);

    return 0;
}
