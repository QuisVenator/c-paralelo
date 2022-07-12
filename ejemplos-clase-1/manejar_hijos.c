#define _GNU_SOURCE // Para que intellisense acepte que esto no es estándar y lo trate como específico de linux

#include <signal.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

sig_atomic_t child_exit_status;
_Atomic(bool) proceso_terminado = false;
void clean_up_child_process(int signal_number) {
    int status;
    wait(&status);
    child_exit_status = status;
    proceso_terminado = true;
}

int main() {
    struct sigaction sigchld_action;
    memset(&sigchld_action, 0, sizeof(sigchld_action));
    sigchld_action.sa_handler = &clean_up_child_process;
    sigaction(SIGCHLD, &sigchld_action, NULL);

    // Crear un proceso hijo
    pid_t child_pid = fork();
    if (child_pid == 0) {
        sleep(1);
        return 0;
    }

    while (true) {
        if (proceso_terminado) {
            printf("El proceso hijo terminó con un código de salida %d\n", child_exit_status);
            proceso_terminado = false;
            // Crear un proceso hijo
            pid_t child_pid = fork();
            if (child_pid == 0) {
                sleep(1);
                return 0;
            }
        }
    }
    return 0;
}