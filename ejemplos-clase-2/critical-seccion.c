// Importamos librerias
#include <stdio.h> // Libreia estandar de entrada y salida
#include <stdlib.h> // Libreria estandar
#include <pthread.h> // Libreria para manejo de hilos
#include <unistd.h> // Libreria UNIX Estandar

float account_balances[5];// "Base de datos de clientes y dinero en cuenta"

void process_transaction (int from_acct, int to_acct, float dollars){
  int old_cancel_state;

  //Inicio de la seccion critica
  pthread_setcancelstate (PTHREAD_CANCEL_DISABLE, &old_cancel_state);

  account_balances[to_acct] += dollars;
  account_balances[from_acct] -= dollars;

  pthread_setcancelstate (old_cancel_state, NULL);
  //Fin de la seccion critica
}

void* thread_funtion(void* arg){
  printf("Operacion: process_transaction(0,1,50.0)\n");
  process_transaction(0,1,50.0);
}

int main(int argc, char const *argv[]){
    account_balances[0] = 1000.0;
    account_balances[1] = 100.0;

    printf("Antes de la operacion account_balances[0] = %.2f, account_balances[1] = %.2f\n",account_balances[0],account_balances[1]);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, &thread_funtion, NULL);
    pthread_join(thread_id, NULL);

    printf("Despues de la operacion account_balances[0] = %.2f, account_balances[1] = %.2f\n",account_balances[0],account_balances[1]);
    return 0;
}
