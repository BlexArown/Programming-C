# Задание: Создать библиотеку из background.c и слинковать ее с библиотекой pipes

# Создаем библиотеку background из background.c
add_library(background background.c)

# Линкуем библиотеку background с библиотекой pipes
target_link_libraries(background pipes)

