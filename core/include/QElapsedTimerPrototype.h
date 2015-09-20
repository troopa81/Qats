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

#ifndef _QELAPSEDTIMERPROTOTYPE_
#define _QELAPSEDTIMERPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QElapsedTimer>

namespace qats
{

class QElapsedTimerPrototype : public QObject, public QScriptable
{
Q_OBJECT

public:

QElapsedTimerPrototype(QObject* parent = 0):QObject(parent){}
public slots:

QElapsedTimer::ClockType clockType()
{
return QElapsedTimer::clockType();
}
bool isMonotonic()
{
return QElapsedTimer::isMonotonic();
}
void start()
{
QElapsedTimer *object = qscriptvalue_cast<QElapsedTimer*>(thisObject());
object->start();
}
qint64 restart()
{
QElapsedTimer *object = qscriptvalue_cast<QElapsedTimer*>(thisObject());
return object->restart();
}
void invalidate()
{
QElapsedTimer *object = qscriptvalue_cast<QElapsedTimer*>(thisObject());
object->invalidate();
}
bool isValid()
{
QElapsedTimer *object = qscriptvalue_cast<QElapsedTimer*>(thisObject());
return object->isValid();
}
qint64 nsecsElapsed()
{
QElapsedTimer *object = qscriptvalue_cast<QElapsedTimer*>(thisObject());
return object->nsecsElapsed();
}
qint64 elapsed()
{
QElapsedTimer *object = qscriptvalue_cast<QElapsedTimer*>(thisObject());
return object->elapsed();
}
bool hasExpired(qint64 timeout)
{
QElapsedTimer *object = qscriptvalue_cast<QElapsedTimer*>(thisObject());
return object->hasExpired(timeout);
}
qint64 msecsSinceReference()
{
QElapsedTimer *object = qscriptvalue_cast<QElapsedTimer*>(thisObject());
return object->msecsSinceReference();
}
qint64 msecsTo(const QElapsedTimer & other)
{
QElapsedTimer *object = qscriptvalue_cast<QElapsedTimer*>(thisObject());
return object->msecsTo(other);
}
qint64 secsTo(const QElapsedTimer & other)
{
QElapsedTimer *object = qscriptvalue_cast<QElapsedTimer*>(thisObject());
return object->secsTo(other);
}
};
}

Q_DECLARE_METATYPE(QElapsedTimer*)

#endif
