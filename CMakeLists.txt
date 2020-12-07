cmake_minimum_required(VERSION 3.0)
project(TexasTrailProject)
file(GLOB_RECURSE sources *.cc world/*.cc inventory/*.cc render/*.cc party/*.cc render/*.cc)

add_executable(TexasTrail ${sources})
target_include_directories(TexasTrail PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/world ${CMAKE_CURRENT_SOURCE_DIR}/inventory ${CMAKE_CURRENT_SOURCE_DIR}/render ${CMAKE_CURRENT_SOURCE_DIR}/party $(CMAKE_CURRENT_SOURCE_DIR)/render)
target_compile_options(TexasTrail PRIVATE -g)