# Versión mínima de CMake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto y versión
project(EjemploCPack VERSION 1.0)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir directorios de encabezados (inclusión recursiva)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/class)
include_directories(${PROJECT_SOURCE_DIR}/include/clientes)
include_directories(${PROJECT_SOURCE_DIR}/include/pagos)
include_directories(${PROJECT_SOURCE_DIR}/include/prestamos)

# Buscar wxWidgets en el sistema
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Incluir los flags de wxWidgets
include(${wxWidgets_USE_FILE})

# Agregar todos los archivos fuente de los subdirectorios
file(GLOB_RECURSE SRC_FILES 
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# Crear el ejecutable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Enlazar wxWidgets con el ejecutable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

# Instalar el ejecutable en /usr/bin
install(TARGETS ${PROJECT_NAME} DESTINATION /usr/bin)

# Configuraciones de CPack
set(CPACK_PACKAGE_NAME "EjemploCPack")  # Nombre del paquete
set(CPACK_PACKAGE_VERSION "1.0.0")  # Versión del paquete
set(CPACK_PACKAGE_DESCRIPTION "Un ejemplo de uso de CPack")  # Descripción del paquete
set(CPACK_PACKAGE_CONTACT "tesst@example.com")  # Correo electrónico de contacto
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Christopher Álvarez")  # Nombre del mantenedor
set(CPACK_GENERATOR "DEB")  # Generar paquete .deb

include(CPack)
