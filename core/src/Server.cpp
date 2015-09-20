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

#include <QLocalSocket>
#include <QCoreApplication>

#include "Server.h"
#include "TestFunction.h"
#include "TestCase.h"
#include "Message.h"

namespace qats
{

Server* Server::s_instance = 0;

/*!
  Constructor
*/
Server::Server( QObject* parent )
	: QLocalServer( parent ),
	  _localSocket( 0 ),
	  _testCase( 0 ),
	  _failedMessage( 0 )
{
	connect( this, SIGNAL( newConnection() ), this, SLOT( onNewConnection() ) );

	// in case of previous pipe has not been closed
	QLocalServer::removeServer( "qats" );

	if (!listen("qats")) 
	{
		qWarning() << "Unable to start server Qats"; 
        return;
    }
}

/*!
  Destructor
*/
Server::~Server()
{
	_localSocket = nextPendingConnection();
}

/*!
  \return unique instance
*/
Server* Server::get()
{
	if ( !s_instance )
	{
		s_instance = new Server();
	}

	return s_instance;
}

/*! 
  called whenever a new connection is incomming on server
*/
void Server::onNewConnection()
{
	_localSocket = nextPendingConnection();
	connect( _localSocket, &QIODevice::readyRead, this, &Server::onMessageReceived );
	qDebug() << "new Connections";
}

/*!
  send \param message to the client
*/
void Server::send( const QByteArray& message )
{
	if ( !_localSocket )
	{
		qDebug() << "No local socket : Cannot send message";
		return;
	}

	_localSocket->write(message);
    _localSocket->flush();
}

/*!
  called whenever a message from the client is received
*/
void Server::onMessageReceived()
{
	QDataStream in(_localSocket);
    in.setVersion(QDataStream::Qt_4_0);
	
	// read all
	while ( !in.atEnd() )
	{
		QString testFunctionName, message, backtrace, actual, expected, testCaseName;
		TestFunction* testFunction = 0;
		Message* messageObject = 0;
		int type;

		// parse message and build internal data model
		in >> type; 
		switch ( type )
		{
		case Test::WARN:
			in >> message >> backtrace; 
			testFunction = _testCase ? _testCase->getCurrentTestFunction() : 0;
			Q_ASSERT( testFunction ); 

			messageObject = new Message( message, backtrace );
			testFunction->addWarnMessage( messageObject ); 
			emit messageAdded( messageObject, testFunction );
			break; 

		case Test::FAIL:
			in >> message >> backtrace; 
			testFunction = _testCase ? _testCase->getCurrentTestFunction() : 0;
			
			messageObject = new Message( message, backtrace );
			if ( testFunction )
			{
				testFunction->fail( messageObject );
			}
			// in case of Syntax error
			else
			{
				delete _failedMessage;
				_failedMessage = messageObject;
			}
			emit messageAdded( messageObject, testFunction );
			break; 

		case Test::FUNCTION_START:
			in >> testFunctionName;
			Q_ASSERT( _testCase );
			testFunction = new TestFunction( testFunctionName );
			_testCase->addTestFunction( testFunction );
			emit testFunctionStarted( testFunction );
			break;

		case Test::FUNCTION_PASS:
			testFunction = _testCase ? _testCase->getCurrentTestFunction() : 0;
			Q_ASSERT( testFunction ); 

			testFunction->pass();
			emit testFunctionPassed( testFunction );
			break;

		case Test::TESTCASE_START:
			delete _testCase;
			in >> testCaseName; 
			_testCase = new TestCase( testCaseName, this );
			emit testCaseStarted( _testCase );
			break;

		case Test::TESTCASE_END:
			emit testCaseEnded( _testCase );
			break; 
		}
	}

	// TODO to be removed (still used in MainWindow for output display) 
	emit outputReceived();
}

/*! 
  \return currently running test case
*/
TestCase* Server::getCurrentTestCase() const
{
	return _testCase;
}


/*! 
  \return current failed message
*/
Message* Server::getFailedMessage() const
{
	return _failedMessage;
}

/*! 
  clear current test case and failed message
*/
void Server::clear()
{
	delete _testCase; 
	_testCase = 0;

	delete _failedMessage; 
	_failedMessage = 0;
}

/*! 
  execute \param test
*/
void Server::executeTest( const QString& test )
{
	QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
	out << QCoreApplication::applicationDirPath() + "/../resources/qats.js";
    out << test;

	Server::get()->send( block );
}

};
