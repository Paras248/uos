#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(strlen(argv[1]) != 10) {
        printf("Invalid string format please enter string in mmddhhmmyy format!!!");
    }

    char command[50];
    snprintf(command, sizeof(command), "date %s", argv[1]);
    system(command);

    return 0;
}
