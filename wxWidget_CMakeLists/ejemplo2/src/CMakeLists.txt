# src/CMakeLists.txt
add_executable(MainApp MainApp.cpp)

# Incluir el directorio de encabezados de ui
target_include_directories(
	MainApp
	PRIVATE ${CMAKE_SOURCE_DIR}/ui
)

# Vincular las bibliotecas
target_link_libraries(
	MainApp
	PRIVATE UiLib UtilsLib ${wxWidgets_LIBRARIES}
)