#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
int main(){
    pid_t pid;
    pid = fork();
    if (pid == -1){
        printf("Failed to create child process.\n");
        return 1;
    }
    if (pid == 0){
        printf("Child process started.\n");
        sleep(10);
        printf("Child process completed.\n");
    }
    else{
        printf("Parent is monitoring the child process.\n");
        sleep(3);
        printf("Child process is unresponsive.\n");
        kill(pid, SIGTERM);
        wait(NULL);
        printf("Zombie process prevented.\n");
    }
    return 0;
}
