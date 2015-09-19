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

#ifndef _QTIMERPROTOTYPE_
#define _QTIMERPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QTimer>

namespace qats
{

class QTimerPrototype : public QObject, public QScriptable
{
Q_OBJECT

public:

QTimerPrototype(QObject* parent = 0):QObject(parent){}
public slots:

inline bool isActive()
{
QTimer *object = qscriptvalue_cast<QTimer*>(thisObject());
return object->isActive();
}
int timerId()
{
QTimer *object = qscriptvalue_cast<QTimer*>(thisObject());
return object->timerId();
}
void setInterval(int msec)
{
QTimer *object = qscriptvalue_cast<QTimer*>(thisObject());
object->setInterval(msec);
}
int interval()
{
QTimer *object = qscriptvalue_cast<QTimer*>(thisObject());
return object->interval();
}
int remainingTime()
{
QTimer *object = qscriptvalue_cast<QTimer*>(thisObject());
return object->remainingTime();
}
void setTimerType(Qt::TimerType atype)
{
QTimer *object = qscriptvalue_cast<QTimer*>(thisObject());
object->setTimerType(atype);
}
Qt::TimerType timerType()
{
QTimer *object = qscriptvalue_cast<QTimer*>(thisObject());
return object->timerType();
}
inline void setSingleShot(bool singleShot)
{
QTimer *object = qscriptvalue_cast<QTimer*>(thisObject());
return object->setSingleShot(singleShot);
}
inline bool isSingleShot()
{
QTimer *object = qscriptvalue_cast<QTimer*>(thisObject());
return object->isSingleShot();
}
void singleShot(int msec,const QObject * receiver,const char * member)
{
QTimer::singleShot(msec,receiver,member);
}
void singleShot(int msec,Qt::TimerType timerType,const QObject * receiver,const char * member)
{
QTimer::singleShot(msec,timerType,receiver,member);
}
void start(int msec)
{
QTimer *object = qscriptvalue_cast<QTimer*>(thisObject());
object->start(msec);
}
void start()
{
QTimer *object = qscriptvalue_cast<QTimer*>(thisObject());
object->start();
}
void stop()
{
QTimer *object = qscriptvalue_cast<QTimer*>(thisObject());
object->stop();
}
};
}

Q_DECLARE_METATYPE(QTimer*)

#endif
