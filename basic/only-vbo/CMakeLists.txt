cmake_minimum_required(VERSION 3.26)

if (NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(main LANGUAGES CXX C)

add_executable(${PROJECT_NAME}
    main.cpp
    ${CMAKE_SOURCE_DIR}/../../libraries/glad/src/glad.c
    ${CMAKE_SOURCE_DIR}/../../libraries/glad/include/glad/glad.h
    ${CMAKE_SOURCE_DIR}/../../libraries/glad/include/KHR/khrplatform.h
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_SOURCE_DIR}/../../libraries/glad/include
    ${CMAKE_SOURCE_DIR}/../../libraries/glfw/include
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    ${CMAKE_SOURCE_DIR}/../../libraries/glfw/build/src/libglfw.so
)
