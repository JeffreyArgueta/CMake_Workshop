cmake_minimum_required(VERSION 3.10)

project(App)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(SRC_LST ${SRC_DIR}/main.cpp)

add_executable(${PROJECT_NAME} ${SRC_LST})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)