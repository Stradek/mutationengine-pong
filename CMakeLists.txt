#
# Copyright (c) 2023 Piotr Stradowski. All rights reserved.
# Software distributed under the permissive MIT License.
#

cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
cmake_policy(VERSION 3.10)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_STANDARD 17)


# Set the default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Set the compile commands export for clang lang server 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Specify compiler flags for different build types
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")

# Enable all warnings
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

# Set the output directories
set(LIBRARIES_PATH ${CMAKE_SOURCE_DIR}/lib)
set(EXTERNAL_INCLUDES_PATH ${CMAKE_SOURCE_DIR}/external)

############################################
project(MutationEngine-Pong)

# MutationEngine-Pong
set(SOURCES 
    ${CMAKE_SOURCE_DIR}/source/game/main.c
    ${CMAKE_SOURCE_DIR}/source/engine/mutation_engine.c
    ${CMAKE_SOURCE_DIR}/source/engine/mutation_engine.h
    ${CMAKE_SOURCE_DIR}/source/engine/renderer.c
    ${CMAKE_SOURCE_DIR}/source/engine/renderer.h
    ${CMAKE_SOURCE_DIR}/source/engine/entity.c
    ${CMAKE_SOURCE_DIR}/source/engine/entity.h
)

add_executable(MutationEngine-Pong ${SOURCES})

target_include_directories(MutationEngine-Pong PRIVATE
    ${CMAKE_SOURCE_DIR}/source
)

# Include external libraries
target_include_directories(MutationEngine-Pong PRIVATE
    "${EXTERNAL_INCLUDES_PATH}"
)

############################################
# SDL2
############################################

# Link SDL2 libraries
target_link_libraries(MutationEngine-Pong
    "${LIBRARIES_PATH}/SDL2/SDL2.dll"
)

# Copy SDL2.dll to the output directory
add_custom_command(TARGET MutationEngine-Pong POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    "${LIBRARIES_PATH}/SDL2/SDL2.dll"
    $<TARGET_FILE_DIR:MutationEngine-Pong>
)

############################################
