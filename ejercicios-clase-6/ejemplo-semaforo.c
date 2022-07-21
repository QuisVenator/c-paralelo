#define _GNU_SOURCE

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t trabajos_en_espera;
trabajo *lista_trabajos;
pthread_mutex_t mutex_lista_trabajos;

void *thread_func(void *arg) {
    while (corriendo) {
        sem_wait(&trabajos_en_espera);
        // Ahora este thread se comprometió con realizar un trabajo y tiene asegurado que uno esta disponible.
        // Igual debemos usar el mutex, por si otro thread también agarró un trabajo, para que los dos no realizen el mismo.
        pthread_mutex_lock(&mutex_lista_trabajos);
        // Sacar trabajo de la lista de trabajos
        pthread_mutex_unlock(&mutex_lista_trabajos);
        // Realizar trabajo. No realizamos el trabajo mientras tenemos el mutex, porque queremos minimizar el tiempo que otros threads deben esperar
    }

    return NULL;
}

int main() {
    pthread_mutex_init(&mutex_lista_trabajos, NULL);
    sem_init(&trabajos_en_espera, 0, 0);
    pthread_mutex_lock(&mutex_lista_trabajos);
    // Agregar N trabajos a la lista de trabajos
    pthread_mutex_unlock(&mutex_lista_trabajos);
    for (int i = 0; i < N; i++) {
        sem_post(&trabajos_en_espera);
    }

    // Crear threads
    return 0;
}