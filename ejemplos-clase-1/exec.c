#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    char *const argumentos[3] = {"ls", "-l", NULL};
    char *const argumentos_aux[3] = {"aux.sh", NULL};
    char *const entorno[2] = {"VARIABLE_ENTORNO=hello", NULL};
    // Puede descomentar una de las siguientes lineas para probar su funcionamiento:
    // execvp("ls", argumentos); // Ejecuta el comando ls con los argumentos "-l", si ls existe en el PATH
    // execv("/bin/ls", argumentos); // Ejecuta el comando ls con los argumentos "-l", si ls existe como /bin/ls
    // execlp("ls", "ls", "-l", NULL); // Ejecuta el comando ls con los argumentos "-l", si ls existe en el PATH y no necesita el array
    // execl("/bin/ls", "ls", "-l", NULL); // Ejecuta el comando ls con los argumentos "-l", si ls existe como /bin/ls y no necesita el array
    // execle("./aux.sh", "aux.sh", NULL, entorno); // Ejecuta el script aux.sh, pero antes de ejecutarlo, cambia o crea la variable de entorno VARIABLE_ENTORNO a "hello"
    execve("./aux.sh", argumentos_aux, entorno); // Ejecuta el script aux.sh, pero antes de ejecutarlo, cambia o crea la variable de entorno VARIABLE_ENTORNO a "hello"
    printf("Este mensaje no deberia aparecer\n");
    return 0;
}