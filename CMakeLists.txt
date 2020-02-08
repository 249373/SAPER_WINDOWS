cmake_minimum_required(VERSION 3.13)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled2 main.cpp IntroView.cpp IntroView.h IntroController.cpp IntroController.h ScoreView.cpp ScoreView.h ScoreController.cpp ScoreController.h GameManager.cpp GameManager.h MinesweeperView.cpp MinesweeperView.h MinesweeperController.cpp MinesweeperController.h MinesweeperBoard.cpp MinesweeperBoard.h IntroModel.cpp IntroModel.h ScoreModel.cpp ScoreModel.h)


# Detect and add SFML
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED graphics window system audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(untitled2 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()