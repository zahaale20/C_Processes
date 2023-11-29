#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>

void limit_fork(rlim_t max_procs)
{
    struct rlimit rl;
    if (getrlimit(RLIMIT_NPROC, &rl))
    {
        perror("getrlimit");
        exit(-1);
    }
    else
    {
        //printf("Current max processes limit: %lu\n", (unsigned long)rl.rlim_cur);
        //printf("Max processes limit (hard limit): %lu\n", (unsigned long)rl.rlim_max);
    }
    rl.rlim_cur = max_procs;
    if (setrlimit(RLIMIT_NPROC, &rl))
    {
        perror("setrlimit");
        exit(-1);
    }
}

int main (int argv, char *argc[]){
    limit_fork(128);
    // Error handling for number of arguments
    if(argv != 2){
        perror("Error: incorrect argument usage. Ex: ./f_test <value>");
        return 1;
    }

    int N = atoi(argc[1]); // convert int to string
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) { // if pid is 0, it is a child process
        for (int i = 1; i <= N; i++) { // for each value to and including N
            if (i % 2 != 0) { // print if odd
                printf("%d\n", i);
            }
        }
        exit(1);
    } else { // else it is a parent process
        for (int i = 1; i <= N; i++) { // for each value to and including N
            if (i % 2 == 0) { // print if even
                printf("\t%d\n", i);
            }
        }
        wait(NULL); // wait for child to finish at the end
    }

    return 0;
}