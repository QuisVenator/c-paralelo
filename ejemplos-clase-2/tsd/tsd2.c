#include <malloc.h> 
#include <pthread.h> 
#include <stdio.h> 

FILE* thread_log; 

void write_to_thread_log (const char* message){ 
    fprintf (thread_log, "%s\n", message); 
} 

/* Close the log file pointer THREAD_LOG. */ 
void close_thread_log (void* thread_log){ 
    fclose ((FILE*) thread_log); 
} 

void* thread_function (void* args) { 
    char thread_log_filename[20]; 
    FILE* thread_log; 
    /* Generate the filename for this thread's log file. */ 
    sprintf (thread_log_filename, "thread%d.log", (int) pthread_self ()); 
    /* Open the log file. */ 
    thread_log = fopen (thread_log_filename, "w"); 
    write_to_thread_log ("Thread starting."); 
    /* Do work here... */ 
    return NULL; 
} 

int main () { 
    int i; 
    pthread_t threads[5]; 
    
    for (i = 0; i < 5; ++i) 
        pthread_create (&(threads[i]), NULL, thread_function, NULL); 


    for (i = 0; i < 5; ++i) 
        pthread_join (threads[i], NULL); 
    return 0; 
}