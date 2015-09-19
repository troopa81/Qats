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

#ifndef _QRECTPROTOTYPE_
#define _QRECTPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QRect>

namespace qats
{

class QRectPrototype : public QObject, public QScriptable
{
Q_OBJECT

public:

QRectPrototype(QObject* parent = 0):QObject(parent){}
public slots:

	QString toString()
{
	return "TODO";
}


 inline bool isNull()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->isNull();
}
 inline bool isEmpty()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->isEmpty();
}
 inline bool isValid()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->isValid();
}
 inline int left()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->left();
}
 inline int top()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->top();
}
 inline int right()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->right();
}
 inline int bottom()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->bottom();
}
QRect normalized()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->normalized();
}
 inline int x()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->x();
}
 inline int y()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->y();
}
inline void setLeft(int pos)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->setLeft(pos);
}
inline void setTop(int pos)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->setTop(pos);
}
inline void setRight(int pos)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->setRight(pos);
}
inline void setBottom(int pos)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->setBottom(pos);
}
inline void setX(int x)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->setX(x);
}
inline void setY(int y)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->setY(y);
}
inline void setTopLeft(const QPoint & p)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->setTopLeft(p);
}
inline void setBottomRight(const QPoint & p)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->setBottomRight(p);
}
inline void setTopRight(const QPoint & p)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->setTopRight(p);
}
inline void setBottomLeft(const QPoint & p)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->setBottomLeft(p);
}
 inline QPoint topLeft()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->topLeft();
}
 inline QPoint bottomRight()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->bottomRight();
}
 inline QPoint topRight()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->topRight();
}
 inline QPoint bottomLeft()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->bottomLeft();
}
 inline QPoint center()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->center();
}
inline void moveLeft(int pos)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->moveLeft(pos);
}
inline void moveTop(int pos)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->moveTop(pos);
}
inline void moveRight(int pos)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->moveRight(pos);
}
inline void moveBottom(int pos)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->moveBottom(pos);
}
inline void moveTopLeft(const QPoint & p)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->moveTopLeft(p);
}
inline void moveBottomRight(const QPoint & p)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->moveBottomRight(p);
}
inline void moveTopRight(const QPoint & p)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->moveTopRight(p);
}
inline void moveBottomLeft(const QPoint & p)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->moveBottomLeft(p);
}
inline void moveCenter(const QPoint & p)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->moveCenter(p);
}
inline void translate(int dx,int dy)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->translate(dx,dy);
}
inline void translate(const QPoint & p)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->translate(p);
}
 inline QRect translated(int dx,int dy)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->translated(dx,dy);
}
 inline QRect translated(const QPoint & p)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->translated(p);
}
inline void moveTo(int x,int t)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->moveTo(x,t);
}
inline void moveTo(const QPoint & p)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->moveTo(p);
}
inline void setRect(int x,int y,int w,int h)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->setRect(x,y,w,h);
}
inline void getRect(int * x,int * y,int * w,int * h)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->getRect(x,y,w,h);
}
inline void setCoords(int x1,int y1,int x2,int y2)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->setCoords(x1,y1,x2,y2);
}
inline void getCoords(int * x1,int * y1,int * x2,int * y2)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->getCoords(x1,y1,x2,y2);
}
inline void adjust(int x1,int y1,int x2,int y2)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->adjust(x1,y1,x2,y2);
}
 inline QRect adjusted(int x1,int y1,int x2,int y2)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->adjusted(x1,y1,x2,y2);
}
 inline QSize size()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->size();
}
 inline int width()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->width();
}
 inline int height()
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->height();
}
inline void setWidth(int w)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->setWidth(w);
}
inline void setHeight(int h)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->setHeight(h);
}
inline void setSize(const QSize & s)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->setSize(s);
}

bool contains(const QRect & r,bool proper = false)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->contains(r,proper);
}
bool contains(const QPoint & p,bool proper = false)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->contains(p,proper);
}
inline bool contains(int x,int y)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->contains(x,y);
}
inline bool contains(int x,int y,bool proper)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->contains(x,y,proper);
}
inline QRect united(const QRect & other)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->united(other);
}
inline QRect intersected(const QRect & other)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->intersected(other);
}
bool intersects(const QRect & r)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->intersects(r);
}
inline QRect marginsAdded(const QMargins & margins)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->marginsAdded(margins);
}
inline QRect marginsRemoved(const QMargins & margins)
{
QRect *object = qscriptvalue_cast<QRect*>(thisObject());
return object->marginsRemoved(margins);
}
};
}

Q_DECLARE_METATYPE(QRect*)

#endif
