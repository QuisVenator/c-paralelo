#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

int main(void)
{
    void *mFile = mmap(NULL, 4, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);

    pid_t childPid = fork();

    if (childPid == 0)
    {
        sprintf(mFile, "%s", "hijo");
        msync(mFile, 4, MS_SYNC);
        usleep(0.1);
        printf("HIJOOOO\n");
    }
    else
    {
        usleep(0.1);
        printf("Padre lee: %s\n", (char *)mFile);
        sprintf(mFile, "%s", "papa");
        msync(mFile, 4, MS_SYNC);
        printf("PADREEE\n");
        // wait(&childPid);
    }

    munmap(mFile, 4);

    return 0;
}