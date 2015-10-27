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

#ifndef _QFILEDEVICEPROTOTYPE_
#define _QFILEDEVICEPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QFileDevice>

#include "QIODevicePrototype.h"

namespace qats
{

class QFileDevicePrototype : public QIODevicePrototype
{
Q_OBJECT

public:

static void registerToScriptEngine(QScriptEngine* engine)
{
engine->setDefaultPrototype(qMetaTypeId<QFileDevice*>(), engine->newQObject(new QFileDevicePrototype(engine)));

QScriptValue metaObject = engine->newQMetaObject(&QFileDevice::staticMetaObject);
engine->globalObject().setProperty("QFileDevice", metaObject);
}

QFileDevicePrototype(QObject* parent = 0):QIODevicePrototype(parent){}
public slots:

int error()
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
return object->error();
}
void unsetError()
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
object->unsetError();
}
void close()
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
object->close();
}
bool isSequential()
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
return object->isSequential();
}
int handle()
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
return object->handle();
}
QString fileName()
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
return object->fileName();
}
qint64 pos()
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
return object->pos();
}
bool seek(qint64 offset)
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
return object->seek(offset);
}
bool atEnd()
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
return object->atEnd();
}
bool flush()
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
return object->flush();
}
qint64 size()
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
return object->size();
}
bool resize(qint64 sz)
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
return object->resize(sz);
}
int permissions()
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
return object->permissions();
}
bool setPermissions(int permissionSpec)
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
return object->setPermissions(QFileDevice::Permissions(permissionSpec));
}
uchar * map(qint64 offset,qint64 size,int flags = QFileDevice::NoOptions)
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
return object->map(offset,size,QFileDevice::MemoryMapFlags(flags));
}
bool unmap(uchar * address)
{
QFileDevice *object = qscriptvalue_cast<QFileDevice*>(thisObject());
return object->unmap(address);
}
};
}

Q_DECLARE_METATYPE(QFileDevice*)

#endif
