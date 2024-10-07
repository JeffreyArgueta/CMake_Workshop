cmake_minimum_required(VERSION 3.10)
project(EjemploDos)

# Encontrar wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Incluir directorios de encabezados de wxWidgets
include(${wxWidgets_USE_FILE})

# Incluir subdirectorios
add_subdirectory(src)
add_subdirectory(ui)
add_subdirectory(utils)
