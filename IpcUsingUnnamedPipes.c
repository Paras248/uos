#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if(argc < 4) {
        printf("\nInsufficient number of arguments to execute...\n");
        return 0; 
    }
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execlp(argv[3], argv[3], argv[4], NULL);
        close(fd[0]);
    } else {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO); 
        execlp(argv[1], argv[1], argv[2], NULL);
        close(fd[1]);
    }

    return 0;
}
