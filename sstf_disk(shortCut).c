// Shortest Seek time First Disk Schedule Algorithm in C

#include<stdio.h>
#include<stdlib.h> 

void sstf(int head, int req[], int n){
    
    int selReq, mini, currPos = head, totalMovement = 0;
    int distance[50]; // max of req[n] or size of DISK
    // Now print the sequence
    printf("Sequence: %d",head);    
    for(int k = 0 ; k<n ; ++k){
        // store distance of each request from current position
        for(int i=0 ; i<n ; ++i){
            distance[i] = abs(currPos - req[i]);
        }

        // Now find the minimum distance
        mini = 1e9;
        selReq = -1;
        for(int i=0 ; i<n ; ++i){
            if(distance[i] < mini){
                mini = distance[i];
                selReq = i;
            }
        }

        printf(" -> %d",req[selReq]);
        currPos = req[selReq];
        req[selReq] =  1e9;       // mark the request as completed

        totalMovement += mini;    // Now add the distance to total movement

    }

    // total head movement
    printf("\nTotal head movement: %d\n",totalMovement);

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
    sstf(head,req,n);
}