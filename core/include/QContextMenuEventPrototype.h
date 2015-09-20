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

#ifndef _QCONTEXTMENUEVENTPROTOTYPE_
#define _QCONTEXTMENUEVENTPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QContextMenuEvent>

namespace qats
{

class QContextMenuEventPrototype : public QObject, public QScriptable
{
Q_OBJECT

public:

QContextMenuEventPrototype(QObject* parent = 0):QObject(parent){}
public slots:

inline int x()
{
QContextMenuEvent *object = qscriptvalue_cast<QContextMenuEvent*>(thisObject());
return object->x();
}
inline int y()
{
QContextMenuEvent *object = qscriptvalue_cast<QContextMenuEvent*>(thisObject());
return object->y();
}
inline int globalX()
{
QContextMenuEvent *object = qscriptvalue_cast<QContextMenuEvent*>(thisObject());
return object->globalX();
}
inline int globalY()
{
QContextMenuEvent *object = qscriptvalue_cast<QContextMenuEvent*>(thisObject());
return object->globalY();
}
inline const QPoint & pos()
{
QContextMenuEvent *object = qscriptvalue_cast<QContextMenuEvent*>(thisObject());
return object->pos();
}
inline const QPoint & globalPos()
{
QContextMenuEvent *object = qscriptvalue_cast<QContextMenuEvent*>(thisObject());
return object->globalPos();
}
inline QContextMenuEvent::Reason reason()
{
QContextMenuEvent *object = qscriptvalue_cast<QContextMenuEvent*>(thisObject());
return object->reason();
}
};
}

Q_DECLARE_METATYPE(QContextMenuEvent*)

#endif
