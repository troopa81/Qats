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

#include "TestCase.h"
#include "TestFunction.h"

namespace qats
{

/*!
  \class TestCase
  \brief use case test interface 
*/

/*!
  Constructor
  \param testCaseName test case name
  \param parent test case object parent
*/
TestCase::TestCase( const QString& testCaseName, QObject* parent )
	: QObject( parent )
{
	setObjectName( testCaseName );
}

/*!
  Destructor
*/
TestCase::~TestCase()
{
}

/*! 
  add test function \param testFunction to use case. Take ownership
*/ 
void TestCase::addTestFunction( TestFunction* testFunction )
{
	testFunction->setParent( this );
	_testFunctions.append( testFunction );
}

/*! 
  get and \return the currently executed test function
*/
TestFunction* TestCase::getCurrentTestFunction() const
{
	return _testFunctions.count() ? _testFunctions.last() : 0;
}

/*! 
  \return test functions
*/
const QList<TestFunction*>& TestCase::getTestFunctions() const
{
	return _testFunctions;
}

}

