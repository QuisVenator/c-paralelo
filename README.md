# Bienvenido
En este repositorio estaremos subiendo los ejemplos mostrados en clase y también soluciones a tareas.

## Compilar un ejemplo
Para compilar por favor usar los siguientes comandos:
- Crear una carpeta vacía build
```sh
rm -rf build && mkdir build && cd build
```
- Preparar archivos para compilación
```sh
cmake ..
```
- Compilar el código deseado. Por ejemplo para compilar `hola_mundo`:
```sh
make hola_mundo
```

## Ejecutar un programa
Cada ejemplo o tarea tiene sus propias instrucciones en su directorio. Pero en general se puede ejcutar con:
```sh
./<NOMBRE_EJEMPLO>
```
Los resultados esperados también se describen en los `README.md` de los subdirectorios individuales.