// Least Recently Used (LRU) Page Replacement Algorithm

#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10

int findLRU(int frame[], int n, int pages[], int m) {
    int res = -1, farthest = 0;

    for (int i = 0; i < n; i++) {
        int j;

        for (j = 0; j < m; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }

        if (j == m)
            return -1;
    }

    return (res == -1) ? 0 : res;
}

void lru(int pages[], int n, int frames) {
    int frame[MAX_FRAMES];
    int pageFaults = 0;

    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");

    for (int i = 0; i < n; i++) {
        bool pageFound = false;
        int page = pages[i];

        for (int j = 0; j < frames; j++) {
            if (frame[j] == page) {
                pageFound = true;
                break;
            }
        }

        if (!pageFound) {
            int lruIndex = findLRU(frame, frames, pages, i);
            frame[lruIndex] = page;
            pageFaults++;

            printf("%d\t", page);

            for (int j = 0; j < frames; j++) {
                printf("%d ", frame[j]);
            }

            printf("\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int n, frames;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter the page sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    lru(pages, n, frames);

    return 0;
}
