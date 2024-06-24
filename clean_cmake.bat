@echo off
setlocal

rem Clean CMake files
rmdir /s /q CMakeFiles
del CMakeCache.txt
del cmake_install.cmake

endlocal
