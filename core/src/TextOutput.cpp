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

#include <QLocalSocket>
#include <QCoreApplication>
#include <QFileInfo>

#include "TestFunction.h"
#include "TestCase.h"
#include "Message.h"
#include "Server.h"
#include "TextOutput.h"

#define LINE_SIZE 50

namespace qats
{

/*!
  Constructor
  Construct a text output on standard output
  \param parent parent object
*/
TextOutput::TextOutput( QObject* parent )
	: QObject( parent ),
	_out( stdout, QIODevice::WriteOnly )
{
	init();
}

/*!
  Constructor
  Construct a text output with an output \param file
  \param parent parent object
*/
TextOutput::TextOutput( QFile* file, QObject* parent )
	: QObject( parent ),
	_out( file )
{
	init();
}

/*!
  Destructor
*/
TextOutput::~TextOutput()
{
}

/*!
  initialize text output
*/
void TextOutput::init()
{
	connect( Server::get(), &Server::testCaseStarted, this, &TextOutput::onTestCaseStarted );
	connect( Server::get(), &Server::testCaseEnded, this, &TextOutput::onTestCaseEnded );
	connect( Server::get(), &Server::testFunctionStarted, this, &TextOutput::onTestFunctionStarted );
	connect( Server::get(), &Server::testFunctionPassed, this, &TextOutput::onTestFunctionPassed );
	connect( Server::get(), &Server::warnMessageAdded, this, &TextOutput::onWarnMessageAdded );
	connect( Server::get(), &Server::failMessageAdded, this, &TextOutput::onFailMessageAdded );
}

/*! 
  called whenever the test case is started
*/
void TextOutput::onTestCaseStarted( TestCase* testCase ) 
{
	_out << "################### " 
		 << qPrintable( QString( testCase->objectName() + " STARTED " ).leftJustified( LINE_SIZE, '#' ) )  
		 << "\n";
	_out.flush();
}

/*! 
  called whenever the test case is ended
*/
void TextOutput::onTestCaseEnded( TestCase* testCase ) 
{
	_out << "################### " 
		 << qPrintable( QString( testCase->objectName() + " ENDED " ).leftJustified( LINE_SIZE, '#' ) )  
		 << "\n";
	_out.flush();
}

/*! 
  called whenever the test function is started
*/
void TextOutput::onTestFunctionStarted( TestFunction* testFunction ) 
{
	_out << "******************* " 
		 << qPrintable( QString( testFunction->objectName() + " " ).leftJustified( LINE_SIZE, '*' ) )  
		 << "\n";
	_out.flush();
}

/*! 
  called whenever the test function is passed
*/
void TextOutput::onTestFunctionPassed( TestFunction* testFunction ) 
{
	_out << "PASS : OK" << "\n";
	_out.flush();
}

/*! 
  called whenever a warn message has been added
*/
void TextOutput::onWarnMessageAdded( Message* message, TestFunction* testFunction ) 
{
	_out << "WARN : " << qPrintable( message->getMessage() ) << "\n";
	_out.flush();

	printBacktrace( message );
}

/*! 
  called whenever the test case is started
*/
void TextOutput::onFailMessageAdded( Message* message, TestFunction* testFunction ) 
{
	_out << "FAIL : " << qPrintable( message->getMessage() ) << "\n";
	_out.flush();

	printBacktrace( message );
}

/*! 
  format and print on stdout \param strBacktrace
*/  
void TextOutput::printBacktrace( const Message* message ) 
{
	QList<Test::BacktraceElt> backtrace = Test::parseBacktrace( message->getBacktrace() );

	_out << "  Backtrace :\n";
	_out.flush();

	// When parsing backtrace, remove 3 first elements and last one because useless
	backtrace = backtrace.mid( 3, backtrace.count()-4 ); 

	// compute file name size 
	int fileNameSize = -1;
	foreach( Test::BacktraceElt backtraceElt, backtrace )
	{
		QFileInfo fileInfo( backtraceElt._filePath );
		if ( fileInfo.fileName().size() > fileNameSize )
		{
			fileNameSize = fileInfo.fileName().size();
		}
	}

	// print
	foreach( Test::BacktraceElt backtraceElt, backtrace )
	{
		QFileInfo fileInfo( backtraceElt._filePath );

		QString strLocation = fileInfo.fileName(); 
		strLocation = strLocation.leftJustified( fileNameSize, ' ' );
		strLocation += " (" + QString::number( backtraceElt._lineNumber ) + ")";

		_out << "    - " << qPrintable( strLocation ) << " : "
			 << qPrintable( Test::getLineFromFile( fileInfo.absoluteFilePath(), backtraceElt._lineNumber ) ) 
			 << "\n";
		_out.flush();
	}
}

};
