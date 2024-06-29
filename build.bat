@echo off
setlocal

rem Set the project name
set PROJECT_NAME=MutationEngine-Pong
set BUILD_DIR=build
set BINARIES_DIR=bin
set PROJECT_EXECUTABLE_PATH=%BINARIES_DIR%\%PROJECT_NAME%.exe

rem Configure the project
if not exist %BUILD_DIR% ( 
    mkdir %BUILD_DIR%
)
cmake -G "MinGW Makefiles" -S . -B %BUILD_DIR%
if %errorlevel% neq 0 (
    echo Failed to configure the project.
    call :close
)

rem Build the project
cmake --build %BUILD_DIR%
if %errorlevel% neq 0 (
    echo Failed to build the project.
    call :close
)

rem Run the executable
if exist %PROJECT_EXECUTABLE_PATH% (
    %PROJECT_EXECUTABLE_PATH%
) else (
    echo Executable not found.
    call :close
)

:close
pause
goto:eof

endlocal
