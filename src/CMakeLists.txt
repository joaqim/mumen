#set(lib${PROJECT_NAME_LOWER}_sources dummy.cpp)
file(GLOB lib${PROJECT_NAME_LOWER}_sources *.cpp)

#corrade_add_resource(src_RESOURCES resources.conf)

add_library(${PROJECT_NAME_LOWER} ${lib${PROJECT_NAME_LOWER}_sources} ${src_RESOURCES})
if(CORRADE_TARGET_EMSCRIPTEN)
	#set_target_properties(${PROJECT_NAME_LOWER} PROPERTIES LINK_FLAGS "-s SIDE_MODULE=1 -s EXPORT_ALL=1 -s DISABLE_EXCEPTION_CATCHING=0 -s FORCE_FILESYSTEM=1 -s SINGLE_FILE=1 -s BINARYEN_ASYNC_COMPILATION=0")
	set_target_properties(${PROJECT_NAME_LOWER} PROPERTIES LINK_FLAGS "-s SIDE_MODULE=1 -s EXPORT_ALL=1 -s WASM=1")
endif()

install(TARGETS ${PROJECT_NAME_LOWER} DESTINATION ${CMAKE_BINARY_DIR})
