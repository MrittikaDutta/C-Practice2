#include <stdio.h>
#include <sys/types.h>
// #include <string.h>
#include <unistd.h>
// #include <math.h>
// #include <stdlib.h>
int main() {
    pid_t p = fork();
    if(fork()||fork()){
        fork();
    }
    printf("*   ");
    return 0;
}