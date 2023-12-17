// Shortest Seek time First Disk Schedule Algorithm in C

#include<stdio.h>
#include<stdlib.h> 

void sstf(int head, int req[], int n){
    
    int selReq, minDis, currPos = head, totalMovement = 0;
    int seq[50];
    int itr = 0;
    int distance[50]; // max of req[n] or size of DISK
    int visited[50];
    for(int i=0 ; i<n ; ++i){
        visited[i] = 0;
    }
    // Now print the sequence
    printf("Sequence: ");    
    for(int currHead = 0 ; currHead<n ; ++currHead){
        // store distance of each request from current position
        for(int i=0 ; i<n ; ++i){
            distance[i] = abs(currPos - req[i]);
        }

        // Now find the minimum distance
        minDis = 1e9;
        selReq = -1;
        for(int i=0 ; i<n ; ++i){
            if(distance[i] < minDis && !visited[i]){
                minDis = distance[i];
                selReq = i;
            }
        }
        // Now store the index of selected request in seq
        seq[itr++] = selReq;

        // Now move the head to the selected request
        currPos = req[selReq];
        visited[selReq] =  1; // mark the request as completed

        // Now add the distance to total movement
        totalMovement += minDis;
    }


    printf("%d",req[seq[0]]);
    for(int i=1 ; i<n ; ++i){
        printf(" -> %d",req[seq[i]]);
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