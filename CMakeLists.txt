cmake_minimum_required(VERSION 3.25)
project(HumansVsZombies)

set(CMAKE_CXX_STANDARD 17)

add_executable(HumansVsZombies main.cpp inc/Organism.h src/Organism.cpp inc/City.h src/City.cpp inc/Human.h inc/Zombie.h src/Human.cpp src/Zombie.cpp inc/GameSpecs.h)
