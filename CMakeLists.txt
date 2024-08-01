cmake_minimum_required(VERSION 3.10)
project(Boids)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find all project files
file(GLOB_RECURSE SOURCES "src/**/*.cpp")
file(GLOB_RECURSE HEADERS "src/**/*.hpp")

# Executable
add_executable(Boids ${SOURCES} ${HEADERS})

# Include GLAD
add_library(glad STATIC
	lib/glad/glad.c
)
target_include_directories(glad PUBLIC lib/glad/include)

# Include GLFW
add_library(glfw STATIC IMPORTED)
set_target_properties(glfw PROPERTIES
	IMPORTED_LOCATION	"${CMAKE_SOURCE_DIR}/lib/glfw-3.4/build/src/libglfw3.a"
	INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/lib/glfw-3.4/include"
)

# Include libraries directories
target_include_directories(Boids PRIVATE 
	src 
	lib
)

find_package(OpenGL REQUIRED)

# Add libraries
target_link_libraries(Boids PRIVATE
	OpenGL::GL
	glfw
	glad
)

# Add shader files to build directory
add_custom_command(TARGET Boids POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/res/shaders $<TARGET_FILE_DIR:Boids>/shaders)
