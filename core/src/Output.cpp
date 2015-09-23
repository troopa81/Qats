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
#include "Output.h"

namespace qats
{

/*!
  Constructor
  Construct an output on standard output
  \param parent parent object
*/
Output::Output( QObject* parent )
	: QObject( parent )
{
	connect( Server::get(), &Server::testCaseStarted, this, &Output::onTestCaseStarted );
	connect( Server::get(), &Server::testCaseEnded, this, &Output::onTestCaseEnded );
	connect( Server::get(), &Server::testFunctionStarted, this, &Output::onTestFunctionStarted );
	connect( Server::get(), &Server::testFunctionPassed, this, &Output::onTestFunctionPassed );
	connect( Server::get(), &Server::warnMessageAdded, this, &Output::onWarnMessageAdded );
	connect( Server::get(), &Server::failMessageAdded, this, &Output::onFailMessageAdded );
}

/*!
  Destructor
*/
Output::~Output()
{
}

/*! 
  called whenever the test case is started
*/
void Output::onTestCaseStarted( TestCase* testCase ) 
{
	Q_UNUSED( testCase );
}

/*! 
  called whenever the test case is ended
*/
void Output::onTestCaseEnded( TestCase* testCase ) 
{
	Q_UNUSED( testCase );
}

/*! 
  called whenever the test function is started
*/
void Output::onTestFunctionStarted( TestFunction* testFunction ) 
{
	Q_UNUSED( testFunction );
}

/*! 
  called whenever the test function is passed
*/
void Output::onTestFunctionPassed( TestFunction* testFunction ) 
{
	Q_UNUSED( testFunction );
}

/*! 
  called whenever a warn message has been added
*/
void Output::onWarnMessageAdded( Message* message, TestFunction* testFunction ) 
{
	Q_UNUSED( message );
	Q_UNUSED( testFunction );
}

/*! 
  called whenever the test case is started
*/
void Output::onFailMessageAdded( Message* message, TestFunction* testFunction ) 
{
	Q_UNUSED( message );
	Q_UNUSED( testFunction );
}

/*! 
  format and print on stdout \param strBacktrace
*/  
QString Output::backtraceToString( const Message* message ) 
{
	QList<Test::BacktraceElt> backtrace = Test::parseBacktrace( message->getBacktrace() );

	QString result = "  Backtrace :\n";

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

		result += "    - " + strLocation + " : ";
		result += Test::getLineFromFile( fileInfo.absoluteFilePath(), backtraceElt._lineNumber ) + "\n";
	}

	return result;
}

};
