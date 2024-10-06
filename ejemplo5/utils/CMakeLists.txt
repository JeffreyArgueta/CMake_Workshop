add_library(UtilsLib Helper.cpp Helper.h)

# Incluir directorios
target_include_directories(UtilsLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

