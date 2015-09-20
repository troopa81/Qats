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

#include <iostream>

#include <QApplication>
#include <QDir>
#include <QCommandLineParser>

#include "TestsTrigger.h"

#define tr(x) QCoreApplication::translate("main", x)

int main( int argc, char* argv[] )
{
	QString text;
	QApplication app( argc, argv );
	QCoreApplication::setApplicationName("Qats");
    QCoreApplication::setApplicationVersion("0.1");

    QCommandLineParser parser;

    parser.setApplicationDescription( tr( "Qt Automated Test Scripting\n\
Qats is an application designed to execute javascript tests inside a Qt	\
application, in order to easily and rapidely write end to end tests." ) );

    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("application", tr("Application to be tested."));

    parser.addPositionalArgument("scripts", tr( "Javascript test \
files.\nCould be also directories. If so, all Javascript test files from the directory are executed."));

	parser.process(app);

    QStringList args = parser.positionalArguments();
	if ( args.count() < 2 )
	{
		std::cout << qPrintable( parser.helpText() );
		return 0;
	}

	qats::TestsTrigger testsTrigger( args ); 

	return app.exec();
}
