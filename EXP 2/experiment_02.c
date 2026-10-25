#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    int src = open("source.txt", O_RDONLY);
    if (src < 0) { perror("source.txt"); return 1; }

    int dst = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst < 0) { perror("destination.txt"); close(src); return 1; }

    char buffer[1024];
    ssize_t n;
    while ((n = read(src, buffer, sizeof(buffer))) > 0) {
        if (write(dst, buffer, (size_t)n) != n) {
            perror("write"); close(src); close(dst); return 1;
        }
    }
    close(src);
    close(dst);
    if (n < 0) { perror("read"); return 1; }
    printf("File copied successfully.\n");
    return 0;
}
