#include "pidmanager.h"
#include <stdio.h>

int allocateMap(){
    
    if(pids_memory == NULL ){
        printf("memory allocation failed");
        return -1;
    }

    for(int i = 0; i < max_pid; i++){
        pids_memory[i] = 0;
    }
    printf("memory allocation success \n");
    return 1;
}

int allocatePID(){

    if(pids_memory == NULL){
        printf("pid manager not working");
        return -1;
    }

    int pid = -1;

    for(int i = 0; i < max_pid; i++){
        if(pids_memory[i] == 0) {
            pids_memory[i] = 1;
            pid = min_pid + i;
            return pid;
        }
    }
    
    if(pid == -1){
        printf("cant allocate pid");
        return -1;
    }
    else{
        printf("pid has been allocated: %d", pid);
        return pid;
    }
}

void releasePID(int pid){

    if(pids_memory == NULL){
        printf("pid manager not working");
    }

    if(pid < min_pid || pid > max_pid){
        printf("pid is not in range");
    }

    int newPID = pid - min_pid;
    if(pids_memory[newPID] == 0){
        printf("released... pid: = %d", newPID );
    }
    printf("released pid: %d \n", newPID);
    pids_memory[newPID] = 0;

}