cmake_minimum_required(VERSION 3.11)
project(shooter)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(sources main.cpp world.cpp entity.cpp item.cpp position.cpp player.cpp zombie.cpp character.cpp drawmanager.cpp game.cpp inputmanager.cpp ncurseswrapper.cpp logger.cpp)

add_executable(shooter ${sources})
target_link_libraries(shooter ncurses ${CMAKE_SOURCE_DIR}/lib/libfmt.a)
set_target_properties(shooter PROPERTIES COMPILE_FLAGS "-Wall -Werror -Wextra -g" LINK_FLAGS "-pthread")
