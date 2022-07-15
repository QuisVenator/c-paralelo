#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int saldo = 600;

void* prestarDinero(void* param) {
  int cantPrestar = *((int*)param);
  printf("Prestar %d dolares\n", cantPrestar);
  // usleep(0.8);
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


  while (i <= 20) {
    printf("%d\n", saldo);
    // usleep(0.01);
    i++;
  };
  
  return 0;
}