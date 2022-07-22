#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    char* valorInicial = "AAAAAAAAAAAAAAAAAAAA";
    int tamBytes = strlen(valorInicial) * sizeof(char);

    int fd = open("test_write_file.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    char* msg = "Archivo Modificado";

    if (fd < 0) {
        printf("Error no se puede abrir el archivo\n");
        return -1;
    }

    write(fd, valorInicial, tamBytes);
    void* mFile = mmap(NULL, tamBytes, PROT_READ | PROT_WRITE, MAP_PRIVATE,fd, 0);
    close(fd);

    // sprintf(mFile, "%s", msg);
    memcpy(mFile, msg, strlen(msg));
    munmap(mFile, tamBytes);

    return 0;
}