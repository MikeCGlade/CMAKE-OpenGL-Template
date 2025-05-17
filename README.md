# CMAKE-OpenGL-Template
This is a CMake OpenGL template originally made in CLION, but it can be used across many different text editors if needed. This project is primarily designed for beginners who are learning practical configuration design patterns. You can also use this project if you don't feel like downloading everything separately.


# Project Organization Template

The primary goal is not to memorize the specific structure of this project, but to understand the importance of thoughtful project design—particularly how C++ code organization differs from that of other high-level languages. While this is not a definitive or production-ready example, it serves as a solid starting point for developing best practices as your skills grow.

To maintain clarity and scalability, each module or component should include its own CMakeLists.txt file. This modular approach helps avoid cluttering the main build configuration with a long list of source files in a single add_executable() call. Instead, individual libraries can be built per component and linked as needed, leading to a cleaner and more maintainable build system.
