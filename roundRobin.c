// Round Robin Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];
    int timeQuanta = 2; // Set the time quantum

    // Input processes
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter the Arival time and Burst time of process %d: ", i + 1);
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
    }
    // Read time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &timeQuanta);
    
    // Round Robin Algorithm
    int currTime = 0;
    int proDone = 0;
    int requiredTime[n];

    for (int i = 0; i < n; i++) {
        requiredTime[i] = bt[i];
    }

    while (proDone != n) {
        int flag = 1;

        for (int i = 0; i < n; i++) {
            if (at[i] <= currTime && requiredTime[i] != 0) {
                flag = 0;
                int req = min(timeQuanta, requiredTime[i]);
                requiredTime[i] -= req;

                currTime += req;

                if (requiredTime[i] == 0) {
                    proDone++;
                    ct[i] = currTime;
                }
            }
        }

        if (flag) {
            currTime++;
        }
    }

    // Calculate Turnaround Time and Waiting Time
    float avgTat = 0.0, avgWt = 0.0;

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avgTat += tat[i];
        avgWt += wt[i];
    }

    avgTat /= n;
    avgWt /= n;

    // Display Results
    printf("\nPid\tA.T\tB.T\tC.T\tTAT\tWT");
    for (int i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAvgTAT: %f\n", avgTat);
    printf("AvgWT: %f", avgWt);

    return 0;
}
