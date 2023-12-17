// Shortest Job First Scheduling Algorithm in C

#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int bt[n], at[n], ct[n], tat[n], wt[n], temp[n];
    for(int i=0;i<n;i++){
        printf("Enter the burst time and arrival time of process %d: ",i+1);
        scanf("%d %d",&bt[i],&at[i]);
        temp[i]=bt[i];
    }

    int done = 0, atime = 0;
    while(done != n){
        int p = -1, min = 1e9, tempat = 1e9;
        for(int i=0 ; i<n ; ++i){
            if(at[i] <= atime && temp[i]){
                if(temp[i] < min){
                    p = i;
                    min = temp[i];
                }
                else if(temp[i] == min && at[i] <tempat){
                    p = i;
                    tempat = at[i];
                }
            }
        }
        if(p == -1)     atime++;
        else{
            atime += bt[p];
            ct[p] = atime;
            temp[p] = 0;
            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];
            done++;
        }
    }

    float ttl_tat = 0, ttl_wt = 0;
    printf("Process\tBT\tAT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,bt[i],at[i],ct[i],tat[i],wt[i]);
        ttl_tat += tat[i];
        ttl_wt += wt[i];
    }

    printf("\n\nAverage Turn Around Time: %f\nAverage Waiting Time: %f\n",ttl_tat/n,ttl_wt/n);

}

/*
Enter the number of processes: 4
Enter the burst time and arrival time of process 1: 2 0
Enter the burst time and arrival time of process 2: 1 1
Enter the burst time and arrival time of process 3: 5 0
Enter the burst time and arrival time of process 4: 3 3
Process BT      AT      CT      TAT     WT
1       2       0       2       2       0
2       1       1       3       2       1
3       5       0       11      11      6
4       3       3       6       3       0


Average Turn Around Time: 4.500000
Average Waiting Time: 1.750000
*/