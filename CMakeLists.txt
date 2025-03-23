# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.31)

project ("Daedalus_One")

set(CMAKE_CXX_STANDARD 17)
set(CXXFLAGS "/std:c++17")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

# Include sub-projects.
add_subdirectory ("Daedalus_One")
add_subdirectory ("Daedalus_One/vehicle")
add_subdirectory ("Daedalus_One/physics")

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
 SFML
 GIT_REPOSITORY https://github.com/SFML/SFML.git
 #GIT_TAG 2.5.1
 GIT_TAG 3.0.0
)
FetchContent_MakeAvailable(SFML)

# Copy assets
add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_LIST_DIR}/copy-assets.cmake
)
add_dependencies(Daedalus_One copy_assets)