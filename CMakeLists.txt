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

project(qats)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")

add_subdirectory( "${CMAKE_SOURCE_DIR}/core" )
add_subdirectory( "${CMAKE_SOURCE_DIR}/gui" )


install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/resources/icons" DESTINATION resources)
install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/resources/qats.js" DESTINATION resources)
install(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/resources/cmake/" DESTINATION cmake)
