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

add_executable(${PROJECT_NAME} ${SRC_FILES}
        src/core/debug.cpp
        src/core/debug.hpp)
target_link_libraries(${PROJECT_NAME} raylib)
target_link_libraries(${PROJECT_NAME} spdlog::spdlog)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
    COMMENT "Copying assets directory for MyTarget"
)
