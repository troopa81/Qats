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

#ifndef QATS_TESTFUNCTION_H
#define QATS_TESTFUNCTION_H

#include <QObject>

#include "Qats.h"

namespace qats
{

class Message;
class QATS_EXPORT TestFunction: public QObject
{
    Q_OBJECT

public:

	enum State
	{
		RUNNING,
		PASSED,
		FAILED
	};

    TestFunction( const QString& testFunctionName );
    virtual ~TestFunction();
	
	void addWarnMessage( Message* warnMessage );
	void fail( Message* message );
	void pass();
	State getState() const;
	const QList<Message*> getWarnMessages() const;
	const Message* getFailedMessage() const;

protected: 

	QList<Message*> _warnMessages;
	State _state;
	Message* _failedMessage;
};

}

#endif

