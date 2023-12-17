// Shortest Remaining Time First (SRTF) scheduling algorithm

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];

    // Input processes
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter the Arival time and Burst time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
    }

    // SRTF Algorithm
    int currTime = 0;
    int proDone = 0;
    int requiredTime[n];

    for (int i = 0; i < n; i++) {
        requiredTime[i] = bt[i];
    }

    while (proDone != n) {
        int minTime = INT_MAX;
        int minIndex = -1;

        for (int i = 0; i < n; i++) {
            if (at[i] <= currTime && requiredTime[i] != 0) {
                if (requiredTime[i] < minTime) {
                    minTime = requiredTime[i];
                    minIndex = i;
                }
            }
        }

        if (minIndex != -1) {
            requiredTime[minIndex] -= 1;
            currTime++;

            if (requiredTime[minIndex] == 0) {
                proDone++;
                ct[minIndex] = currTime;
            }
        } else {
            currTime++;
        }
    }

    // Calculate Turnaround Time and Waiting Time
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Print the output
    printf("P#\tAT\tBT\tCT\tTAT\tWT\n\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Calculate average Turnaround Time and average Waiting Time
    float avgTAT = 0, avgWT = 0;
    for (int i = 0; i < n; i++) {
        avgTAT += tat[i];
        avgWT += wt[i];
    }
    avgTAT /= n;
    avgWT /= n;

    printf("Average Turnaround Time = %f\n", avgTAT);
    printf("Average Waiting Time = %f\n", avgWT);
    
}