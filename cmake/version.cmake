# Project version

set(${PROJECT_NAME_LOWER}_VERSION_MAJOR 0)
set(${PROJECT_NAME_LOWER}_VERSION_MINOR 0)
set(${PROJECT_NAME_LOWER}_VERSION_MICRO 0)

configure_file (
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
)

include_directories(${PROJECT_BINARY_DIR})
