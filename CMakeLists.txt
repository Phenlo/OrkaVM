cmake_minimum_required(VERSION 3.10)
project(OrkaVM VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(${PROJECT_NAME}_AUTHOR "Andrzej Brzeziński")

configure_file(
    ${PROJECT_SOURCE_DIR}/config/OrkaVM/config.h.in
    ${PROJECT_BINARY_DIR}/config/OrkaVM/config.h
)

include_directories(${PROJECT_BINARY_DIR}/config)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
