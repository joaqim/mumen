include_directories(${PROJECT_SOURCE_DIR}/third_party/include ${PROJECT_SOURCE_DIR}/src)


if(${PROJECT_NAME}_BUILD_TESTS)
    file(GLOB test_sources *.cpp)

    #list(REMOVE_ITEM test_sources test_dummy.cpp)

    add_executable(test_runner ${test_sources})
    target_link_libraries(test_runner ${PROJECT_NAME_LOWER})

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -ldl")
    add_test(test_runner test_runner)

    if(CORRADE_TARGET_EMSCRIPTEN)
	    set_target_properties(test_runner PROPERTIES LINK_FLAGS "-s MAIN_MODULE=1 -s EXPORT_ALL=1")
	    install(TARGETS test_runner DESTINATION ${CMAKE_INSTALL_PREFIX})

	    install(FILES
		    test_runner.html
		    DESTINATION ${CMAKE_INSTALL_PREFIX}
		    )
	    install(FILES
		    ${CMAKE_CURRENT_BINARY_DIR}/test_runner.js.mem
		    ${CMAKE_CURRENT_BINARY_DIR}/test_runner.wasm
		    DESTINATION ${CMAKE_INSTALL_PREFIX} OPTIONAL)
    endif()
endif()
