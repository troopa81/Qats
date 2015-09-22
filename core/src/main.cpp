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
#include <QSharedPointer>

#include "TestsTrigger.h"
#include "TextOutput.h"
#include "XunitOutput.h"

#define tr(x) QCoreApplication::translate("main", x)

#define ERROR(x)											\
	std::cout << "Error:" << qPrintable( x ) << std::endl	\
	<< qPrintable( parser.helpText() ) << std::endl;		\
	return 1;

int main( int argc, char* argv[] )
{
	QString text;
	qats::TextOutput* textOutput = 0;
	qats::XunitOutput* xunitOutput = 0;
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

    // output type option
    QCommandLineOption outputTypeOption("output-type", tr( "Output type : TEXT, XUNIT (TEXT by default)"), 
										tr( "type" ), "TEXT" );
    parser.addOption(outputTypeOption);

    // output file option
    QCommandLineOption outputFileOption("output-file", tr( "Output file (standard output by default)"), 
										tr( "type" ), "" );
    parser.addOption(outputFileOption);

	// parse args
	parser.process(app);

    QStringList args = parser.positionalArguments();
	if ( args.count() < 2 )
	{
 		ERROR( tr( "Bad number of arguments" ) );
	}

	// output file (use a shared pointer to properly delete file in case we exit the application with return)
	QSharedPointer<QFile> outputFile;
	QString strOutputFile = parser.value( outputFileOption ); 
	if ( !strOutputFile.isEmpty() )
	{
		outputFile = QSharedPointer<QFile> ( new QFile( strOutputFile ) );
		if ( !outputFile->open( QIODevice::WriteOnly ) )
		{
			ERROR( tr( "Cannot open output file '%1'" ).arg( strOutputFile ) );
		}
	}

	// output type
	QString outputType = parser.value( outputTypeOption ); 
	if ( outputType == "TEXT" )
	{
		textOutput = outputFile ? new qats::TextOutput( outputFile.data(), &app ) 
			: new qats::TextOutput( &app ); 
	}
	else if ( outputType == "XUNIT" )
	{
		if ( !outputFile )
		{
			ERROR( tr( "You have to define an output file with XUNIT output type" ) );
		}

		xunitOutput = new qats::XunitOutput( outputFile.data(), &app );
	}
	else
	{
		ERROR( tr( "Wrong output type '%1'" ).arg( outputType ) );
	}

	qats::TestsTrigger testsTrigger( args ); 

	int res = app.exec(); 

	delete textOutput; 
	delete xunitOutput;

	return res;
}
