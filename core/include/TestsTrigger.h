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

#ifndef QATS_TESTSTRIGGER_H
#define QATS_TESTSTRIGGER_H

#include <QObject>
#include <QStringList>
#include <QProcess>

#include "Qats.h"

namespace qats
{

class QATS_EXPORT TestsTrigger : public QObject
{
	Q_OBJECT

public:

	TestsTrigger( const QStringList& args, QObject* parent = 0 );
	~TestsTrigger();

public slots:

	void triggerTests();

protected: 

	QStringList _scripts; 
}; 

}

#endif
