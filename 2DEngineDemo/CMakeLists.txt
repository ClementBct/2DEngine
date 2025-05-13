file(GLOB_RECURSE DEMO_SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_executable(2DEngineDemo ${DEMO_SOURCES})
target_link_libraries(2DEngineDemo PRIVATE 2DEngine)
target_include_directories(2DEngineDemo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)