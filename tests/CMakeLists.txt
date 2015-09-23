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

project(qatsTests)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")

find_package(Qats REQUIRED)
find_package(Qt5Widgets)
find_package(Qt5Test)
find_package(Qt5Script)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB CPP_LIST "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB UI_LIST  "${CMAKE_CURRENT_SOURCE_DIR}/src/*.ui")
file(GLOB INC_LIST "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

include_directories(${QATS_INCLUDE_DIRS})
link_libraries(${QATS_LIBRARIES})

# app
add_executable(qatsTests ${CPP_LIST} ${INC_LIST})
target_include_directories(qatsTests PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
qt5_use_modules(qatsTests Widgets Test Script Network)

install(TARGETS qatsTests RUNTIME DESTINATION bin)
