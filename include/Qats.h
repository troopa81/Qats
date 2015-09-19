/****************************************************************************
**
** Copyright (C) 2015 Cabieces Julien
** Contact: https://github.com/troopa81/Qats
**
** This file is part of Qats.
**
** Qats is free software: you can redistribute it and/or modify
** it under the terms of the GNU Lesser General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** Qats is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public License
** along with Qats. If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#ifndef QATS_H
#define QATS_H

// Static or dynamic link configuration
#ifdef WIN32
#	ifdef QATS_MAKELIB	// Create a static library.
#		define QATS_EXPORT
#		define QATS_TEMPLATE_EXPORT
#	elif defined QATS_USELIB	// Use a static library.
#		define QATS_EXPORT
#		define QATS_TEMPLATE_EXPORT
#	elif defined QATS_MAKEDLL	// Create a dynamic library.
#		define QATS_EXPORT	__declspec(dllexport)
#		define QATS_TEMPLATE_EXPORT
#	else	// Use DLL library
#		define QATS_EXPORT	__declspec(dllimport)
#		define QATS_TEMPLATE_EXPORT	extern
#	endif
#else
#	 if defined(QATS_MAKEDLL) || defined(QATS_MAKELIB)
#		define QATS_EXPORT
#		define QATS_TEMPLATE_EXPORT
#	else
#		define QATS_EXPORT
#		define QATS_TEMPLATE_EXPORT	extern
#	endif
#endif

namespace qats
{

void initialize();

}

#endif 
