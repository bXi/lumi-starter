cmake_minimum_required(VERSION 3.22)

project("luminoveau-starter")
# We require C++17 as a minimum
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable("luminoveau-starter" "src/main.cpp")

add_subdirectory(luminoveau)
target_link_libraries("luminoveau-starter" luminoveau)
target_include_directories("luminoveau-starter" PRIVATE luminoveau)

set(ASSETS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assets")

if(EXISTS ${ASSETS_SOURCE_DIR})
    message("Copying assets from '${ASSETS_SOURCE_DIR}' to '${ASSETS_DEST_DIR}'")

    set(ASSETS_DEST_DIR "${CMAKE_BINARY_DIR}/assets")

    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${ASSETS_SOURCE_DIR}
            ${ASSETS_DEST_DIR}
    )
else()
    message("Assets source directory not found: ${ASSETS_SOURCE_DIR}")
endif()
