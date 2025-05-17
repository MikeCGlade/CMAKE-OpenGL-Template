cmake_minimum_required(VERSION 3.31)
project(ComputerGraphics)

set(CMAKE_CXX_STANDARD 20)

# Add your executable, include glad.c
add_executable(ComputerGraphics
        main.cpp
        gl.c
)

# Add GLFW or access subdirectories
add_subdirectory(libs/glfw)
# Private means that these directories are used only for compiling the ComputerGraphics exe
target_include_directories(ComputerGraphics PRIVATE libs/glfw/include)

# Include GLAD headers
include_directories(libs/glad/include)

# Find OpenGL (Externally installed on computer with Windows etc)
find_package(OpenGL REQUIRED)

# Link everything
target_link_libraries(ComputerGraphics
        glfw
        OpenGL::GL
)

#Project Organization Template

# The main idea is that you don't need to memorize this particular content, but you should take into
# consideration about the importance of project design in the way C++ code is organized in comparison to other
# high level languages. This is not a perfect example but it is something to start with as skills begin developing.
# Each sub component should have a CMakeList.txt for the sake of simplicity. You do not want to have every cpp or c
# file on add_executable(appname sourcefiles.c, etc.cpp)

#game_engine/                  # | Root directory for the game engine project
#├── CMakeLists.txt            # | Root CMake file for the project
#├── src/                      # | Source files
#│   ├── CMakeLists.txt        # | CMake file for the src directory
#│   ├── main.cpp              # | The entry point of your game engine (if an executable)
#│   ├── engine.cpp            # | Core engine logic
#│   ├── rendering/            # | Rendering component
#│   │   ├── CMakeLists.txt    # | CMake file for the rendering component
#│   │   ├── renderer.cpp      # | Rendering code (e.g., OpenGL rendering)
#    │   ├── shader.cpp        # | Shader code for rendering
#│   │   └── renderer.h        # | Header for the renderer class
#│   ├── audio/                # | Audio component
#│   │   ├── CMakeLists.txt    # | CMake file for the audio component
#    │   ├── audio_manager.cpp # | Audio management code
#│   │   └── audio_manager.h   # | Header for the audio manager
#│   ├── physics/              # | Physics component
#│   │   ├── CMakeLists.txt    # | CMake file for the physics component
#│   │   ├── physics_engine.cpp # | Physics engine code
#│   │   └── physics_engine.h   # | Header for the physics engine
#│   ├── input/                # | Input handling component
#│   │   ├── CMakeLists.txt    # | CMake file for the input component
#│   │   ├── input_manager.cpp # | Input handling code
#│   │   └── input_manager.h   # | Header for the input manager
#│   └── utils/                # | Utility functions (math, file handling, etc.)
#│       ├── CMakeLists.txt    # | CMake file for the utils component
#       ├── math_utils.cpp    # | Math utility functions (e.g., matrix operations)
#│       └── file_utils.cpp    # | File handling utility functions
#├── include/                  # | Header files (common interface)
#│   ├── rendering/            # | Rendering headers
#│   │   └── renderer.h        # | Header for the renderer class
#│   ├── audio/                # | Audio headers
#│   │   └── audio_manager.h   # | Header for the audio manager
#│   ├── physics/              # | Physics headers
#│   │   └── physics_engine.h  # | Header for the physics engine
#│   └── utils/                # | Utility headers
#│       └── math_utils.h      # | Header for math utility functions
#├── libs/                     # | External libraries (e.g., GLFW, GLAD)
#│   ├── glfw/                 # | GLFW library for windowing/input
#│   ├── glad/                 # | GLAD for OpenGL function loading
#└── build/                    # | Generated build directory

# CMakeList.txt Examples:

# Main CMakeList.txt

# <------------------------------------------------------------------------>
# cmake_minimum_required(VERSION 3.31)                                 # | Set the minimum CMake version required
# project(GameEngine)                                                  # | Set the project name

# set(CMAKE_CXX_STANDARD 20)                                           # | Set the C++ standard to C++20

#  Add external libraries
# add_subdirectory(libs/glfw)                                          # | Add the GLFW subdirectory for window/input management
# add_subdirectory(libs/glad)                                          # | Add the GLAD subdirectory for OpenGL function loading

#  Add the source directory (which includes all components like rendering, audio, physics, etc.)
# add_subdirectory(src)                                                # | Add the source directory that contains the main engine files

#  Create the main executable for the game engine
# add_executable(GameEngine src/main.cpp)  # | Define the GameEngine executable from the main.cpp file

#  Link all the libraries (including rendering, audio, physics, input, and utils) to the GameEngine
# target_link_libraries(GameEngine PRIVATE glfw glad rendering audio physics input utils)  # | Link all components

#  Include directories for the executable
# target_include_directories(GameEngine PRIVATE                        # | Include the necessary directories for the executable
#         include                                                      # | Include project-specific header files
#         libs/glfw/include                                            # | Include GLFW header files
#         libs/glad/include                                            # | Include GLAD header files
# )
# <------------------------------------------------------------------------>
# Add additional settings for optimizations, warnings, etc. if needed
# For example, you can enable warnings as errors, set debugging flags, etc.

# Subdirectory CMakeList.txt example:

# src/audio/CMakeLists.txt

# Create a static library for audio
# add_library(audio STATIC                   # | Create a static library named 'audio'
#        audio_manager.cpp                   # | Add the source file for the audio manager
# )

# Include the current directory for header files
# target_include_directories(audio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})  # | Make headers available publicly