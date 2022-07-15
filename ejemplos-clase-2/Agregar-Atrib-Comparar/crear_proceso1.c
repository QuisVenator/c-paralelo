#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int saldo = 600;

int main() {
  int pres = 25;
  int i = 0;

  int id = fork();
  saldo = saldo - pres;
  
  if (id == 0) {
    printf("Saldo disponible hijo: %d\n", saldo);
  }
  else {
    sleep(2);
    printf("Saldo disponible padre: %d\n", saldo);
    wait(NULL);
  };

    
  return 0;
}