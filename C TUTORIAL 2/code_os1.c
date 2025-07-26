#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
    // pid_t p = fork();
    
    int i;
    int k=1;
    for(i=0;i<4;i++){
        fork();
    }
    printf("* %d  ",k++);
    return 0;
}