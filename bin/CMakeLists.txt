# Deal with all the versions here
cmake_minimum_required (VERSION 3.21) 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(hello_bin VERSION 0.0.1 DESCRIPTION "Hello Example Binary")

# Add all the source files here
set(SOURCE_FILES "main.cpp") 
add_executable (hello_bin ${SOURCE_FILES})

# Connecting the library, specify where to get the header files
include_directories("../lib")
# Do we want a shared or static lib?
set(HELLO_BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)")
# And also we specify dependence on static library
target_link_libraries(hello_bin libhello)

# Copy the required library files over the the executable
if (HELLO_BUILD_SHARED_LIBS)
    add_custom_command(TARGET hello_bin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:hello_bin> $<TARGET_FILE_DIR:hello_bin>
    COMMAND_EXPAND_LISTS
    )
endif()
