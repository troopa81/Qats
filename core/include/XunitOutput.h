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

#ifndef QATS_XUNITOUTPUT_H
#define QATS_XUNITOUTPUT_H

#include <QDomDocument>
#include <QDateTime>

#include "Output.h"
#include "Qats.h"

namespace qats
{

class TestCase;
class TestFunction;
class Message;
class QATS_EXPORT XunitOutput : public Output
{
	Q_OBJECT

public:

	XunitOutput( QFile* file, QObject* parent = 0 );
	~XunitOutput();

protected :

	void onTestCaseStarted( TestCase* testCase );
	void onTestCaseEnded( TestCase* testCase );
	void onTestFunctionStarted( TestFunction* testFunction );
	void onTestFunctionPassed( TestFunction* testFunction );
	void onWarnMessageAdded( Message* message, TestFunction* testFunction );
	void onFailMessageAdded( Message* message, TestFunction* testFunction );

protected: 

	QFile* _file; 

	QDomDocument _dom; 
	QDomElement _testSuitesDom; 
	QDomElement _testSuiteDom; 
	QDomElement _testCaseDom; 

	int _testSuitesNbTests; 
	int _testSuitesNbErrors; 
	int _testSuitesNbFailures; 
	int _testSuiteNbTests; 
	int _testSuiteNbErrors; 
	int _testSuiteNbFailures; 
	QDateTime _testSuitesStart; 
	QDateTime _testSuiteStart; 
	QDateTime _testCaseStart; 
}; 

}

#endif
