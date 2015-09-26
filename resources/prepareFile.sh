#!/bin/bash

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

grep -v ^#include $1 > /tmp/withoutIncludesFile.h
g++ -E /tmp/withoutIncludesFile.h "-DQT_DEPRECATED_SINCE(x,y)=0" "-DQ_DECLARE_OPERATORS_FOR_FLAGS(x)=" "-DQT_BEGIN_NAMESPACE=" "-DQ_DECLARE_FLAGS( Flags, Enum)=enum Flags{toto,tata};" > /tmp/tmpPreprocessorFile.h
