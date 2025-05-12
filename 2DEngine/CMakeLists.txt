file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_library(2DEngine STATIC ${ENGINE_SOURCES})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

target_include_directories(2DEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(2DEngine ${SDL2_LIBRARIES})