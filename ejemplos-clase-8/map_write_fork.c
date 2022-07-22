#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

int main(void)
{
    char *valorInicial = "nada";
    int tamBytes = strlen(valorInicial) * sizeof(char);

    int fd = open("test_write_file.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    if (fd < 0)
    {
        printf("Error no se puede abrir el archivo\n");
        return -1;
    }

    write(fd, valorInicial, tamBytes);
    void *mFile = mmap(NULL, tamBytes, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    pid_t childPid = fork();

    if (childPid == 0) {
        sprintf(mFile, "%s", "hijo");
        msync(mFile, strlen(valorInicial), MS_SYNC);
        usleep(0.1);
        printf("HIJOOOO\n");
    }
    else {
        usleep(0.1);
        printf("Padre lee: %s\n", (char*)mFile);
        sprintf(mFile, "%s", "papa");
        msync(mFile, strlen(valorInicial), MS_SYNC);
        printf("PADREEE\n");
        // wait(&childPid);
    }
    
    munmap(mFile, tamBytes);

    return 0;
}