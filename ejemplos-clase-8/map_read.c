#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    char valorInicial[] = "AAAAAAAAAAAAAAAAAAAA";
    int tamBytes = strlen(valorInicial) * sizeof(char);

    int fd = open("test_write_file.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    if (fd < 0)
    {
        printf("Error no se puede abrir el archivo\n");
        return -1;
    }

    write(fd, valorInicial, tamBytes);
    
    void *mFile = mmap(NULL, 70, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    printf("%s\n", (char*)mFile);
    munmap(mFile, tamBytes);

    return 0;
}