# CMakeList.txt : CMake project for MSFS-SimConnect-Data, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

add_library(MSFS-SimConnect-Data "MSFS-SimConnect-Data.cpp" "MSFS-SimConnect-DataFormat.cpp" "MSFS-SimConnect-Data.h" "MSFS-SimConnect-DataFormat.h" )
target_link_libraries(MSFS-SimConnect-Data SimConnect )


# Add source to this project's executable.
add_executable (MSFS-SimConnect-Data-CLI "MSFS-SimConnect-CLI.cpp")
target_link_libraries(MSFS-SimConnect-Data-CLI MSFS-SimConnect-Data)

install(TARGETS MSFS-SimConnect-Data-CLI MSFS-SimConnect-Data
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)
# TODO: Add tests and install targets if needed.
