#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
    pid_t child_pid;
    printf("El proceso principal tiene el ID %d\n", (int)getpid());
    child_pid = fork();
    if (child_pid != 0) {
        printf("Este es el proceso padre, sigue con ID %d\n", (int)getpid());
        printf("El proceso hijo tiene ID %d\n", (int)child_pid);
    } else
        printf("Este mensaje viene del proceso hijo con el ID %d\n", (int)getpid());
    return 0;
}