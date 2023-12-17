// First In First Out (FIFO) Page Replacement Algorithm

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Enter the number of frames: ");
    scanf("%d", &n);
    printf("Enter the number of pages: ");
    scanf("%d", &m);

    int pages[m];
    printf("Enter the page reference string: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &pages[i]);
    }

    int frames[n];
    for (int i = 0; i < n; i++) {
        frames[i] = -1;
    }

    int pageFaults = 0;
    int currFrame = 0;

    for (int i = 0; i < m; i++) {
        int flag = 0;

        for (int j = 0; j < n; j++) {
            if (frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            frames[currFrame] = pages[i];
            currFrame = (currFrame + 1) % n;
            pageFaults++;
        }
    }

    printf("Number of page faults: %d\n", pageFaults);
    return 0;
}