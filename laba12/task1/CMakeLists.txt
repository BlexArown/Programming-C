# Задание: задать имя проекта и версию cmake, добавить subdirectory для background и pipes, в которых 
# тоже есть свои CMakeLists.txt (внутри них тоже нужно добавить одну-две строки для сборки, задание описано в них же)
# Решить проблему с заголовочными файлами, включив директории в корневом CMakeLists.txt (include_directories)
# Слинковать исполняемый файл из src/main.c с библиотекой background
# Все это дело собрать, используя cmake и make
# Для установки cmake нужно установить его: sudo apt install build-essential cmake -y

cmake_minimum_required(VERSION 3.10)
project(project)

# Добавляем директории с заголовочными файлами
include_directories(${CMAKE_SOURCE_DIR}/background ${CMAKE_SOURCE_DIR}/pipes)

# Добавляем поддиректории с их CMakeLists.txt
add_subdirectory(background)
add_subdirectory(pipes)

# Создаем исполняемый файл main из main.c
add_executable(main src/main.c)

# Линкуем исполняемый файл с библиотекой background
target_link_libraries(main background)

