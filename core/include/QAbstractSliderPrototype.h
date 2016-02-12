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

#ifndef _QABSTRACTSLIDERPROTOTYPE_
#define _QABSTRACTSLIDERPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QAbstractSlider>

#include "QWidgetPrototype.h"

inline QScriptValue scriptQAbstractSliderConstructor(QScriptContext *context, QScriptEngine *engine)
{
Q_UNUSED(context);
QAbstractSlider *object = new QAbstractSlider(0);
return engine->newQObject(object, QScriptEngine::ScriptOwnership);
}

namespace qats
{

class QAbstractSliderPrototype : public QWidgetPrototype
{
Q_OBJECT

public:

static void registerToScriptEngine(QScriptEngine* engine)
{
engine->setDefaultPrototype(qMetaTypeId<QAbstractSlider*>(), engine->newQObject(new QAbstractSliderPrototype(engine)));

QScriptValue ctor = engine->newFunction(scriptQAbstractSliderConstructor);
QScriptValue metaObject = engine->newQMetaObject(&QAbstractSlider::staticMetaObject, ctor);
engine->globalObject().setProperty("QAbstractSlider", metaObject);
}

QAbstractSliderPrototype(QObject* parent = 0):QWidgetPrototype(parent){}
public slots:

Qt::Orientation orientation()
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
return object->orientation();
}
void setMinimum(int param0)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->setMinimum(param0);
}
int minimum()
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
return object->minimum();
}
void setMaximum(int param0)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->setMaximum(param0);
}
int maximum()
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
return object->maximum();
}
void setSingleStep(int param0)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->setSingleStep(param0);
}
int singleStep()
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
return object->singleStep();
}
void setPageStep(int param0)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->setPageStep(param0);
}
int pageStep()
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
return object->pageStep();
}
void setTracking(bool enable)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->setTracking(enable);
}
bool hasTracking()
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
return object->hasTracking();
}
void setSliderDown(bool param0)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->setSliderDown(param0);
}
bool isSliderDown()
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
return object->isSliderDown();
}
void setSliderPosition(int param0)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->setSliderPosition(param0);
}
int sliderPosition()
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
return object->sliderPosition();
}
void setInvertedAppearance(bool param0)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->setInvertedAppearance(param0);
}
bool invertedAppearance()
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
return object->invertedAppearance();
}
void setInvertedControls(bool param0)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->setInvertedControls(param0);
}
bool invertedControls()
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
return object->invertedControls();
}
int value()
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
return object->value();
}
void triggerAction(QAbstractSlider::SliderAction action)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->triggerAction(action);
}
void setValue(int param0)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->setValue(param0);
}
void setOrientation(Qt::Orientation param0)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->setOrientation(param0);
}
void setRange(int min,int max)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->setRange(min,max);
}
void valueChanged(int value)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->valueChanged(value);
}
void sliderPressed()
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->sliderPressed();
}
void sliderMoved(int position)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->sliderMoved(position);
}
void sliderReleased()
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->sliderReleased();
}
void rangeChanged(int min,int max)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->rangeChanged(min,max);
}
void actionTriggered(int action)
{
QAbstractSlider *object = qscriptvalue_cast<QAbstractSlider*>(thisObject());
object->actionTriggered(action);
}
};
}

Q_DECLARE_METATYPE(QAbstractSlider*)

#endif
