cmake_minimum_required(VERSION 3.28.2)
set(PROJECT_NAME network_scanner)
project(${PROJECT_NAME})

# set c++ standard
set(CMAKE_CXX_STANDARD 17)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# add your source files
set(SOURCE_FILES 
  # src/main.cpp
  src/tcp_port_scanner.cpp
  src/cli.cpp
  )
set (HEADER_FILES
  include/tcp_port_scanner.h
  )


# Add Boost dependency
find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

# Add cxxopts library
set(EXTERNAL_INCLUDE_DIRS external/cxxopts/include)
include_directories(external/cxxopts-3.1.1/include)

# Add the CMAKE_EXPORT_COMPILE_COMMANDS option
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

# Include the 'include/' directory
target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  )



# Add any necessary libraries here (replace library_name with the actual library name)
# find_library(LIBPCAP_LIBRARY pcap)
# target_link_libraries(NetworkScanner ${LIBPCAP_LIBRARY})

# Optionally, enable threading (if your project uses multithreading)
# find_package(Threads REQUIRED)
# target_link_libraries(NetworkScanner Threads::Threads)
