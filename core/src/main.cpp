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
		std::cout << qPrintable( tr( "Bad number of arguments" ) )
				  << qPrintable( parser.helpText() ) << std::endl;
		return 1;
	}

	// output file (use a shared pointer to properly delete file in case we exit the application with return)
	QSharedPointer<QFile> outputFile;
	QString strOutputFile = parser.value( outputFileOption ); 
	if ( !strOutputFile.isEmpty() )
	{
		outputFile = QSharedPointer<QFile> ( new QFile( strOutputFile ) );
		if ( !outputFile->open( QIODevice::WriteOnly ) )
		{
			std::cout << qPrintable( tr( "Cannot open output file '%1'" ).arg( strOutputFile ) )
					  << qPrintable( parser.helpText() ) << std::endl;
			return 1;
		}
	}

	// output type
	QString outputType = parser.value( outputTypeOption ); 
	if ( outputType == "TEXT" )
	{
		qats::TextOutput* textOutput = outputFile ? new qats::TextOutput( outputFile.data(), &app ) 
			: new qats::TextOutput( &app ); 
	}
	else if ( outputType == "XUNIT" )
	{
		std::cout << qPrintable( tr( "XUNIT type not implemented yet" ) )
				  << qPrintable( parser.helpText() ) << std::endl;
		return 1;
	}
	else
	{
		std::cout << qPrintable( tr( "Wrong output type '%1'" ).arg( outputType ) )
				  << qPrintable( parser.helpText() ) << std::endl;
		return 1;
	}


	qats::TestsTrigger testsTrigger( args ); 

	return app.exec();
}
