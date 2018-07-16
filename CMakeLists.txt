cmake_minimum_required(VERSION 3.1)
include(ExternalProject)

set(default_build_type "Release")
if(CMAKE_BUILD_TYPE)
  message(STATUS "Build type is '${CMAKE_BUILD_TYPE}'.")
else()
  message(STATUS "Setting build type to '${default_build_type}'.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Build type (default ${default_build_type})" FORCE)
endif()

set(LUCAS_VERSION master)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)


#######################################
# RocksDB Required OS flags
########################################
if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    add_definitions(-DOS_MACOSX)
endif ()


#######################################
# Fetch and Build Lucas
#######################################

set(LUCAS_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/external/out/lucas)
ExternalProject_Add(
  lucas
  DOWNLOAD_COMMAND bash -c "rm -rf ${CMAKE_CURRENT_BINARY_DIR}/external/src/lucas && wget -nc -P ${CMAKE_CURRENT_BINARY_DIR}/../download/lucas https://github.com/stardog-union/lucas/archive/${LUCAS_VERSION}.zip && unzip ${CMAKE_CURRENT_BINARY_DIR}/../download/lucas/${LUCAS_VERSION}.zip -d ${CMAKE_CURRENT_BINARY_DIR}/external/src && mv ${CMAKE_CURRENT_BINARY_DIR}/external/src/lucas-${LUCAS_VERSION} ${CMAKE_CURRENT_BINARY_DIR}/external/src/lucas"
  PREFIX external
  DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}/../download/lucas
  INSTALL_DIR external/out/lucas
  CMAKE_ARGS
      -DBUILD_SHARED_LIBS=OFF
      -DCMAKE_INSTALL_PREFIX=${LUCAS_INSTALL_DIR}
      -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
      -DCMAKE_POSITION_INDEPENDENT_CODE=on
      -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
  LOG_DOWNLOAD ON
)

ExternalProject_Get_Property(lucas install_dir)
set(LUCAS_INCLUDE_DIR ${install_dir}/include)
include_directories(${LUCAS_INCLUDE_DIR})


#######################################
# Build mersenne
#######################################

set(COMMON_FLAGS "-Wall -Werror=reorder -Wno-unused-function -pedantic -Wno-unknown-pragmas -Wno-vla -pthread -U_FORTIFY_SOURCE -fno-omit-frame-pointer -fno-common")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} ${COMMON_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} ${COMMON_FLAGS}")

add_executable(mersenne mersenne.cc)
add_dependencies(mersenne lucas)
