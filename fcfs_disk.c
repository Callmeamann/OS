// First Come First Serve Disk Schedule Algorithm in C

#include<stdio.h>
#include<stdlib.h>

void fcfs(int head, int req[], int n){
    int seek =0, curr , diff;
    for(int i=0 ; i<n ; ++i){
        curr = req[i];
        diff = abs(curr -head);
        seek += diff;
        head = curr;
    }

    printf("Total seek time: %d\n", seek);
    // seek sequence will be same as request sequence
    printf("Average seek time : %f\n", (float)seek/n);
}

int main(){

    int n,head;
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    int req[n];
    printf("Enter the requests: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter the initial head position:  ");
    scanf("%d",&head);
    fcfs(head,req,n);

}