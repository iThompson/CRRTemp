cmake_minimum_required(VERSION 2.8)
include(FRCDeploy)

project(CodeRedRobot2014)
find_package(WPILib)
include_directories(${WPILib_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCE_CODE *.cpp)

add_executable(CodeRedRobot2014 ${SOURCE_CODE})
target_link_libraries(CodeRedRobot2014 ${WPILib_LIBRARY})

add_make_deploy(CodeRedRobot2014 10.6.39.2) # where your team number is xxyy