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
  int retorno1;
  int retorno2;
  int pres1 = 25;
  int pres2 = 200;
  int i = 0;
  pthread_create(&thread_id1, NULL, &prestarDinero, &pres1);
  pthread_create(&thread_id2, NULL, &prestarDinero, &pres2);

  while (i <= 10) {
    printf("%d\n", saldo);
    i++;
  };

  pthread_join(thread_id1, (void*)&retorno1);
  pthread_join(thread_id2, (void*)&retorno2);

  printf("Usaron respectivamente: %d y %d respectivamente\n", retorno1, retorno2);
  // pthread_exit(0);
  return 0;
}