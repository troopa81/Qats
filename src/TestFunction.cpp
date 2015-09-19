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

#include "TestFunction.h"
#include "Message.h"

namespace qats
{

/*!
  \class TestFunction
  \brief test function interface 
*/

/*!
  Constructor
*/
TestFunction::TestFunction( const QString& testFunctionName )
	: QObject( 0 ),
	  _state( RUNNING ),
	  _failedMessage( 0 )
{
	setObjectName( testFunctionName );
}

/*!
  Destructor
*/
TestFunction::~TestFunction()
{
}

/*!
  set the test function to fail state with associated \param message
 */
void TestFunction::fail( Message* message )
{
	_failedMessage = message;
	_failedMessage->setParent( message );
	_state = FAILED;
}

/*! 
  add warn message \param warnMessage to test function
*/
void TestFunction::addWarnMessage( Message* warnMessage )
{
	warnMessage->setParent( this );
	_warnMessages.append( warnMessage );
}

/*!
  change the test function state to passed
 */
void TestFunction::pass()
{
	_state = PASSED;
}

/*! 
  \return test function state
*/
TestFunction::State TestFunction::getState() const
{
	return _state;
}

/*! 
  \return warn messages
*/
const QList<Message*> TestFunction::getWarnMessages() const
{
	return _warnMessages;
}

/*! 
  \return failed message
*/
const Message* TestFunction::getFailedMessage() const
{
	return _failedMessage; 
}

}

