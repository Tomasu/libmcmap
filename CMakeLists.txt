project(mcmap CXX)

find_package(ZLIB)
include_directories(${ZLIB_INCLUDE_DIRS})

if(NOT ${ZLIB_LIBRARY})
	set(ZLIB_LIBRARY "/usr/lib/x86_64-linux-gnu/libz.so")
endif(NOT ${ZLIB_LIBRARY})

add_definitions(-fPIC ${NBT_CFLAGS})

add_library(mcmap SHARED
	Block.cpp
	BlockMaps.cpp
	Chunk.cpp
	Map.cpp
	Region.cpp
)

add_dependencies(mcmap nbt)
target_link_libraries(mcmap ${ZLIB_LIBRARIES} ${NBT_LIBS})

set(MAP_CFLAGS -I${CMAKE_CURRENT_SOURCE_DIR} ${NBT_CFLAGS} PARENT_SCOPE)
set(MAP_LIBS ${NBT_LIBS} -Wl,--rpath,${CMAKE_CURRENT_BINARY_DIR} -L${CMAKE_CURRENT_BINARY_DIR} -lmcmap PARENT_SCOPE)
