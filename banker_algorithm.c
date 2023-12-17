// Banker's Algorithm in C 

#include<stdio.h>

// Function to input the allocated and maximum resources for each process
void inputResources(int resources[][10], int n, int m, const char* message) {
    printf("Enter %s resources for each process:\n", message);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &resources[i][j]);
        }
    }
}

// Function to input available resources
void inputAvailableResources(int available[], int m) {
    printf("Enter available resources:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }
}

// Function to calculate the need matrix
void calculateNeed(int need[][10], int max[][10], int alloc[][10], int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

// Function to check if a process can be executed
int canExecute(int avail[], int need[], int m) {
    for(int j = 0; j < m; j++) {
        if(avail[j] < need[j]) {
            return 0;  // Resources are insufficient
        }
    }
    return 1;  // Resources are sufficient
}

// Function to find the safe sequence using Banker's algorithm
void findSafeSequence(int alloc[][10], int max[][10], int avail[], int n, int m) {
    int need[10][10];
    calculateNeed(need, max, alloc, n, m);

    int ans[10], done[10] = {0};
    int finished = 1, idx = 0;

    printf("Remaining need:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    while(finished != 0) {
        finished = 0;
        for(int i = 0; i < n; i++) {
            if(done[i] == 0 && canExecute(avail, need[i], m)) {
                finished++;
                done[i] = 1;
                ans[idx++] = i;

                // Update available resources
                for(int k = 0; k < m; k++) {
                    avail[k] += alloc[i][k];
                }
            }
        }
    }

    int ok = 1;
    for(int i = 0; i < n; i++) {
        if(done[i] == 0) {
            ok = 0;
        }
    }

    if(ok) {
        printf("Safe sequence: P%d", ans[0]);
        for(int i = 1; i < n; i++) {
            printf(" -> P%d", ans[i]);
        }
    } else {
        printf("System is in an unsafe state!\n");
    }
}

int main() {
    int n, m;
    printf("Enter the number of processes and resources:\n");
    scanf("%d %d", &n, &m);

    int alloc[10][10], max[10][10], avail[10];

    inputResources(alloc, n, m, "allocated");
    inputResources(max, n, m, "maximum");
    inputAvailableResources(avail, m);

    findSafeSequence(alloc, max, avail, n, m);

    return 0;
}
