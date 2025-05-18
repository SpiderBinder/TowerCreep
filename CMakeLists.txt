cmake_minimum_required(VERSION 3.5)
project(TowerCreep)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Fetch SFML libraries using git
include(FetchContent)
FetchContent_Declare(
    SFML 
    GIT_REPOSITORY https://github.com/SFML/SFML.git
)
FetchContent_MakeAvailable(SFML)

set(SOURCE_FILES 
    src/main.cpp )
add_executable(TowerCreep ${SOURCE_FILES})

target_link_libraries(TowerCreep PRIVATE sfml-graphics sfml-system)
target_compile_features(TowerCreep PRIVATE cxx_std_20)