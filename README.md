# CMAKE-OpenGL-Template
This is a CMake OpenGL template originally made in CLION, but it can be used across many different text editors if needed. This project is primarily designed for beginners who are learning practical configuration design patterns. You can also use this project if you don't feel like downloading everything separately.


# Project Organization Template

The main idea is that you don't need to memorize this particular content, but you should take into
consideration about the importance of project design in the way C++ code is organized in comparison to other
high level languages. This is not a perfect example but it is something to start with as skills begin developing.
Each sub component should have a CMakeList.txt for the sake of simplicity. You do not want to have every cpp or c
file on add_executable(appname sourcefiles.c, etc.cpp)
