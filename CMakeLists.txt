cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/..)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(snake_2d src/main.cpp src/GameHandler.cpp src/Snake.cpp src/Map.cpp src/SnakeBody.cpp 
src/TextBox.cpp src/ScoreCounter.cpp src/Tower.cpp)
target_link_libraries(snake_2d PRIVATE sfml-graphics)
target_compile_features(snake_2d PRIVATE cxx_std_17)
target_include_directories(snake_2d PRIVATE include)

if(WIN32)
    add_custom_command(
        TARGET snake_2d
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()
