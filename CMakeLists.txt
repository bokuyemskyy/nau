cmake_minimum_required(VERSION 3.31)

project(BlackHole)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY    https://github.com/glfw/glfw.git
    GIT_TAG            3.4
    GIT_SHALLOW        TRUE
)
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG master
    GIT_SHALLOW        TRUE
)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
    GIT_SHALLOW        TRUE
)
FetchContent_Declare(
    glad
    GIT_REPOSITORY    https://github.com/Dav1dde/glad.git
    GIT_TAG            v2.0.8
    GIT_SHALLOW        TRUE
    SOURCE_SUBDIR    cmake
)
FetchContent_Declare(
    miniaudio
    GIT_REPOSITORY https://github.com/mackron/miniaudio.git
    GIT_TAG master
    GIT_SHALLOW        TRUE
)
FetchContent_MakeAvailable(glad glfw glm googletest miniaudio)

find_package(OpenGL REQUIRED)

glad_add_library(glad STATIC REPRODUCIBLE LOADER API gl:core=3.3)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw glm::glm glad OpenGL::GL)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
    COMPILE_OPTIONS -Werror
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    CXX_SCAN_FOR_MODULES OFF
)