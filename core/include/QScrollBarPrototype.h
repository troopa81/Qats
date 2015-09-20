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

#ifndef _QSCROLLBARPROTOTYPE_
#define _QSCROLLBARPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QScrollBar>

namespace qats
{

class QScrollBarPrototype : public QObject, public QScriptable
{
Q_OBJECT

public:

QScrollBarPrototype(QObject* parent = 0):QObject(parent){}
public slots:

QSize sizeHint()
{
QScrollBar *object = qscriptvalue_cast<QScrollBar*>(thisObject());
return object->sizeHint();
}
bool event(QEvent * event)
{
QScrollBar *object = qscriptvalue_cast<QScrollBar*>(thisObject());
return object->event(event);
}
};
}

Q_DECLARE_METATYPE(QScrollBar*)

#endif
