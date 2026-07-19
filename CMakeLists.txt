cmake_minimum_required(VERSION 3.14)

project(tui-sudoku LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(FTXUI_DEV_WARNINGS ON)
set(FTXUI_ENABLE_CCACHE ON)

include(FetchContent)

FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI.git
  GIT_TAG         v7.0.0
)

FetchContent_MakeAvailable(ftxui)

# add_executable(tui-sudoku src/main.cpp src/io.cpp src/ui-comp.cpp)
add_executable(tui-sudoku src/main.cpp)

target_compile_definitions(tui-sudoku PRIVATE PROJECT_ROOT_DIR="${CMAKE_SOURCE_DIR}")

target_include_directories(tui-sudoku PRIVATE include)

target_link_libraries(tui-sudoku PUBLIC
  ftxui::screen
  ftxui::dom
  ftxui::component
)
