CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test test.cpp enemy.cpp entity.cpp boss.cpp hero.cpp factory.cpp) 

ADD_EXECUTABLE(rpgGame main.cpp battle.cpp factory.cpp entity.cpp hero.cpp enemy.cpp boss.cpp)


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
