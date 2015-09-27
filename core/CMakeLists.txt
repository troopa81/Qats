############################################################################
##
## Copyright (C) 2015 Cabieces Julien
## Contact: https://github.com/troopa81/Qats
##
## This file is part of Qats.
##
## Qats is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## Qats is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with Qats. If not, see <http://www.gnu.org/licenses/>.
##
############################################################################

cmake_minimum_required (VERSION 3.2.2)

project(qatsCore)

find_package(Qt5Widgets)
find_package(Qt5Test)
find_package(Qt5Script)
find_package(Qt5Xml)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB CPP_LIST "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB INC_LIST "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

# lib
add_library(qatsClient SHARED ${CPP_LIST} ${INC_LIST})
target_include_directories(qatsClient PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
qt5_use_modules(qatsClient Widgets Test Script Network Xml)

# app
add_executable(qats ${CPP_LIST} ${INC_LIST})
target_include_directories(qats PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
qt5_use_modules(qats Widgets Test Script Network Xml)

install(TARGETS qats qatsClient
  RUNTIME DESTINATION bin 
  LIBRARY DESTINATION lib)

install(FILES ${INC_LIST} DESTINATION include)
