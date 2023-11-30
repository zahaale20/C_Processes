#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("Error: Incorrect Argument Usage. Proper usage: ./fe_test <value>");
        return 1;
    }

    // fork the first child to run the 'odds' program
    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid1 == 0) { // check if child
        // child process for 'odds'
        execlp("./odd", "odd", argv[1], NULL);
        perror("execlp odds failed");
        exit(1);
    } else {
        // fork the second child to run the 'evens' program
        pid_t pid2 = fork();
        if (pid2 < 0) {
            perror("fork failed");
            return 1;
        }

        if (pid2 == 0) {
            // 2nd child process for 'evens'
            execlp("./even", "even", argv[1], NULL);
            perror("execlp evens failed");
            exit(1);
        }
        // parent process waits for both child processes
        int status;
        waitpid(pid1, &status, 0);
        waitpid(pid2, &status, 0);
    }

    return 0;
}