cmake_minimum_required(VERSION 2.8)
project(libmcmap CXX)

find_package(ZLIB REQUIRED)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
   add_definitions(-DDEBUG -O0 -ggdb3)
else()
   add_definitions(-O2 -s -march=native)
endif()

add_definitions(-fPIC -Wextra -Wall -pipe -std=gnu++11 -I${LIBNBT_DIR})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${ZLIB_INCLUDE_DIRS})

option(LIBNBT_DIR "path to libnbt")

add_library(mcmap SHARED
	src/Block.cpp
	src/BlockMaps.cpp
	src/Chunk.cpp
	src/Level.cpp
	src/Map.cpp
	src/Player.cpp
	src/MCRegion.cpp
	src/PairHash.cpp
	include/Block.h
	include/BlockMaps.h
	include/Chunk.h
	include/Level.h
	include/Map.h
	include/Player.h
	include/MCRegion.h
	include/PairHash.h
)

target_link_libraries(mcmap ${ZLIB_LIBRARIES} -lnbt)
