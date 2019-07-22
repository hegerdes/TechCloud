###############################################################################
# Declare the minimum cmake version required
###############################################################################
cmake_minimum_required(VERSION 3.6)

###############################################################################
# The name of out project
###############################################################################
project(tech_cloud)

###############################################################################
# Now add and declare additional linker and include directories.
###############################################################################
#set(JSON_BuildTests OFF CACHE INTERNAL "")
#add_subdirectory(ext_lib/nlohmannJSON)

###############################################################################
# Extend path to search for local cmake modules
###############################################################################
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(GENARAL_INCLUDE ${CMAKE_SOURCE_DIR}/include)
set(UI_INCLUDE ${GENARAL_INCLUDE}/ui)
set(READER_INCLUDE ${GENARAL_INCLUDE}/reader)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${GENARAL_INCLUDE})
include_directories(${UI_INCLUDE})
include_directories(${READER_INCLUDE})


###############################################################################
#Add additional paths that will be searched with find_package
###############################################################################
IF (WIN32)
    set (CMAKE_PREFIX_PATH "C:/Qt/5.12.2/msvc2017_64")
    SET(BOOST_ROOT "C:/libs/boost_1_70_0")
    SET(BOOST_LIBRARYDIR "C:/libs/boost_1_70_0/msvclibs_all/lib")
    SET(Boost_NAMESPACE "libboost")
ENDIF()

###############################################################################
# Set additional compiler flags for different configurations.
###############################################################################
set( CMAKE_CXX_FLAGS         "-std=c++17 -O3 -Wall" )
set( CMAKE_CXX_FLAGS_RELEASE "-std=c++17 -O3 -msse3 -Wno-deprecated-declarations -Wno-unused -Wcpp" )
set( CMAKE_CXX_FLAGS_DEBUG   "-g -Wall -std=c++17" )

###############################################################################
# Find required libraries.
###############################################################################
set(Boost_USE_MULTITHREADED     ON)
find_package( Boost 1.50
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
find_package(Qt5 REQUIRED
    COMPONENTS
    Core
    Network
    Widgets
    Concurrent
    OpenGL
    Multimedia
    REQUIRED
)
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
    main.cpp
    src/reader/Note.cpp
    src/reader/Note_preference.cpp
    src/ui/ResultWindow.cpp
    src/ui/MainWindow.cpp
)

set(TECHCLOUD_MOCS
    include/ui/MainWindow.h
    include/ui/ResultWindow.h
)

set(TECHCLOUD_UIS
    src/ui/ResultWindow.ui
    src/ui/MainWindow.ui
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
    nlohmann_json::nlohmann_json
)

find_package(nlohmann_json CONFIG REQUIRED)

###############################################################################
# The executable of our project
###############################################################################

add_executable(${PROJECT_NAME}
    ${TECHCLOUD_SOURCES}
    ${TECHCLOUD_MOCS}
    ${TECHCLOUD_UI_HDRS}
)

qt5_use_modules(tech_cloud Multimedia)

###############################################################################
# External library dependencys
###############################################################################

target_link_libraries(tech_cloud ${TECHCLOUD_DEPENDS})
