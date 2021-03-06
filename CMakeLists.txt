cmake_minimum_required(VERSION 2.8)
project(ORB_SIFT)

# Check C++11 or C++0x support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    add_definitions(-DCOMPILEDWITHC11)
    message(STATUS "Using flag -std=c++11.")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    add_definitions(-DCOMPILEDWITHC0X)
    message(STATUS "Using flag -std=c++0x.")
else()
    message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

#set(OpenCV_DIR "/home/bene-robot/opencv-3.4.7/build/")
message(${OpenCV_DIR})
find_package(OpenCV 3 REQUIRED)
find_package(PCL 1.2 REQUIRED)


include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/Thirdparty/DBoW2/DUtils)
#include_directories(./include) //这个和上面的是等效的，下面的没用
#include_directories(${PROJECT_SOURCE_DIR})

#include_directories(${OpenCV_INCLUDE_DIRS})

SET(SRC
        src/ORBextractor.cc
        src/ORBTest.cpp
        src/main.cpp
        #src/SIFTTest.cpp
        src/Frame.cc
        src/ORBmatcher.cc
        src/HomoDecomp.cpp
        src/Initializer.cc
        src/LidarProcess.cpp)

SET(LIBS
        ${OpenCV_LIBS}
        ${PCL_LIBRARIES}
        ${PROJECT_SOURCE_DIR}/Thirdparty/DBoW2/lib/libDBoW2.so)

add_executable(ORB_SIFT ${SRC})
target_link_libraries(ORB_SIFT ${LIBS})
