#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    printf("Before fork: PID = %d, PPID = %d\n", getpid(), getppid());
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("Child process: PID = %d, PPID = %d\n", getpid(), getppid());
    } else {
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }
    return 0;
}
