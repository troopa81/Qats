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

#ifndef _QPOINTPROTOTYPE_
#define _QPOINTPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QPoint>


inline QScriptValue scriptQPointConstructor(QScriptContext *context, QScriptEngine *engine)
{
Q_UNUSED(context);
QPoint object;
return engine->newVariant( QVariant( object ) );}

namespace qats
{

class QPointPrototype : public  QObject, public QScriptable
{
Q_OBJECT

public:

static void registerToScriptEngine(QScriptEngine* engine)
{
engine->setDefaultPrototype(qMetaTypeId<QPoint>(), engine->newQObject(new QPointPrototype(engine)));
engine->setDefaultPrototype(qMetaTypeId<QPoint*>(), engine->newQObject(new QPointPrototype(engine)));

QScriptValue ctor = engine->newFunction(scriptQPointConstructor);
engine->globalObject().setProperty("QPoint", ctor);
}

QPointPrototype(QObject* parent = 0):QObject(parent){}
public slots:

Q_DECL_CONSTEXPR inline bool isNull()
{
QPoint *object = qscriptvalue_cast<QPoint*>(thisObject());
return object->isNull();
}
Q_DECL_CONSTEXPR inline int x()
{
QPoint *object = qscriptvalue_cast<QPoint*>(thisObject());
return object->x();
}
Q_DECL_CONSTEXPR inline int y()
{
QPoint *object = qscriptvalue_cast<QPoint*>(thisObject());
return object->y();
}
inline void setX(int x)
{
QPoint *object = qscriptvalue_cast<QPoint*>(thisObject());
return object->setX(x);
}
inline void setY(int y)
{
QPoint *object = qscriptvalue_cast<QPoint*>(thisObject());
return object->setY(y);
}
Q_DECL_CONSTEXPR inline int manhattanLength()
{
QPoint *object = qscriptvalue_cast<QPoint*>(thisObject());
return object->manhattanLength();
}
inline int & rx()
{
QPoint *object = qscriptvalue_cast<QPoint*>(thisObject());
return object->rx();
}
inline int & ry()
{
QPoint *object = qscriptvalue_cast<QPoint*>(thisObject());
return object->ry();
}
inline int dotProduct(const QPoint & p1,const QPoint & p2)
{
return QPoint::dotProduct(p1,p2);
}
};
}

Q_DECLARE_METATYPE(QPoint*)

#endif
