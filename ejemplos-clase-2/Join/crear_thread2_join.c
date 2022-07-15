#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int saldo = 600;

void* prestarDinero(void* param) {
  int cantPrestar = *((int*)param);
  printf("Prestar %d dolares\n", cantPrestar);
  saldo = saldo - cantPrestar;
  printf("Dolares prestados: %d dolares\n", cantPrestar);

  return NULL;
}

int main() {
  pthread_t thread_id1;
  pthread_t thread_id2;
  int pres1 = 25;
  int pres2 = 200;
  int i = 0;
  pthread_create(&thread_id1, NULL, &prestarDinero, &pres1);
  pthread_create(&thread_id2, NULL, &prestarDinero, &pres2);


  while (i <= 10) {
    printf("%d\n", saldo);
    i++;
  };

  pthread_join(thread_id1, NULL);
  pthread_join(thread_id2, NULL);

  return 0;
}