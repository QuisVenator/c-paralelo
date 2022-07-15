#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int saldo = 600;

void* prestarDinero(void* param) {
  int cantPrestar = *((int*)param);
  printf("Prestar %d dolares\n", cantPrestar);
  saldo = saldo - cantPrestar;
  printf("Dolares prestados: %d dolares\n", cantPrestar);

  srand(time(NULL));
  int randomNum = (rand() % cantPrestar) + 1;
  return (void*) randomNum;
}

int main() {
  pthread_t thread_id1;
  pthread_t thread_id2;
  pthread_attr_t detachedThread;
  int retorno1;
  int retorno2;
  int pres1 = 25;
  int pres2 = 200;
  int i = 0;

  pthread_attr_init(&detachedThread);
  // Se selecciona el estado del hilo, puede ser detached or joinable
  pthread_attr_setdetachstate(&detachedThread, PTHREAD_CREATE_DETACHED);
  pthread_create(&thread_id1, &detachedThread, &prestarDinero, &pres1);
  pthread_create(&thread_id2, &detachedThread, &prestarDinero, &pres2);


  while (i <= 10) {
    printf("%d\n", saldo);
    i++;
  };

  pthread_exit(0);
  
  if (pthread_join(thread_id1, (void *)&retorno1) != 0) {
    perror("Join no funciona");
  };
  if (pthread_join(thread_id2, (void*) &retorno2) != 0) {
    perror("Join no funciona");
  };

  pthread_attr_destroy(&detachedThread);
  
  
  // return 0;
}