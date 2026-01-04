# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(TodoApp VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -O2)
endif()

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/Task.cpp
    src/TaskManager.cpp
    src/FileHandler.cpp
    src/UIManager.cpp
    src/Utils.cpp
    src/main.cpp
)

# Create executable
add_executable(todo-app ${SOURCES})

# Platform-specific settings
if(WIN32)
    target_compile_definitions(todo-app PRIVATE _WIN32)
else()
    target_compile_definitions(todo-app PRIVATE UNIX)
endif()

# Installation rules
install(TARGETS todo-app DESTINATION bin)

# Create data directory during installation
install(DIRECTORY DESTINATION ${CMAKE_INSTALL_PREFIX}/share/todo-app/data)

# Print build information
message(STATUS "Building Todo App v${PROJECT_VERSION}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Install Prefix: ${CMAKE_INSTALL_PREFIX}")
