#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>
 
struct job {
  /* Link field for linked list.  */
  int numtrabajo;
  struct job* next;
 
  /* Other fields describing work to be done... */
};
 
//Creamos un mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//Implementamos un semaforo
sem_t semaforo;

/* A linked list of pending jobs.  */
struct job* job_queue;
 
void process_job (struct job* trabajo){
    printf("Procesando tarea %d\n", trabajo->numtrabajo);
}
 
/* Process queued jobs until the queue is empty.  */
 
void* thread_function (void* arg)
{
  while (job_queue != NULL) {

    
    //Esperamos a que el semaforo este en 1
    sem_wait(&semaforo);
    //pthread_mutex_lock(&mutex);
    /* Get the next available job.  */
    struct job* next_job = job_queue;
    /* Remove this job from the list.  */
    job_queue = job_queue->next;

    sem_post(&semaforo);
    
    sleep(1+ (rand() % 2));
    /* Carry out the work.  */
    process_job (next_job);
    /* Clean up.  */
    free (next_job);

    //pthread_mutex_unlock(&mutex);


  }
  return NULL;
}

//Parametros para el thread
struct thread_params {
  int num_threads;
};
 
int main(int argc, char **argv){
    
    srand(time(NULL));
    //Creamos 100 trabajos
    int i;
    for(i=0;i<20;i++){
        struct job* trabajo = malloc(sizeof(struct job));
        trabajo->numtrabajo = 20-i;
        trabajo->next = job_queue;
        job_queue = trabajo;
    }

    //Iniciamos el semaforo
    sem_init(&semaforo, 0, 1);

    //Creamos 4 hilos y pasamos el numero de hilo al thread_function
    pthread_t threads[4];
    for(i=0;i<4;i++){
        struct thread_params* params = malloc(sizeof(struct thread_params));
        params->num_threads = i;
        pthread_create(&threads[i], NULL, thread_function, params);
    }
    for(i=0;i<4;i++){
        pthread_join(threads[i], NULL);
    }

    return 0;
}