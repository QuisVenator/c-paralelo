#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *decir_hola_mundo(void *tnum) {
    for (int i = 0; i < 10; i++) {
        printf("Thread %d: Hola mundo!\n", *(int *)tnum);
    }
    return 0;
}

int main() {
    int ids[5];
    pthread_t thread_id[5];
    for (int i = 1; i <= 5; i++) {
        ids[i - 1] = i;
        pthread_create(&thread_id[i - 1], NULL, decir_hola_mundo, (void *)&ids[i - 1]);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(thread_id[i], NULL);
    }
    printf("BYE!\n");
    return 0;
}
