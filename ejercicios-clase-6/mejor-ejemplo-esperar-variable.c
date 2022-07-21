#include <pthread.h>

int thread_flag;
pthread_cond_t thread_flag_cv;
pthread_mutex_t thread_flag_mutex;
void initialize_flag() {
    pthread_mutex_init(&thread_flag_mutex, NULL);
    pthread_cond_init(&thread_flag_cv, NULL);
    pthread_mutex_lock(&thread_flag_mutex);
    thread_flag = 0;
    pthread_mutex_unlock(&thread_flag_mutex);
}

void *thread_function(void *thread_arg) {
    while (1) {
        // Debemos agarrar el lock manualmente
        pthread_mutex_lock(&thread_flag_mutex);
        while (thread_flag > 10)
            // El flag no esta seteado
            pthread_cond_wait(&thread_flag_cv, &thread_flag_mutex);
        // Si llegamos a este punto, el flag está seteado.
        pthread_mutex_unlock(&thread_flag_mutex);
        do_work();
    }
    return NULL;
}

/* Sets the value of the thread flag to FLAG_VALUE. */
void set_thread_flag(int flag_value) {
    pthread_mutex_lock(&thread_flag_mutex);

    thread_flag = flag_value;

    // Lanzar una señal
    pthread_cond_signal(&thread_flag_cv);

    pthread_mutex_unlock(&thread_flag_mutex);
}
