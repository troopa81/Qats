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

#ifndef _QSLIDERPROTOTYPE_
#define _QSLIDERPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QSlider>

#include "QAbstractSliderPrototype.h"

inline QScriptValue scriptQSliderConstructor(QScriptContext *context, QScriptEngine *engine)
{
Q_UNUSED(context);
QSlider *object = new QSlider(0);
return engine->newQObject(object, QScriptEngine::ScriptOwnership);
}

namespace qats
{

class QSliderPrototype : public QAbstractSliderPrototype
{
Q_OBJECT

public:

static void registerToScriptEngine(QScriptEngine* engine)
{
engine->setDefaultPrototype(qMetaTypeId<QSlider*>(), engine->newQObject(new QSliderPrototype(engine)));

QScriptValue ctor = engine->newFunction(scriptQSliderConstructor);
QScriptValue metaObject = engine->newQMetaObject(&QSlider::staticMetaObject, ctor);
engine->globalObject().setProperty("QSlider", metaObject);
}

QSliderPrototype(QObject* parent = 0):QAbstractSliderPrototype(parent){}
public slots:

QSize sizeHint()
{
QSlider *object = qscriptvalue_cast<QSlider*>(thisObject());
return object->sizeHint();
}
QSize minimumSizeHint()
{
QSlider *object = qscriptvalue_cast<QSlider*>(thisObject());
return object->minimumSizeHint();
}
void setTickPosition(QSlider::TickPosition position)
{
QSlider *object = qscriptvalue_cast<QSlider*>(thisObject());
object->setTickPosition(position);
}
QSlider::TickPosition tickPosition()
{
QSlider *object = qscriptvalue_cast<QSlider*>(thisObject());
return object->tickPosition();
}
void setTickInterval(int ti)
{
QSlider *object = qscriptvalue_cast<QSlider*>(thisObject());
object->setTickInterval(ti);
}
int tickInterval()
{
QSlider *object = qscriptvalue_cast<QSlider*>(thisObject());
return object->tickInterval();
}
bool event(QEvent * event)
{
QSlider *object = qscriptvalue_cast<QSlider*>(thisObject());
return object->event(event);
}
};
}

Q_DECLARE_METATYPE(QSlider*)

#endif
