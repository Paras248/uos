#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void handleSigFpe(int sig) {
    printf("\nChild process encountered SIGFPE i.e floating point error");
    kill(getpid(), SIGKILL);
}

void hanldeSigChld(int sig){
    printf("\nChild process terminated\n");
    exit(1);
}

void main(){
    int pid = fork();
    if(pid > 0){
        printf("Parent process is executing...\n");
        signal(SIGCHLD, hanldeSigChld);
        while(1) sleep(1);
        printf("\nParent process executed successfully\n");
    } else {
        printf("Child process is executing...\n");
        signal(SIGFPE, handleSigFpe);
        int a = 1, b = 0;
        int c = a / b; 
        printf("Child process executed successfully\n");
    }
}