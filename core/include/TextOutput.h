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

#ifndef QATS_TEXTOUPUT_H
#define QATS_TEXTOUPUT_H

#include "Qats.h"

namespace qats
{

class TestCase;
class TestFunction;
class Message;
class QATS_EXPORT TextOutput : public QObject
{
	Q_OBJECT

public:

	TextOutput( QObject* parent = 0 );
	~TextOutput();

protected slots:

	void onTestCaseStarted( TestCase* testCase ) const;
	void onTestCaseEnded( TestCase* testCase ) const;
	void onTestFunctionStarted( TestFunction* testFunction ) const;
	void onTestFunctionPassed( TestFunction* testFunction ) const;
	void onWarnMessageAdded( Message* message, TestFunction* testFunction ) const;
	void onFailMessageAdded( Message* message, TestFunction* testFunction ) const;

protected:
	
	void printBacktrace( const Message* message ) const;

}; 

}

#endif
