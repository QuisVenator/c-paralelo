#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* funcionBasica(void* param) {
  sleep(3);
  printf("Marco\n");

  return NULL;
}

int main() {
  pthread_t thread_id;
  int i = 0;
  
  pthread_create(&thread_id, NULL, &funcionBasica, NULL);

  while (i <= 5) {
    printf("Polo\n");
    i++;
    sleep(1);
  };
  
  return 0;
}