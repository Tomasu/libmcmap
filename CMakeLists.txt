cmake_minimum_required(VERSION 2.8)
project(libmcmap CXX)

set(LIBMCMAP_MAJOR_VERSION 0)
set(LIBMCMAP_MINOR_VERSION 1)
set(LIBMCMAP_PATCH_VERSION 0)
set(LIBMCMAP_VERSION
  ${LIBMCMAP_MAJOR_VERSION}.${LIBMCMAP_MINOR_VERSION}.${LIBMCMAP_PATCH_VERSION})
  
find_package(ZLIB REQUIRED)
find_package(LibNBT REQUIRED)
find_package(LibIOAccess REQUIRED)

option(SHARED "Build shared library" ON)
set(MODE SHARED)

include_directories(${CMAKE_SOURCE_DIR}/vendor/rapidjson/include)

if(NOT SHARED)
	add_definitions(-static)
	set(MODE STATIC)
endif()

if(CMAKE_BUILD_TYPE STREQUAL Debug)
   add_definitions(-DDEBUG -O0 -ggdb3)
else()
   add_definitions(-DDEBUG -O2 -s -march=native)
endif()

add_definitions(-fPIC -Wextra -Wall -pipe -std=gnu++11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/vendor/rapidjson/include ${ZLIB_INCLUDE_DIRS} ${LIBNBT_INCLUDE_DIRS} ${LIBIOACCESS_INCLUDE_DIRS})

# Offer the user the choice of overriding the installation directories

set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")

if(WIN32 AND NOT CYGWIN)
  set(DEF_INSTALL_CMAKE_DIR CMake)
else()
  set(DEF_INSTALL_CMAKE_DIR lib/cmake/LibMCMap)
endif()
set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH
  "Installation directory for CMake files")
 
# Make relative paths absolute (needed later on)
foreach(p LIB BIN INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()


set(MCMAP_HEADERS
	include/Block.h
	include/BlockMaps.h
	include/BlockState.h
	include/BlockStateValue.h
	include/BlockStateValueConvert.h
	include/BlockAddress.h
	include/BlockInfo.h
	include/Chunk.h
	include/ChunkSection.h
	include/CustomVertex.h
	include/Level.h
	include/Map.h
	include/Minecraft.h
	include/Player.h
	include/MCRegion.h
	include/PairHash.h
	include/Util.h
	include/Model/Coords.h
	include/Model/Element.h
	include/Model/Face.h
	include/Model/Model.h
	include/Model/Rotation.h
	include/Model/Variant.h
)

set(MCMAP_SOURCES
	src/Block.cpp
	src/BlockMaps.cpp
	src/BlockState.cpp
	src/BlockStateValue.cpp
	src/Chunk.cpp
	src/ChunkSection.cpp
	src/Level.cpp
	src/Map.cpp
	src/Minecraft.cpp
	src/Player.cpp
	src/MCRegion.cpp
	src/PairHash.cpp
	src/Model/Model.cpp
	src/Model/Element.cpp
	src/Model/Face.cpp
	src/Model/Rotation.cpp
	src/Model/Variant.cpp
)

set(LIBS ${ZLIB_LIBRARIES} ${LIBNBT_LIBRARIES} ${LIBIOACCESS_LIBRARIES})

add_library(mcmap ${MODE} ${MCMAP_SOURCES} ${MCMAP_HEADERS})
target_link_libraries(mcmap ${LIBS})

message(STATUS "libs: " ${LIBS})

set_target_properties(mcmap PROPERTIES PUBLIC_HEADER "${MCMAP_HEADERS}")

# Add all targets to the build-tree export set
export(TARGETS mcmap
  FILE "${PROJECT_BINARY_DIR}/LibMCMapTargets.cmake")
  
# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)
export(PACKAGE LibMCMap)

# Create the LibNBTConfig.cmake and LibNBTConfigVersion files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}"
   "${INSTALL_INCLUDE_DIR}")
   
# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include" "${PROJECT_BINARY_DIR}")
configure_file(cmake/LibMCMapConfig.cmake.in
  "${PROJECT_BINARY_DIR}/LibMCMapConfig.cmake" @ONLY)

# ... for the install tree
set(CONF_INCLUDE_DIRS "\${LIBMCMAP_CMAKE_DIR}/${REL_INCLUDE_DIR}/libmcmap")
configure_file(cmake/LibMCMapConfig.cmake.in
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/LibMCMapConfig.cmake" @ONLY)
# ... for both
configure_file(cmake/LibMCMapConfigVersion.cmake.in
  "${PROJECT_BINARY_DIR}/LibMCMapConfigVersion.cmake" @ONLY)
 
# Install the LibMCMapConfig.cmake and LibMCMapConfigVersion.cmake
install(FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/LibMCMapConfig.cmake"
  "${PROJECT_BINARY_DIR}/LibMCMapConfigVersion.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)
 
# Install the export set for use with the install-tree
install(EXPORT LibMCMapTargets DESTINATION
  "${INSTALL_CMAKE_DIR}" COMPONENT dev)

install(TARGETS mcmap
	# IMPORTANT: Add the libnbt library to the "export-set"
	EXPORT LibMCMapTargets
	RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
	LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
	ARCHIVE DESTINATION "${INSTALL_LIB_DIR}" COMPONENT lib
	PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/libmcmap"
	COMPONENT dev)


