cmake_minimum_required(VERSION 3.24)
project(Molecule_monster)

set(CMAKE_CXX_STANDARD 14)

add_executable(Molecule_monster main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/dev/DEVEL/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/dev/DEVEL/SFML/include/SFML)
target_link_libraries(Molecule_monster sfml-system sfml-window sfml-graphics sfml-audio)