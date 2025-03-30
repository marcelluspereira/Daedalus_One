# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.31)

project (Daedalus_One VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CXXFLAGS "/std:c++17")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

# Include sub-projects.
add_subdirectory ("Daedalus_One")
add_subdirectory ("Daedalus_One/vehicle")
add_subdirectory ("Daedalus_One/physics")
add_subdirectory ("Daedalus_One/map_manager")


# SFML
include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
 SFML
 GIT_REPOSITORY https://github.com/SFML/SFML.git
 #GIT_TAG 2.5.1
 GIT_TAG 3.0.0
)
FetchContent_MakeAvailable(SFML)

# VCPKG
#-DCMAKE_TOOLCHAIN_FILE=C:/Users/marce/source/repos/vcpkg/scripts/buildsystems/vcpkg.cmake
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

#TESTING ---
# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#enable_testing()

# Add your main test executable
#add_executable(
#  GameTests
#  ut/ut_game.cpp
#)

# Link GoogleTest to your test targets
#target_link_libraries(
#  GameTests
#  gtest_main
#)

#include(GoogleTest)
#gtest_discover_tests(GameTests)

#--- TESTING

# Copy assets
add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_LIST_DIR}/copy-assets.cmake
)
add_dependencies(Daedalus_One copy_assets)