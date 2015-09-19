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

#ifndef _QABSTRACTSCROLLAREAPROTOTYPE_
#define _QABSTRACTSCROLLAREAPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QAbstractScrollArea>
#include "QFramePrototype.h"

namespace qats
{

class QAbstractScrollAreaPrototype : public QFramePrototype
{
Q_OBJECT

public:

QAbstractScrollAreaPrototype(QObject* parent = 0):QFramePrototype(parent){}
public slots:

Qt::ScrollBarPolicy verticalScrollBarPolicy()
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
return object->verticalScrollBarPolicy();
}
void setVerticalScrollBarPolicy(Qt::ScrollBarPolicy param0)
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
object->setVerticalScrollBarPolicy(param0);
}
QScrollBar * verticalScrollBar()
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
return object->verticalScrollBar();
}
void setVerticalScrollBar(QScrollBar * scrollbar)
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
object->setVerticalScrollBar(scrollbar);
}
Qt::ScrollBarPolicy horizontalScrollBarPolicy()
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
return object->horizontalScrollBarPolicy();
}
void setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy param0)
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
object->setHorizontalScrollBarPolicy(param0);
}
QScrollBar * horizontalScrollBar()
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
return object->horizontalScrollBar();
}
void setHorizontalScrollBar(QScrollBar * scrollbar)
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
object->setHorizontalScrollBar(scrollbar);
}
QWidget * cornerWidget()
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
return object->cornerWidget();
}
void setCornerWidget(QWidget * widget)
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
object->setCornerWidget(widget);
}
void addScrollBarWidget(QWidget * widget,Qt::Alignment alignment)
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
object->addScrollBarWidget(widget,alignment);
}
QWidgetList scrollBarWidgets(Qt::Alignment alignment)
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
return object->scrollBarWidgets(alignment);
}
QWidget * viewport()
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
return object->viewport();
}
void setViewport(QWidget * widget)
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
object->setViewport(widget);
}
QSize maximumViewportSize()
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
return object->maximumViewportSize();
}
QSize minimumSizeHint()
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
return object->minimumSizeHint();
}
QSize sizeHint()
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
return object->sizeHint();
}
void setupViewport(QWidget * viewport)
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
object->setupViewport(viewport);
}
QAbstractScrollArea::SizeAdjustPolicy sizeAdjustPolicy()
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
return object->sizeAdjustPolicy();
}
void setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy policy)
{
QAbstractScrollArea *object = qscriptvalue_cast<QAbstractScrollArea*>(thisObject());
object->setSizeAdjustPolicy(policy);
}
};
}

Q_DECLARE_METATYPE(QAbstractScrollArea*)

#endif
