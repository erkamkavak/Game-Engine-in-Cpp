cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME Brix)
project(${PROJECT_NAME})

# add_compile_options(-std=c++14)
# add_compile_options(-O2)
# add_compile_options(-pthread)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})


find_package(OpenGL)
find_package(SDL2 REQUIRED)
# find_package(SDL2_image REQUIRED)
# find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window system)
# find_package(wxWidgets REQUIRED COMPONENTS net core base)

# Add definitions
# add_definitions()

# Include directories and files
include_directories(
  ${SDL2_INCLUDE_DIRS}
  include
  libs/spdlog/include
)

file(GLOB source_files "src/*.cpp" "include/*.h")
# file(GLOB_RECURSE lib_files "libs/*.h" "libs/*.c" "libs/*.cpp")

set(SOURCES ${source_files})
set(LIBRARIES
  # sfml-system
  # sfml-window
  # sfml-graphics
  # ${wxWidgets_LIBRARIES}
  ${SDL2_LIBRARIES}
  # ${SDL2_IMAGE_LIBRARIES}
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})


if (UNIX)
   target_link_libraries(${PROJECT_NAME} pthread)
endif (UNIX)