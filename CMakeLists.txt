cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME Brix)
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

find_package(OpenGL)
# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SDL REQUIRED)
find_package(SFML 2 REQUIRED COMPONENTS network audio graphics window system)
find_package(wxWidgets REQUIRED COMPONENTS net core base)

# Add definitions
# add_definitions()

# Include directories and files
include_directories(
    PRIVATE
    "include"
    "libs/spdlog/include"
    ${SDL2_INCLUDE_DIRS}
  )
include(
    ${wxWidgets_USE_FILE}
)

file(GLOB source_files
	"src/*.cpp"
)

set(SOURCES ${source_files})
set(LIBRARIES
  sfml-system
  sfml-window
  sfml-graphics
  ${wxWidgets_LIBRARIES}
  ${SDL2_LIBRARIES}
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})


if (UNIX)
   target_link_libraries(${PROJECT_NAME} pthread)
endif (UNIX)