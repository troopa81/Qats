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

#ifndef _QTOOLBARPROTOTYPE_
#define _QTOOLBARPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QToolBar>

#include "QWidgetPrototype.h"

namespace qats
{

class QToolBarPrototype : public QWidgetPrototype
{
Q_OBJECT

public:

QToolBarPrototype(QObject* parent = 0):QWidgetPrototype(parent){}
public slots:

void setMovable(bool movable)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
object->setMovable(movable);
}
bool isMovable()
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->isMovable();
}
void setAllowedAreas(Qt::ToolBarAreas areas)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
object->setAllowedAreas(areas);
}
Qt::ToolBarAreas allowedAreas()
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->allowedAreas();
}
inline bool isAreaAllowed(Qt::ToolBarArea area)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->isAreaAllowed(area);
}
void setOrientation(Qt::Orientation orientation)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
object->setOrientation(orientation);
}
Qt::Orientation orientation()
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->orientation();
}
void clear()
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
object->clear();
}
inline void addAction(QAction * action)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->addAction(action);
}
QAction * addAction(const QString & text)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->addAction(text);
}
QAction * addAction(const QIcon & icon,const QString & text)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->addAction(icon,text);
}
QAction * addAction(const QString & text,const QObject * receiver,const char * member)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->addAction(text,receiver,member);
}
QAction * addAction(const QIcon & icon,const QString & text,const QObject * receiver,const char * member)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->addAction(icon,text,receiver,member);
}
QAction * addSeparator()
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->addSeparator();
}
QAction * insertSeparator(QAction * before)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->insertSeparator(before);
}
QAction * addWidget(QWidget * widget)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->addWidget(widget);
}
QAction * insertWidget(QAction * before,QWidget * widget)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->insertWidget(before,widget);
}
QRect actionGeometry(QAction * action)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->actionGeometry(action);
}
QAction * actionAt(const QPoint & p)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->actionAt(p);
}
inline QAction * actionAt(int x,int y)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->actionAt(x,y);
}
QAction * toggleViewAction()
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->toggleViewAction();
}
QSize iconSize()
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->iconSize();
}
Qt::ToolButtonStyle toolButtonStyle()
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->toolButtonStyle();
}
QWidget * widgetForAction(QAction * action)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->widgetForAction(action);
}
bool isFloatable()
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->isFloatable();
}
void setFloatable(bool floatable)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
object->setFloatable(floatable);
}
bool isFloating()
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
return object->isFloating();
}
void setIconSize(const QSize & iconSize)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
object->setIconSize(iconSize);
}
void setToolButtonStyle(Qt::ToolButtonStyle toolButtonStyle)
{
QToolBar *object = qscriptvalue_cast<QToolBar*>(thisObject());
object->setToolButtonStyle(toolButtonStyle);
}
};
}

Q_DECLARE_METATYPE(QToolBar*)

#endif
