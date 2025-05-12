@echo off
setlocal

:: Configuration
set BUILD_DIR=build
set GENERATOR="MinGW Makefiles"
::set GENERATOR="Visual Studio 17 2022"

if not exist %BUILD_DIR% mkdir %BUILD_DIR%

cd %BUILD_DIR%

cmake .. -G %GENERATOR%

cmake --build .

pause
endlocal
