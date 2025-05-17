# CMAKE-OpenGL-Template
This is a CMake OpenGL template originally made in CLION, but it can be used across many different text editors if needed. This project is primarily designed for beginners who are learning practical configuration design patterns. You can also use this project if you don't feel like downloading everything separately.


Project Organization Template

The main idea is that you don't need to memorize this particular content, but you should take into
consideration about the importance of project design in the way C++ code is organized in comparison to other
high level languages. This is not a perfect example but it is something to start with as skills begin developing.
Each sub component should have a CMakeList.txt for the sake of simplicity. You do not want to have every cpp or c
file on add_executable(appname sourcefiles.c, etc.cpp)

game_engine/                     # Root directory for the game engine project
├── CMakeLists.txt              # Root CMake configuration file
├── src/                        # Source files for the engine
│   ├── CMakeLists.txt          # CMake file for the source directory
│   ├── main.cpp                # Entry point of the engine (main executable)
│   ├── engine.cpp              # Core engine logic
│   ├── rendering/              # Rendering module (OpenGL, shaders, etc.)
│   │   ├── CMakeLists.txt
│   │   ├── renderer.cpp
│   │   ├── shader.cpp
│   │   └── renderer.h
│   ├── audio/                  # Audio module
│   │   ├── CMakeLists.txt
│   │   ├── audio_manager.cpp
│   │   └── audio_manager.h
│   ├── physics/                # Physics module
│   │   ├── CMakeLists.txt
│   │   ├── physics_engine.cpp
│   │   └── physics_engine.h
│   ├── input/                  # Input handling module
│   │   ├── CMakeLists.txt
│   │   ├── input_manager.cpp
│   │   └── input_manager.h
│   └── utils/                  # Utility functions (math, file IO, etc.)
│       ├── CMakeLists.txt
│       ├── math_utils.cpp
│       └── file_utils.cpp
├── include/                    # Public header files
│   ├── rendering/
│   │   └── renderer.h
│   ├── audio/
│   │   └── audio_manager.h
│   ├── physics/
│   │   └── physics_engine.h
│   └── utils/
│       └── math_utils.h
├── libs/                       # External libraries
│   ├── glfw/                   # GLFW for window management and input
│   └── glad/                   # GLAD for OpenGL function loading
└── build/                      # Build output directory (generated)

 CMakeList.txt Examples:

 Main CMakeList.txt

 <------------------------------------------------------------------------>
cmake_minimum_required(VERSION 3.31)
project(GameEngine)

set(CMAKE_CXX_STANDARD 20)

# Add external libraries
add_subdirectory(libs/glfw)
add_subdirectory(libs/glad)

# Add source directory containing engine components
add_subdirectory(src)

# Define the main executable
add_executable(GameEngine src/main.cpp)

# Include necessary directories
target_include_directories(GameEngine PRIVATE
    include
    libs/glfw/include
    libs/glad/include
)

# Link libraries and modules
# Uncomment and update as needed
# target_link_libraries(GameEngine PRIVATE glfw glad rendering audio physics input utils)
 <------------------------------------------------------------------------>
# Create the audio static library
add_library(audio STATIC
    audio_manager.cpp
)

# Include headers from the current directory
target_include_directories(audio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
