@echo off
setlocal

rem Set the project name
set PROJECT_NAME=MutationEngine-Pong
set BUILD_DIR=build
set BINARIES_DIR=bin
set PROJECT_EXECUTABLE_PATH=%BINARIES_DIR%\%PROJECT_NAME%.exe
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
cmake -G "MinGW Makefiles" -S . -B %BUILD_DIR%
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

endlocal
exit /b %errorlevel%
