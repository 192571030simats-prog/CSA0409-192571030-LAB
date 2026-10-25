#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void) {
    int id = shmget(IPC_PRIVATE, 256, IPC_CREAT | 0600);
    if (id < 0) { perror("shmget"); return 1; }
    char *data = (char *)shmat(id, NULL, 0);
    if (data == (char *)-1) { perror("shmat"); shmctl(id, IPC_RMID, NULL); return 1; }
    strcpy(data, "Hello from shared memory!");
    printf("Data in shared memory: %s\n", data);
    shmdt(data);
    shmctl(id, IPC_RMID, NULL);
    return 0;
}
