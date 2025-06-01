cmake_minimum_required(VERSION 3.5)
project(TowerCreep)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Fetch SFML libraries using git
include(FetchContent)
FetchContent_Declare(
    SFML 
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
)
FetchContent_MakeAvailable(SFML)

set(SOURCE_FILES 
    src/main.cpp 
    src/Game.h 
    src/Game.cpp 
    src/Menu.h 
    src/Menu.cpp 
    
    src/Objects/GameObject.h 
    src/Objects/GameObject.cpp 
    src/Objects/Entity.h 
    src/Objects/Entity.cpp 
    src/Objects/Player.h 
    src/Objects/Player.cpp 
    
    src/Environment/Chunk.h 
    src/Environment/Chunk.cpp 
    src/Environment/Level.h 
    src/Environment/Level.cpp 
    src/Environment/Tower.h 
    src/Environment/Tower.cpp 
    src/Environment/Hub.h 
    src/Environment/Hub.cpp )
add_executable(TowerCreep ${SOURCE_FILES})

target_link_libraries(TowerCreep PRIVATE SFML::Graphics SFML::Audio)
target_compile_features(TowerCreep PRIVATE cxx_std_20)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/content/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/content/)