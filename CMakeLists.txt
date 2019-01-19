cmake_minimum_required(VERSION 3.11)
project(shooter)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(fmt/include)

set(sources main.cpp sdlmanager.cpp window.cpp renderer.cpp world.cpp entity.cpp item.cpp position.cpp player.cpp zombie.cpp character.cpp drawmanager.cpp game.cpp inputmanager.cpp logger.cpp color.cpp)

add_executable(shooter ${sources})
target_link_libraries(shooter ${SDL2_LIBRARIES} ${CMAKE_SOURCE_DIR}/fmt/build/libfmt.a)
set_target_properties(shooter PROPERTIES COMPILE_FLAGS "-Wall -Werror -Wextra -g" LINK_FLAGS "-lSDL2")
