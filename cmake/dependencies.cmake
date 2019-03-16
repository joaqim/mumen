# Find dependencies


include(FindPkgConfig)
if(${WITH_OPENCV})
	find_package(OpenCV REQUIRED)
	#pkg_search_module(OPENCV REQUIRED QUIET opencv)
	include_directories(${OPENCV_INCLUDE_DIRS})
endif()

# glfw3
#find_package(glfw3 REQUIRED)
#include_directories(${GLFW_INCLUDE_DIRS})

# opengl
#find_package(OpenGL REQUIRED)
#include_directories(${OPENGL_INCLUDE_DIRS})

# glew
#find_package(GLEW REQUIRED)
#include_directories(${GLEW_INCLUDE_DIRS})
