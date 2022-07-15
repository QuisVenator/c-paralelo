/*
Sustino Among está intentando pasar matemática, solo que al ver la hoja de examen se da cuenta de que 
no va a tener tiempo de realizar la suma de matrices en la calculadora. Por suerte, Sustino había llevado
su computadora y se recordó que justo había estudiado respecto al uso de hilos y podría realizar un 
programa que terminé en el tiempo establecido.
*/

// Material sobre uso de punteros
// https://www.oreilly.com/library/view/understanding-and-using/9781449344535/ch04.html

// Agregue las librerias que necesite
#include <stdio.h>





// Agruege las variables globales que necesite en caso de usar






// Funcion para verificar el resultado
void comprobarResultado(int* mat, int fil, int col) {
  int resultado[][4] = {{766,721,565,782},{900,490,47,138},{1227,1020,699,781}};
  int equivocado = 0;
  int error = 1;

  if (mat == NULL) {
    printf("Matriz con valor nulo\n");
    return;
  }
  
  for (int i = 0; i < fil; i++) {
    for (int j = 0; j < col; j++) {
      error = 0;
      if (mat [i * col + j] != resultado[i][j]) {
        equivocado = 1;
        printf("No coincide el valor correcto %d con %d\n", resultado[i][j], mat [i * col + j]);
      }
    }
  }

  if (equivocado == 0 && error == 0) {
    printf("Resultado correcto!!!\n");
  }
  else if (error == 1){
    printf("Error, verificar numero de filas y columnas u otro problema (no entro en el 'for')\n");
  }
}


// Agregue las funciones y/o estructuras que necesite para la resolucion














int main(void) {
  // Valores para probar (no tocar los valores en caso de querer comprobar los resultados)
  int mat1[3][4] = {{222,66,444,5},{22,435,44,112},{452,932,634,125}};
  int mat2[3][4] = {{544,655,121,777},{878,55,3,26},{775,88,65,656}};







  
  

  // Si quiere comprobar su resultado
  // Debe insertar en el primer parametro un puntero al vector con la respuesta
  // Para el segundo y tercer parametro insertar el numero de fila y columna respectivamente
  comprobarResultado(NULL, 0, 0);

  
  return 0;
}