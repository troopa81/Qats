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
#include "XunitOutput.h"

#define DATEFORMAT "yyyy-MM-ddTHH:mm:ss"

namespace qats
{

/*!
  Constructor
  Construct an xUnit output with an output \param file
  \param parent parent object
*/
XunitOutput::XunitOutput( QFile* file, QObject* parent )
	: Output( parent ),
	  _file( file ),
	  _testSuitesNbTests( 0 ),
	  _testSuitesNbErrors( 0 ),
	  _testSuitesNbFailures( 0 ),
	  _testSuiteNbTests( 0 ),
	  _testSuiteNbErrors( 0 ),
	  _testSuiteNbFailures( 0 )
{
	_testSuitesDom = _dom.createElement("testsuites");
	_testSuitesDom.setAttribute("name", QFileInfo( file->fileName() ).baseName() );
	_dom.appendChild( _testSuitesDom );

	_testSuitesStart = QDateTime::currentDateTime();
}

/*!
  Destructor
*/
XunitOutput::~XunitOutput()
{
	_testSuitesDom.setAttribute( "tests", QString::number( _testSuitesNbTests ) );
	_testSuitesDom.setAttribute( "errors", QString::number( _testSuitesNbErrors ) );
	_testSuitesDom.setAttribute( "failures", QString::number( _testSuitesNbFailures ) );
	_testSuitesDom.setAttribute( "time", QString::number( _testSuitesStart.secsTo( QDateTime::currentDateTime() ) ) );
	
	_file->write( qPrintable( _dom.toString() ) );
}

/*! 
  \overloaded
*/
void XunitOutput::onTestCaseStarted( TestCase* testCase ) 
{
	// reset to 0
	_testSuiteNbTests = 0;
	_testSuiteNbErrors = 0;
	_testSuiteNbFailures = 0;
	_testSuiteStart = QDateTime::currentDateTime();
	
	_testSuiteDom = _dom.createElement( "testsuite" );
	_testSuiteDom.setAttribute( "name", testCase->objectName() );
	_testSuiteDom.setAttribute( "timestamp", _testSuiteStart.toString( DATEFORMAT ) );
    _testSuitesDom.appendChild( _testSuiteDom );
}

/*! 
  \overloaded
*/
void XunitOutput::onTestCaseEnded( TestCase* testCase ) 
{
	_testSuitesNbTests += _testSuiteNbTests;
	_testSuitesNbErrors += _testSuiteNbErrors;
	_testSuitesNbFailures += _testSuiteNbFailures;
	
	_testSuiteDom.setAttribute( "tests", QString::number( _testSuiteNbTests ) );
	_testSuiteDom.setAttribute( "errors", QString::number( _testSuiteNbErrors ) );
	_testSuiteDom.setAttribute( "failures", QString::number( _testSuiteNbFailures ) );
	_testSuiteDom.setAttribute( "time", QString::number( _testSuiteStart.secsTo( QDateTime::currentDateTime() ) ) );
}

/*! 
  \overloaded
*/
void XunitOutput::onTestFunctionStarted( TestFunction* testFunction ) 
{
	_testCaseStart = QDateTime::currentDateTime();
	_testSuiteNbTests++;

	_testCaseDom = _dom.createElement( "testcase" );
	_testCaseDom.setAttribute( "name", testFunction->objectName() );
    _testSuiteDom.appendChild( _testCaseDom );
}

/*! 
  \overloaded
*/
void XunitOutput::onTestFunctionPassed( TestFunction* testFunction ) 
{
	_testCaseDom.setAttribute( "time", QString::number( _testCaseStart.secsTo( QDateTime::currentDateTime() ) ) );
}

/*! 
  \overloaded
*/
void XunitOutput::onWarnMessageAdded( Message* message, TestFunction* testFunction ) 
{
	QDomElement elt = _dom.createElement( "system-out" ); 
	elt.appendChild( _dom.createTextNode( message->getMessage() + "\n" + backtraceToString( message ) ) );
	( testFunction ? _testCaseDom : _testSuiteDom ).appendChild( elt );
}

/*! 
  \overloaded
*/
void XunitOutput::onFailMessageAdded( Message* message, TestFunction* testFunction ) 
{
	if ( testFunction )
	{
		_testCaseDom.setAttribute( "time", QString::number( _testCaseStart.secsTo( QDateTime::currentDateTime() ) ) );
	}

	QDomElement elt = _dom.createElement( "failure" ); 
	elt.setAttribute( "message", message->getMessage() + "\n" + backtraceToString( message ) );
	( testFunction ? _testCaseDom : _testSuiteDom ).appendChild( elt );

	_testSuiteNbFailures++;
}

};
