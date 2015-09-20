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

#include "TestFunction.h"
#include "TestCase.h"
#include "Message.h"
#include "Server.h"
#include "TextOutput.h"

namespace qats
{

/*!
  Constructor
*/
TextOutput::TextOutput( QObject* parent )
	: QObject( parent )
{
	connect( Server::get(), &Server::testCaseStarted, this, &TextOutput::onTestCaseStarted );
	connect( Server::get(), &Server::testCaseEnded, this, &TextOutput::onTestCaseEnded );
	connect( Server::get(), &Server::testFunctionStarted, this, &TextOutput::onTestFunctionStarted );
	connect( Server::get(), &Server::testFunctionPassed, this, &TextOutput::onTestFunctionPassed );
	connect( Server::get(), &Server::messageAdded, this, &TextOutput::onMessageAdded );
}

/*!
  Destructor
*/
TextOutput::~TextOutput()
{
}

/*! 
  called whenever the test case is started
*/
void TextOutput::onTestCaseStarted( TestCase* testCase ) const
{
	std::cout << "################### " << qPrintable( testCase->objectName() ) << " STARTED #################" << std::endl;
}

/*! 
  called whenever the test case is ended
*/
void TextOutput::onTestCaseEnded( TestCase* testCase ) const
{
	std::cout << "################### " << qPrintable( testCase->objectName() ) << " ENDED ###################" << std::endl;
}

/*! 
  called whenever the test function is started
*/
void TextOutput::onTestFunctionStarted( TestFunction* testFunction ) const
{
	std::cout << "******************* " << qPrintable( testFunction->objectName() ) << " STARTED" << std::endl;
}

/*! 
  called whenever the test function is passed
*/
void TextOutput::onTestFunctionPassed( TestFunction* testFunction ) const
{
	std::cout << "PASS : OK" << std::endl;
}

/*! 
  called whenever the test case is started
*/
void TextOutput::onMessageAdded( Message* message, TestFunction* testFunction ) const
{
	std::cout << qPrintable( message->getMessage() ) << std::endl;
}

};
