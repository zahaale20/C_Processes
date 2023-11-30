#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    // error handling for arguments
    if (argc != 3) {
        perror( "Usage: ./to_file <process> <file>\n");
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // error handling for file descriptor
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // redirct stdout to the file descritor
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("Error redirecting standard output");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);

    execvp(argv[1], &argv[1]);  // Execute the specified program
    perror("execvp failed");    // This will be executed only if execvp fails
    exit(EXIT_FAILURE);
}