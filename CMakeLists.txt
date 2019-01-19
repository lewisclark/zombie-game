cmake_minimum_required(VERSION 3.11)
project(game)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# For Vim YCM
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# libfmt
include_directories(fmt/include)
add_subdirectory(fmt)

# Sources to compile
set(sources
	main.cpp logger.cpp sdlmanager.cpp window.cpp renderer.cpp world.cpp
	entities/entity.cpp entities/item.cpp entities/player.cpp entities/zombie.cpp
	entities/character.cpp entities/projectile.cpp entities/bullet.cpp entities/entityfactory.cpp
	position.cpp drawmanager.cpp game.cpp inputmanager.cpp color.cpp)

add_executable(game ${sources})
target_link_libraries(game ${SDL2_LIBRARIES} fmt)
set_target_properties(game PROPERTIES COMPILE_FLAGS "-Wall -Werror -Wextra -g" LINK_FLAGS "-lSDL2")
