# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("MSFS-SimConnect-Data")
INCLUDE_DIRECTORIES("C:/MSFS SDK/SimConnect SDK/include/" "C:/usr/include/")
LINK_DIRECTORIES("C:/MSFS SDK/SimConnect SDK/lib" "C:/usr/lib")
# Include sub-projects.
add_subdirectory ("MSFS-SimConnect-Data")
