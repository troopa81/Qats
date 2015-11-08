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

#ifndef _QPOINTFPROTOTYPE_
#define _QPOINTFPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QPointF>


inline QScriptValue scriptQPointFConstructor(QScriptContext *context, QScriptEngine *engine)
{
Q_UNUSED(context);
QPointF object;
return engine->newVariant( QVariant( object ) );}

namespace qats
{

class QPointFPrototype : public  QObject, public QScriptable
{
Q_OBJECT

public:

static void registerToScriptEngine(QScriptEngine* engine)
{
engine->setDefaultPrototype(qMetaTypeId<QPointF>(), engine->newQObject(new QPointFPrototype(engine)));
engine->setDefaultPrototype(qMetaTypeId<QPointF*>(), engine->newQObject(new QPointFPrototype(engine)));

QScriptValue ctor = engine->newFunction(scriptQPointFConstructor);
engine->globalObject().setProperty("QPointF", ctor);
}

QPointFPrototype(QObject* parent = 0):QObject(parent){}
public slots:

Q_DECL_CONSTEXPR inline qreal manhattanLength()
{
QPointF *object = qscriptvalue_cast<QPointF*>(thisObject());
return object->manhattanLength();
}
inline bool isNull()
{
QPointF *object = qscriptvalue_cast<QPointF*>(thisObject());
return object->isNull();
}
Q_DECL_CONSTEXPR inline qreal x()
{
QPointF *object = qscriptvalue_cast<QPointF*>(thisObject());
return object->x();
}
Q_DECL_CONSTEXPR inline qreal y()
{
QPointF *object = qscriptvalue_cast<QPointF*>(thisObject());
return object->y();
}
inline void setX(qreal x)
{
QPointF *object = qscriptvalue_cast<QPointF*>(thisObject());
return object->setX(x);
}
inline void setY(qreal y)
{
QPointF *object = qscriptvalue_cast<QPointF*>(thisObject());
return object->setY(y);
}
inline qreal & rx()
{
QPointF *object = qscriptvalue_cast<QPointF*>(thisObject());
return object->rx();
}
inline qreal & ry()
{
QPointF *object = qscriptvalue_cast<QPointF*>(thisObject());
return object->ry();
}
inline qreal dotProduct(const QPointF & p1,const QPointF & p2)
{
return QPointF::dotProduct(p1,p2);
}
Q_DECL_CONSTEXPR QPoint toPoint()
{
QPointF *object = qscriptvalue_cast<QPointF*>(thisObject());
return object->toPoint();
}
};
}

Q_DECLARE_METATYPE(QPointF*)

#endif
