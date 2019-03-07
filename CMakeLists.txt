cmake_minimum_required(VERSION 2.8)

project(My_Application)
string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_EXTENSIONS OFF) #TODO: Google if I want this, maybe smaller executable?

set(OpenGL_GL_PREFERENCE "GLVND")

set_directory_properties(PROPERTIES
	CORRADE_CXX_STANDARD ${CMAKE_CXX_STANDARD}
	CORRADE_USE_PEDANTIC_FLAGS ON)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")

include(version)
include(project_options)
include(dependencies)

add_subdirectory(src)
#add_subdirectory(tests)
add_subdirectory(apps)
add_subdirectory(plugins)
