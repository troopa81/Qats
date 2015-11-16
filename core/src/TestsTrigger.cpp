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

#include <QProcess>
#include <QCoreApplication>
#include <QEventLoop>

#include "Server.h"
#include "TestsTrigger.h"
#include "TestCase.h"

namespace qats
{

/*! 
  Constructor
  \param args arguments from command line
  \parent parent object
*/
TestsTrigger::TestsTrigger( const QStringList& args, QObject* parent )
	: QObject( parent ),
	  _scripts( args )
{
	connect( Server::get(), &Server::newConnection, this, &TestsTrigger::triggerTests );

	Server::get()->startTestedApplication( _scripts.takeFirst(), QStringList() );
}

/*!
  Destructor
 */
TestsTrigger::~TestsTrigger()
{
}

/*! 
  trigger all tests
*/
void TestsTrigger::triggerTests()
{
	foreach( QString script, _scripts )
	{
		Server::get()->executeTest( script );

		// wait for testcase to be ended 
		QEventLoop loop;
		QObject::connect(Server::get(), &Server::testCaseEnded, &loop, &QEventLoop::quit);
		loop.exec();
	}

	Server::get()->closeTestedApplication();

	// finish, exit the application
	QCoreApplication::exit();
}

}; 
