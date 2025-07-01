cmake_minimum_required(VERSION 3.19)
project(MQTT_simu LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Core Widgets)

find_package(PkgConfig REQUIRED)
pkg_check_modules(MOSQPP QUIET IMPORTED_TARGET libmosquittopp)
if(NOT MOSQPP_FOUND)
    pkg_check_modules(MOSQPP REQUIRED IMPORTED_TARGET mosquittopp)
endif()

add_subdirectory(common)
add_subdirectory(simulator)
add_subdirectory(gui)

install(TARGETS sensor_gui sensor_simulator RUNTIME DESTINATION bin)

