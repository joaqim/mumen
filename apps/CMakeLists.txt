find_package(Magnum REQUIRED GL Sdl2Application)

set_directory_properties(PROPERTIES CORRADE_USE_PEDANTIC_FLAGS ON)

add_executable(${PROJECT_NAME}_main MyApplication.cpp)
target_link_libraries(${PROJECT_NAME}_main PRIVATE
    Magnum::Application
    Magnum::GL
    Magnum::Magnum
    ${PROJECT_NAME_LOWER}
    )

if(CORRADE_TARGET_EMSCRIPTEN)
	#set_target_properties(${PROJECT_NAME}_main PROPERTIES LINK_FLAGS "-s SIDE_MODULE=1 -s EXPORT_ALL=1 -s DISABLE_EXCEPTION_CATCHING=0 -s FORCE_FILESYSTEM=1 -s SINGLE_FILE=1 -s BINARYEN_ASYNC_COMPILATION=0")
	set_target_properties(${PROJECT_NAME}_main PROPERTIES LINK_FLAGS "-s MAIN_MODULE=1 -s EXPORT_ALL=1 -s BINARYEN_ASYNC_COMPILATION=0 -s WASM=0 -s DEMANGLE_SUPPORT=1 ")
	install(TARGETS ${PROJECT_NAME}_main DESTINATION ${CMAKE_INSTALL_PREFIX} COMPONENT test_runner)
	install(FILES
		#${PROJECT_NAME}.html
		MyApplication.html
		EmscriptenApplication.js
		WebApplication.css
		DESTINATION ${CMAKE_INSTALL_PREFIX})
	install(FILES
		${CMAKE_CURRENT_BINARY_DIR}/MyApplication.js.mem
		${CMAKE_CURRENT_BINARY_DIR}/MyApplication.wasm
		DESTINATION ${CMAKE_INSTALL_PREFIX} OPTIONAL)
endif()

include_directories(${PROJECT_SOURCE_DIR}/src)
