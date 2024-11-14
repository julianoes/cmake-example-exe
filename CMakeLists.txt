cmake_minimum_required(VERSION 3.16)

# create project
project(example-exe
    LANGUAGES CXX)

include(GNUInstallDirs)

if (USE_CPM)
    include(cmake/CPM.cmake)
    CPMAddPackage(NAME example-lib
        GITHUB_REPOSITORY julianoes/cmake-example-lib
        GIT_TAG c790756
    )
message(STATUS "Added: ${CPM_LAST_PACKAGE_NAME}")
    add_library(example-lib::example-lib ALIAS example-lib)
else()
    find_package(example-lib REQUIRED)
endif()

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} example-lib::example-lib)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")

install(TARGETS ${PROJECT_NAME})
