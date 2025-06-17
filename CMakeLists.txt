cmake_minimum_required(VERSION 3.15)
project(demonophobia)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_PREFIX_PATH "./build/generators")

find_package(raylib REQUIRED)
find_package(spdlog REQUIRED)

file(GLOB_RECURSE SRC_FILES "src/*.h" "src/*.hpp" "src/*.cpp")

message("=== SRC FILES ===")

foreach(file ${SRC_FILES})
    message("${file}")
endforeach()

message("=== END ===")

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} spdlog::spdlog)