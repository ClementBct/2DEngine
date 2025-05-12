@echo off
setlocal

:: Configuration
set VCPKG_ROOT=C:\Users\clebo\Documents\Dev\vcpkg
set TOOLCHAIN_FILE=%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake
set BUILD_DIR=build
set GENERATOR="MinGW Makefiles"
::set GENERATOR="Visual Studio 17 2022"

if not exist %BUILD_DIR% mkdir %BUILD_DIR%

cd %BUILD_DIR%

cmake -DCMAKE_TOOLCHAIN_FILE=%TOOLCHAIN_FILE% -DCMAKE_BUILD_TYPE=Release -G %GENERATOR% ..

cmake --build .

pause
endlocal
