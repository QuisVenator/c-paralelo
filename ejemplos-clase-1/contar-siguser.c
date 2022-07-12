#define _GNU_SOURCE // Para que intellisense acepte que esto no es estándar y lo trate como específico de linux

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

sig_atomic_t sigusr1_count = 0;
void handler(int signal_number) {
    ++sigusr1_count;
}
int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &handler;
    sigaction(SIGINT, &sa, NULL);
    time_t tiempo_ini = time(0);
    while (time(0) - tiempo_ini < 5) {
        ;
    }
    printf("SIGINT se llamó %d veces\n", sigusr1_count);
    return 0;
}
