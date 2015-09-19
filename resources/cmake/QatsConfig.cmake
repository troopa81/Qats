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

find_path(QATS_INCLUDE_DIR NAMES Qats.h)

find_library(QATS_LIBRARY NAMES qatsClient )

set(QATS_LIBRARIES ${QATS_LIBRARY} )
set(QATS_INCLUDE_DIRS ${QATS_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Qats DEFAULT_MSG QATS_LIBRARY QATS_INCLUDE_DIR)

mark_as_advanced(QATS_INCLUDE_DIR QATS_LIBRARY )
