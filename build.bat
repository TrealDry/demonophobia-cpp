@echo off

if not exist build (
	conan install . --build=missing
)

if not exist build/CMakeFiles (
    cmake -B build -S . -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=conan_provider.cmake -DCMAKE_BUILD_TYPE=Release
)

cmake --build build --config Release