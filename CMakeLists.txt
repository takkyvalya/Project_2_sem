cmake_minimum_required(VERSION 3.24)
project(Susuwatari)

set(CMAKE_CXX_STANDARD 17)

add_executable(Susuwatari main.cpp Game.h Game.cpp
        Map/Map.h Entity.h Entity.cpp Map/Map.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Program Files (x86)/SFML-2.5.1/lib/cmake/SFML)
#C:/Users/vtakk/CLionProjects/2_semestr/LaboratoryWork_1/SFML-2.5.1/include/SFML/Graphics.hpp
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
#file(COPY Game/arial.ttf DESTINATION "/")
include_directories(C:/Program Files (x86)/SFML-2.5.1/include)
target_link_libraries(Susuwatari sfml-system sfml-window sfml-graphics sfml-audio)
