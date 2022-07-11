cmake_minimum_required(VERSION 3.10)

project(cparalelo)

add_executable(hola_mundo hola_mundo/hola-mundo.c)
add_custom_target(ejemplo_hola_mundo)
add_dependencies(ejemplo_hola_mundo hola_mundo)