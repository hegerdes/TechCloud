###############################################################################
# Declare the minimum cmake version required
###############################################################################
cmake_minimum_required(VERSION 3.0.2)

###############################################################################
# The name of out project
###############################################################################
project(Tech_Cloud)

###############################################################################
# Now you would normally declare additional linker and include directories.
# We don't need this at this moment, just to show you how its done
###############################################################################

#link_directories("${CMAKE_SOURCE_DIR}/lib")
#link_directories("$ENV{HOME}/local/lib")

#include_directories(${CMAKE_SOURCE_DIR}/ext/Eigen)
#include_directories(${CMAKE_SOURCE_DIR})
#include_directories(${CMAKE_SOURCE_DIR}/src/lib)

###############################################################################
# Extend path to search for local cmake modules
###############################################################################

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

###############################################################################
# With cmake we can define additional compiler flags for different
# configurations. CMAKE_CXX_FLAGS are for the default case. The debug config
# can be used to generate debug symbols for gdb. The release option uses
# special optimization flags
###############################################################################

set( CMAKE_CXX_FLAGS         "-std=c++17 -O3 -Wall" )
set( CMAKE_CXX_FLAGS_RELEASE "-std=c++17 -O3 -msse3 -Wno-deprecated-declarations -Wno-unused -Wcpp" )
set( CMAKE_CXX_FLAGS_DEBUG   "-g -Wall -std=c++17" )

###############################################################################
# Find required libraries. The required
# options forces this packages to be present. For non-mandatory packages you
# can leave this flag out. The can then check if they were found by using
# IF(OpenGL_found) etc.
###############################################################################

include_directories(${CMAKE_SOURCE_DIR})

set(Boost_USE_MULTITHREADED     ON)

find_package( Boost 1.54
    COMPONENTS
    program_options
    filesystem
    system
    thread
    serialization
    REQUIRED )

link_directories(${Boost_LIBRARY_DIR})
include_directories(${Boost_INCLUDE_DIRS})
add_definitions(${Boost_LIB_DIAGNOSTIC_DEFINITIONS})

###############################################################################
# Find and setup Qt5
###############################################################################

set( QT_USE_QTOPENGL TRUE )
find_package( Qt5
    COMPONENTS
    Core
    Network
    Widgets
    Concurrent
    OpenGL
    Multimedia
    REQUIRED
)
find_package(Qt5Multimedia REQUIRED)

include_directories(${Qt5Widgets_INCLUDE_DIRS})
include_directories(${Qt5Concurrent_INCLUDE_DIRS})
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Network_INCLUDE_DIRS})
include_directories(${Qt5OpenGL_INCLUDE_DIRS})

###############################################################################
# Variable for the sources of the binary. In larger projects it is often a
# good idea to use such variables because it is easy to add more source files
# and you can reuse it for several targets (maybe you want to build a library
# some day ;-)
###############################################################################

set(TECHCLOUD_SOURCES
    src\ui\ResultWindow.cpp
    main.cpp
    src\ui\MainWindow.cpp
)

set(TECHCLOUD_MOCS
    src\ui\ResultWindow.h
    src\ui\MainWindow.h
)

set(TECHCLOUD_UIS
    src\ui\ResultWindow.ui
    src\ui\MainWindow.ui
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

qt5_wrap_ui(TECHCLOUD_UI_HDRS ${TECHCLOUD_UIS})
message(STATUS ${TECHCLOUD_UI_HDRS})

add_definitions(${QT_DEFINITIONS})


set(TECHCLOUD_DEPENDS
    ${Boost_PROGRAM_OPTIONS_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_THREAD_LIBRARY}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Qt5Widgets_LIBRARIES}
    ${Qt5Network_LIBRARIES}
)

###############################################################################
# The executable of our project
###############################################################################

add_executable(TechCloud
    ${TECHCLOUD_SOURCES}
    ${TECHCLOUD_MOCS}
    ${TECHCLOUD_UI_HDRS}
)

qt5_use_modules(TechCloud Multimedia)

###############################################################################
# External library dependencys
###############################################################################

target_link_libraries(TechCloud ${TECHCLOUD_DEPENDS})
