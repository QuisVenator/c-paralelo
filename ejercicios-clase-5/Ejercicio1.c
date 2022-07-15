/*
1- Simular una cola de supermercados donde cada thread es un hilo, el supermercado tiene hasta 4 cajas, 
donde existe una cola de todos los clientes, cuando una caja se libera, este toma al siguiente cliente.
*/

//librerias
#include <stdio.h>



//Agregue variables globales


//Structura de las cola de supermercado
typedef struct cola_supermercado{
    int numero_cliente;
    int segundos;
    struct cola_supermercado *siguiente;
} cola;

//Implemente la funcion hilo

int main(){



    return 0;
}