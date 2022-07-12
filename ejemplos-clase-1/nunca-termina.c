#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    printf("El proceso principal tiene el ID %d\n", (int)getpid());

    // Este loop es infinito, debemos terminarlo con sigkill o sigint (Ctrl+C)
    while (1) {
        ;
    }

    return 0;
}