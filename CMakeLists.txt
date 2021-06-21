cmake_minimum_required(VERSION 3.0)
project(TexasTrailProject)
file(GLOB_RECURSE sources *.cc world/*.cc inventory/*.cc render/*.cc party/*.cc render/*.cc ui/*.cc event/*.cc hazard/*.cc shape/*.cc)

add_executable(TexasTrail ${sources})
target_include_directories(TexasTrail PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/world ${CMAKE_CURRENT_SOURCE_DIR}/inventory ${CMAKE_CURRENT_SOURCE_DIR}/render ${CMAKE_CURRENT_SOURCE_DIR}/party ${CMAKE_CURRENT_SOURCE_DIR}/render ${CMAKE_CURRENT_SOURCE_DIR}/ui ${CMAKE_CURRENT_SOURCE_DIR}/event ${CMAKE_CURRENT_SOURCE_DIR}/hazard ${CMAKE_CURRENT_SOURCE_DIR}/shape)
target_compile_options(TexasTrail PRIVATE -g)