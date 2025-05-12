cmake_minimum_required(VERSION 3.15)

project(2DEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

cmake_minimum_required(VERSION 3.15)
project(2DEngine LANGUAGES CXX)

# Add subdirectories
add_subdirectory(2DEngine)
add_subdirectory(2DEngineDemo)
