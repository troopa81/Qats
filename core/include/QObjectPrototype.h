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

#ifndef _QOBJECTPROTOTYPE_
#define _QOBJECTPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QObject>

namespace qats
{

class QObjectPrototype : public QObject, public QScriptable
{
Q_OBJECT

public:

QObjectPrototype(QObject* parent = 0):QObject(parent){}
public slots:

// TODO : not 'const' because compilation bug. Don't understand why
QMetaObject* metaObject()
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return const_cast<QMetaObject*>( object->metaObject() );
}

// TODO : not 'const' because compilation bug. Don't understand why
bool inherits( QString className )
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->inherits( qPrintable( className ) );
}

bool event(QEvent * param0)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->event(param0);
}
bool eventFilter(QObject * param0,QEvent * param1)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->eventFilter(param0,param1);
}

QString objectName()
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->objectName();
}
void setObjectName(const QString & name)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
object->setObjectName(name);
}
inline bool isWidgetType()
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->isWidgetType();
}
inline bool isWindowType()
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->isWindowType();
}
inline bool signalsBlocked()
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->signalsBlocked();
}
bool blockSignals(bool b)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->blockSignals(b);
}
QThread * thread()
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->thread();
}
void moveToThread(QThread * thread)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
object->moveToThread(thread);
}
int startTimer(int interval,Qt::TimerType timerType = Qt::CoarseTimer)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->startTimer(interval,timerType);
}
void killTimer(int id)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
object->killTimer(id);
}

/*!
inline T findChild(const QString & aName = QString(),Qt::FindChildOptions options = Qt::FindChildrenRecursively)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->findChild(aName,options);
}
inline QList<T> findChildren(const QString & aName = QString(),Qt::FindChildOptions options = Qt::FindChildrenRecursively)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->findChildren(aName,options);
}
inline QList<T> findChildren(const QRegExp & re,Qt::FindChildOptions options = Qt::FindChildrenRecursively)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->findChildren(re,options);
}
inline QList<T> findChildren(const QRegularExpression & re,Qt::FindChildOptions options = Qt::FindChildrenRecursively)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->findChildren(re,options);
}
*/

inline QObjectList children()
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->children();
}
void setParent(QObject * param0)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
object->setParent(param0);
}
void installEventFilter(QObject * param0)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
object->installEventFilter(param0);
}
void removeEventFilter(QObject * param0)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
object->removeEventFilter(param0);
}
/*!
QMetaObject::Connection connect(const QObject * sender,const char * signal,const QObject * receiver,const char * member, Qt::ConnectionType = Qt::AutoConnection)
{
	return QObject::connect(sender,signal,receiver,member,Qt::ConnectionType);
}
*/
QMetaObject::Connection connect(const QObject * sender,const QMetaMethod & signal,const QObject * receiver,const QMetaMethod & method,Qt::ConnectionType type = Qt::AutoConnection)
{
return QObject::connect(sender,signal,receiver,method,type);
}

inline QMetaObject::Connection connect(const QObject * sender,const char * signal,const char * member,Qt::ConnectionType type = Qt::AutoConnection)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->connect(sender,signal,member,type);
}
bool disconnect(const QObject * sender,const char * signal,const QObject * receiver,const char * member)
{
return QObject::disconnect(sender,signal,receiver,member);
}
bool disconnect(const QObject * sender,const QMetaMethod & signal,const QObject * receiver,const QMetaMethod & member)
{
return QObject::disconnect(sender,signal,receiver,member);
}
inline bool disconnect(const char * signal = 0,const QObject * receiver = 0,const char * member = 0)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->disconnect(signal,receiver,member);
}
inline bool disconnect(const QObject * receiver,const char * member = 0)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->disconnect(receiver,member);
}
bool disconnect(const QMetaObject::Connection& param0)
{
return QObject::disconnect(param0);
}
void dumpObjectTree()
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
object->dumpObjectTree();
}
void dumpObjectInfo()
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
object->dumpObjectInfo();
}
bool setProperty(const char * name,const QVariant & value)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->setProperty(name,value);
}
QVariant property(const char * name)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->property(name);
}
QList<QByteArray> dynamicPropertyNames()
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->dynamicPropertyNames();
}
uint registerUserData()
{
return QObject::registerUserData();
}
void setUserData(unsigned int id,QObjectUserData * data)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
object->setUserData(id,data);
}
QObjectUserData * userData(unsigned int id)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->userData(id);
}
inline QObject * parent()
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->parent();
}
inline bool inherits(const char * classname)
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
return object->inherits(classname);
}
void deleteLater()
{
QObject *object = qscriptvalue_cast<QObject*>(thisObject());
object->deleteLater();
}
};
}

Q_DECLARE_METATYPE(QObject*)

#endif
