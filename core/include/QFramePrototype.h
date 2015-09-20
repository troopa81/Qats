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

#ifndef _QFRAMEPROTOTYPE_
#define _QFRAMEPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QFrame>

#include "QWidgetPrototype.h"

namespace qats
{

class QFramePrototype : public QWidgetPrototype
{
Q_OBJECT

public:

QFramePrototype(QObject* parent = 0):QWidgetPrototype(parent){}
public slots:

int frameStyle()
{
QFrame *object = qscriptvalue_cast<QFrame*>(thisObject());
return object->frameStyle();
}
void setFrameStyle(int param0)
{
QFrame *object = qscriptvalue_cast<QFrame*>(thisObject());
object->setFrameStyle(param0);
}
int frameWidth()
{
QFrame *object = qscriptvalue_cast<QFrame*>(thisObject());
return object->frameWidth();
}
QSize sizeHint()
{
QFrame *object = qscriptvalue_cast<QFrame*>(thisObject());
return object->sizeHint();
}
QFrame::Shape frameShape()
{
QFrame *object = qscriptvalue_cast<QFrame*>(thisObject());
return object->frameShape();
}
void setFrameShape(QFrame::Shape param0)
{
QFrame *object = qscriptvalue_cast<QFrame*>(thisObject());
object->setFrameShape(param0);
}
QFrame::Shadow frameShadow()
{
QFrame *object = qscriptvalue_cast<QFrame*>(thisObject());
return object->frameShadow();
}
void setFrameShadow(QFrame::Shadow param0)
{
QFrame *object = qscriptvalue_cast<QFrame*>(thisObject());
object->setFrameShadow(param0);
}
int lineWidth()
{
QFrame *object = qscriptvalue_cast<QFrame*>(thisObject());
return object->lineWidth();
}
void setLineWidth(int param0)
{
QFrame *object = qscriptvalue_cast<QFrame*>(thisObject());
object->setLineWidth(param0);
}
int midLineWidth()
{
QFrame *object = qscriptvalue_cast<QFrame*>(thisObject());
return object->midLineWidth();
}
void setMidLineWidth(int param0)
{
QFrame *object = qscriptvalue_cast<QFrame*>(thisObject());
object->setMidLineWidth(param0);
}
QRect frameRect()
{
QFrame *object = qscriptvalue_cast<QFrame*>(thisObject());
return object->frameRect();
}
void setFrameRect(const QRect& param0)
{
QFrame *object = qscriptvalue_cast<QFrame*>(thisObject());
object->setFrameRect(param0);
}
};
}

Q_DECLARE_METATYPE(QFrame*)

#endif
