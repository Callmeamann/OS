// First come First serve algorithm in C

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
    float ttl_tat = 0, ttl_wt = 0;
    while(done != n){
        int p=-1, min = 1e9;
        int tempat = 1e9;
        for(int i=0 ; i<n ; ++i){
            if(at[i] <= atime && temp[i]){
                if(at[i] < tempat){
                    p = i;
                    tempat = at[i];
                }
            }
        }
        if(p == -1) atime++;
        else{
            atime += bt[p];
            ct[p] = atime;
            temp[p] = 0;
            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];
            ttl_tat += tat[p];
            ttl_wt += wt[p];
            done++;
        }
    }

    printf("Process\tBT\tAT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,bt[i],at[i],ct[i],tat[i],wt[i]);
    }

    printf("\n\nAverage Turn Around Time: %f\nAverage Waiting Time: %f\n",ttl_tat/n,ttl_wt/n);

}