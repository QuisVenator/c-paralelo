target_sources(hola_mundo PRIVATE
    hola-mundo.c
)

target_link_libraries(hola_mundo PRIVATE
    pthread
)