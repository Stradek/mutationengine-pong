@echo off
setlocal

rem Clean CMake files
rmdir /s /q CMakeFiles
rmdir /s /q build
del CMakeCache.txt
del cmake_install.cmake

rem Clean Visual Studio files
del *.vcxproj
del *.vcxproj.*
del *.sln

endlocal
