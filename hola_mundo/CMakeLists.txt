target_sources(hola_mundo PRIVATE
    hola-mundo.c
)

target_compile_options(hola_mundo PUBLIC "-pthread")