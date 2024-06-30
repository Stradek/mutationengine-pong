@echo off
setlocal disabledelayedexpansion

rem Set the project name and build directory
set PROJECT_NAME=MutationEngine-Pong
set BUILD_DIR=build

rem set program configuration
set arg1=%1 
if "%1" == "Release" (
    echo "Release configuration selected."
    set BINARIES_DIR=bin\release
    set PROJECT_EXECUTABLE_SUFFIX=
) else if "%1" == "Debug" (
    echo "Debug configuration selected."
    set BINARIES_DIR=bin\debug
    set PROJECT_EXECUTABLE_SUFFIX=-d
) else (
    set "ERROR_MESSAGE=Invalid configuration. Use 'Release' or 'Debug'."
    call :handle_error
    goto :EOF
)

set PROJECT_EXECUTABLE_PATH=%BINARIES_DIR%\%PROJECT_NAME%%PROJECT_EXECUTABLE_SUFFIX%.exe

goto :main

rem Function to handle error and exit
:handle_error
echo Error: %ERROR_MESSAGE%
pause
exit /b 1

:main
rem Configure the project
if not exist %BUILD_DIR% ( 
    mkdir %BUILD_DIR%
)
cmake -G "MinGW Makefiles" -S . -B %BUILD_DIR% -DCMAKE_BUILD_TYPE=%1 -DCMAKE_INSTALL_PREFIX=%BINARIES_DIR%
if %errorlevel% neq 0 (
    set "ERROR_MESSAGE=Failed to configure the project."
    call :handle_error
    goto :EOF
)

rem Build the project
cmake --build %BUILD_DIR%
if %errorlevel% neq 0 (
    set "ERROR_MESSAGE=Failed to build the project."
    call :handle_error
    goto :EOF
)

rem Run the executable
if exist %PROJECT_EXECUTABLE_PATH% (
    %PROJECT_EXECUTABLE_PATH%
) else (
    set "ERROR_MESSAGE=Executable not found."
    call :handle_error
    goto :EOF
)
echo Program finished.
pause

endlocal
exit /b %errorlevel%
