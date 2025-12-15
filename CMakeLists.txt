cmake_minimum_required(VERSION 4.0)

project(ByteStreamCpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} src/main.cpp src/Runner.cpp src/Random.cpp)

add_subdirectory(ByteStreamCppLib)

target_include_directories(${PROJECT_NAME} PUBLIC src/include)

target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}Lib)
