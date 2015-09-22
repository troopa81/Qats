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
	: Output( parent ),
	  _out( stdout, QIODevice::WriteOnly )
{
}

/*!
  Constructor
  Construct a text output with an output \param file
  \param parent parent object
*/
TextOutput::TextOutput( QFile* file, QObject* parent )
	: Output( parent ),
	  _out( file )
{
}

/*!
  Destructor
*/
TextOutput::~TextOutput()
{
}

/*! 
  \overloaded
*/
void TextOutput::onTestCaseStarted( TestCase* testCase ) 
{
	_out << "################### " 
		 << qPrintable( QString( testCase->objectName() + " STARTED " ).leftJustified( LINE_SIZE, '#' ) )  
		 << "\n";
	_out.flush();
}

/*! 
  \overloaded
*/
void TextOutput::onTestCaseEnded( TestCase* testCase ) 
{
	_out << "################### " 
		 << qPrintable( QString( testCase->objectName() + " ENDED " ).leftJustified( LINE_SIZE, '#' ) )  
		 << "\n";
	_out.flush();
}

/*! 
  \overloaded
*/
void TextOutput::onTestFunctionStarted( TestFunction* testFunction ) 
{
	_out << "******************* " 
		 << qPrintable( QString( testFunction->objectName() + " " ).leftJustified( LINE_SIZE, '*' ) )  
		 << "\n";
	_out.flush();
}

/*! 
  \overloaded
*/
void TextOutput::onTestFunctionPassed( TestFunction* testFunction ) 
{
	_out << "PASS : OK" << "\n";
	_out.flush();
}

/*! 
  \overloaded
*/
void TextOutput::onWarnMessageAdded( Message* message, TestFunction* testFunction ) 
{
	_out << "WARN : " << qPrintable( message->getMessage() ) << "\n";
	_out << qPrintable( backtraceToString( message ) );
	_out.flush();
}

/*! 
  \overloaded
*/
void TextOutput::onFailMessageAdded( Message* message, TestFunction* testFunction ) 
{
	_out << "FAIL : " << qPrintable( message->getMessage() ) << "\n";
	_out << qPrintable( backtraceToString( message ) );
	_out.flush();
}

};
