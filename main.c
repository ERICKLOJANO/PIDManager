#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pidmanager.c"

int main(){
    allocateMap();
    int x = allocatePID();
    int y = allocatePID();
    int z = allocatePID();
    fprintf(stdout, "allocated pid: %d \n", x);
    fprintf(stdout, "allocated pid: %d \n", y);
    releasePID(x);
    fprintf(stdout, "allocated pid: %d \n", z);
}