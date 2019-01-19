cmake_minimum_required(VERSION 3.11)
project(shooter)

# For Vim YCM
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# libfmt
include_directories(fmt/include)
add_subdirectory(fmt)

# Sources to compile
set(sources main.cpp sdlmanager.cpp window.cpp renderer.cpp world.cpp entity.cpp item.cpp position.cpp player.cpp zombie.cpp character.cpp drawmanager.cpp game.cpp inputmanager.cpp logger.cpp color.cpp)

add_executable(shooter ${sources})
target_link_libraries(shooter ${SDL2_LIBRARIES} fmt)
set_target_properties(shooter PROPERTIES COMPILE_FLAGS "-Wall -Werror -Wextra -g" LINK_FLAGS "-lSDL2")
