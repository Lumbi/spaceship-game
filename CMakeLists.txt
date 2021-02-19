cmake_minimum_required(VERSION 3.0.0)
project(shmup VERSION 0.1.0)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(src)
include_directories(/usr/local/include)

find_library(SFML_SYSTEM NAMES sfml-system REQUIRED)
find_library(SFML_WINDOW NAMES sfml-window REQUIRED)
find_library(SFML_GRAPHICS NAMES sfml-graphics REQUIRED)

set(SRC
    src/main.cpp
    src/Game.cpp
    src/Keyboard.cpp
    src/GameContext.cpp
    src/Collider.cpp
    src/Camera.cpp
    src/ShapeSprite.cpp
    src/BloomEffect.cpp
    src/PlayerWeapon.cpp
    src/PlayerShip.cpp
    src/PlayerBullet.cpp
    src/EnemyShip.cpp
    src/Debris.cpp
    src/EnemyHitAnimation.cpp
)
add_executable(${PROJECT_NAME} ${SRC})

# target_link_libraries(${PROJECT_NAME} ${SFML})
target_link_libraries(${PROJECT_NAME} ${SFML_SYSTEM})
target_link_libraries(${PROJECT_NAME} ${SFML_WINDOW})
target_link_libraries(${PROJECT_NAME} ${SFML_GRAPHICS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
