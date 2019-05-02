cmake_minimum_required(VERSION 2.4.0)
project(pokemon_random)

find_package(SDL2 REQUIRED OPTIONAL_COMPONENTS image ttf)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${SDL2_INCLUDE_DIRS}
    )
    
message(STATUS "SDL2 Include Dirs = ${SDL2_INCLUDE_DIRS}")
message(STATUS "SDL2 Libraries = ${SDL2_LIBRARIES}")
    
set(SRC_FILES
    src/Adventure.cpp
    src/Layer.cpp
    src/Pokemon.cpp
    src/Animation.cpp
    src/Main.cpp
    src/Sprite.cpp
    src/Attack.cpp
    src/Map.cpp
    src/Text_Manager.cpp
    src/Constants.cpp
    src/Map_Manager.cpp
    src/Texture.cpp
    src/Dialog.cpp
    src/Movable_Thing.cpp
    src/Thing.cpp
    src/Enemy.cpp
    src/Movable_Trainer.cpp
    src/Timer.cpp
    src/Fight.cpp
    src/Player.cpp
    src/Vector2D.cpp
    src/Interaction.cpp
    src/Player_Trainer.cpp
    src/World.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2_image SDL2_ttf)
