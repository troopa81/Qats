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

#ifndef _QABSTRACTBUTTONPROTOTYPE_
#define _QABSTRACTBUTTONPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QAbstractButton>

#include "QWidgetPrototype.h"

namespace qats
{

class QAbstractButtonPrototype : public QWidgetPrototype
{
Q_OBJECT

public:

static void registerToScriptEngine(QScriptEngine* engine)
{
engine->setDefaultPrototype(qMetaTypeId<QAbstractButton*>(), engine->newQObject(new QAbstractButtonPrototype(engine)));

}

QAbstractButtonPrototype(QObject* parent = 0):QWidgetPrototype(parent){}
public slots:

void setText(const QString & text)
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->setText(text);
}
QString text()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
return object->text();
}
void setIcon(const QIcon & icon)
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->setIcon(icon);
}
QIcon icon()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
return object->icon();
}
QSize iconSize()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
return object->iconSize();
}
void setShortcut(const QKeySequence & key)
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->setShortcut(key);
}
QKeySequence shortcut()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
return object->shortcut();
}
void setCheckable(bool param0)
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->setCheckable(param0);
}
bool isCheckable()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
return object->isCheckable();
}
bool isChecked()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
return object->isChecked();
}
void setDown(bool param0)
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->setDown(param0);
}
bool isDown()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
return object->isDown();
}
void setAutoRepeat(bool param0)
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->setAutoRepeat(param0);
}
bool autoRepeat()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
return object->autoRepeat();
}
void setAutoRepeatDelay(int param0)
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->setAutoRepeatDelay(param0);
}
int autoRepeatDelay()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
return object->autoRepeatDelay();
}
void setAutoRepeatInterval(int param0)
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->setAutoRepeatInterval(param0);
}
int autoRepeatInterval()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
return object->autoRepeatInterval();
}
void setAutoExclusive(bool param0)
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->setAutoExclusive(param0);
}
bool autoExclusive()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
return object->autoExclusive();
}
QButtonGroup * group()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
return object->group();
}
void setIconSize(const QSize & size)
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->setIconSize(size);
}
void animateClick(int msec = 100)
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->animateClick(msec);
}
void click()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->click();
}
void toggle()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->toggle();
}
void setChecked(bool param0)
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->setChecked(param0);
}
void pressed()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->pressed();
}
void released()
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->released();
}
void clicked(bool checked = false)
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->clicked(checked);
}
void toggled(bool checked)
{
QAbstractButton *object = qscriptvalue_cast<QAbstractButton*>(thisObject());
object->toggled(checked);
}
};
}

Q_DECLARE_METATYPE(QAbstractButton*)

#endif
