#include <malloc.h> 
#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int numero;

void imprimirNumero(){
    printf("%d ",numero);
}

void* thread_function (void* args) { 
    numero = *(int*) args;
    usleep((float)1/(float)(rand()%20));
    //printf("%d",numero);
    imprimirNumero();
} 

int main () { 
    int i; 
    pthread_t threads[5]; 
    
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
