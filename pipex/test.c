#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process

        // Perform some tasks in the child process
        printf("Child process executing...\n");
        sleep(2); // Simulating some work

        exit(EXIT_SUCCESS);
    } else {
        // Parent process

        printf("Parent process waiting for the child to terminate...\n");

        // Wait for the child process to terminate
        int status;
        pid_t child_pid = waitpid(pid, &status, 0);

        if (child_pid == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) {
            printf("Child process terminated with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child process terminated by signal %d\n", WTERMSIG(status));
        }
    }

    return 0;
}

