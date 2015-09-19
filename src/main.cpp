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

#include <QApplication>
#include <QDir>

#include "MainWindow.h"
#include "Server.h"

int main( int argc, char* argv[] )
{
	QApplication app( argc, argv );

	QDir::setSearchPaths("icons", QStringList( app.applicationDirPath() + "/../resources/icons" ) );

	qats::MainWindow mainWindow;

	// initalize server
	qats::Server::get();

	mainWindow.show();

	return app.exec();
}
