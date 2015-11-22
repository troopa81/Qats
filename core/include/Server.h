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

#ifndef QATS_SERVER_H
#define QATS_SERVER_H

#include <QLocalServer>
#include <QProcess>

#include "Qats.h"
#include "Test.h"

namespace qats
{

class TestCase;
class TestFunction;
class Message;
class QATS_EXPORT Server : public QLocalServer
{
	Q_OBJECT

  public:
	
	static Server* get();
	void send( const QByteArray& message );
	TestCase* getCurrentTestCase() const;
	Message* getFailedMessage() const;
	void clear();
	void executeTest( const QString& test );
	bool startTestedApplication( const QString& command, const QStringList& arguments );
	bool isStartedTestedApplication();
	void closeTestedApplication();
	int getTestedApplicationPid() const;

  signals:
	
	void outputReceived();	
	void testCaseStarted( TestCase* testCase );
	void testCaseEnded( TestCase* testCase );
	void testFunctionStarted( TestFunction* testFunction );
	void testFunctionPassed( TestFunction* testFunction );
	void failMessageAdded( Message* message, TestFunction* testFunction );
	void warnMessageAdded( Message* message, TestFunction* testFunction );
	void testedApplicationFinished();

  protected slots:
	
	void onNewConnection();
	void onMessageReceived();
	void onProcessFinished( int exitCode, QProcess::ExitStatus exitStatus );

  private:
	
	Server( QObject* parent = 0 );
	~Server();

  protected:

	void onFail( const QString& message, const QString& backtrace );
	
	QLocalSocket* _localSocket;
	static Server* s_instance;
	TestCase* _testCase;
	Message* _failedMessage;
	QProcess* _process;

};

}

#endif
