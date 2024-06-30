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
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

# Specify compiler flags for different build types
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")

# Define DEBUG and RELEASE macros
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DRELEASE")

# Enable all warnings
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

# Set the output directories
set(LIBRARIES_PATH ${CMAKE_SOURCE_DIR}/lib)
set(EXTERNAL_INCLUDES_PATH ${CMAKE_SOURCE_DIR}/external)

############################################
project(MutationEngine-Pong)

# MutationEngine-Pong
set(SOURCES 
    ${CMAKE_SOURCE_DIR}/source/common/debug.c
    ${CMAKE_SOURCE_DIR}/source/game/main.c
    ${CMAKE_SOURCE_DIR}/source/engine/mutation_engine.c
    ${CMAKE_SOURCE_DIR}/source/engine/renderer.c
    ${CMAKE_SOURCE_DIR}/source/engine/entity.c
)

add_executable(MutationEngine-Pong ${SOURCES})

# Set the output name
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(EXECUTABLE_NAME "${PROJECT_NAME}-d")
else()
    set(EXECUTABLE_NAME "${PROJECT_NAME}")
endif()

set_target_properties(MutationEngine-Pong PROPERTIES
    OUTPUT_NAME "${EXECUTABLE_NAME}"
)

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
