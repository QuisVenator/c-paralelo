target_sources(hola_mundo PRIVATE
    hola-mundo.c
)

find_package(Threads REQUIRED)
target_link_libraries(my_app PRIVATE
    Threads::Threads
)