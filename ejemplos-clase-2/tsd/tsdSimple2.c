#include <malloc.h> 
#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static pthread_key_t thread_log_key;

void imprimirNumero(){
    printf("%d ", *(int*) pthread_getspecific (thread_log_key));
}

void* thread_function (void* args) {
    int numero = *(int*) args;
    pthread_setspecific (thread_log_key, &numero);
    usleep((float)1/(float)(rand()%20));
    //printf("%d",numero);
    imprimirNumero();
} 

int main () { 
    int i; 
    pthread_t threads[5]; 

    pthread_key_create (&thread_log_key, NULL); 
    
    for (i = 0; i < 5; ++i){
        int* aux = malloc(sizeof(int));
        *aux = i;
        pthread_create (&(threads[i]), NULL, thread_function, aux); 
    }
        
    for (i = 0; i < 5; ++i) 
        pthread_join (threads[i], NULL); 

    printf("\n");

    return 0; 
}
