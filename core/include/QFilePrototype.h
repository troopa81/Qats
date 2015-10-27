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

#ifndef _QFILEPROTOTYPE_
#define _QFILEPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QFile>

#include "QFileDevicePrototype.h"

inline QScriptValue scriptQFileConstructor(QScriptContext *context, QScriptEngine *engine)
{
Q_UNUSED(context);
QFile *object = new QFile(0);
return engine->newQObject(object, QScriptEngine::ScriptOwnership);
}

namespace qats
{

class QFilePrototype : public QFileDevicePrototype
{
Q_OBJECT

public:

static void registerToScriptEngine(QScriptEngine* engine)
{
engine->setDefaultPrototype(qMetaTypeId<QFile*>(), engine->newQObject(new QFilePrototype(engine)));

QScriptValue ctor = engine->newFunction(scriptQFileConstructor);
QScriptValue metaObject = engine->newQMetaObject(&QFile::staticMetaObject, ctor);
engine->globalObject().setProperty("QFile", metaObject);
}

QFilePrototype(QObject* parent = 0):QFileDevicePrototype(parent){}
public slots:

QString fileName()
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
return object->fileName();
}
void setFileName(const QString & name)
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
object->setFileName(name);
}
inline QByteArray encodeName(const QString & fileName)
{
return QFile::encodeName(fileName);
}
QString decodeName(const QByteArray & localFileName)
{
return QFile::decodeName(localFileName);
}
QString decodeName(const char * localFileName)
{
return QFile::decodeName(localFileName);
}
bool exists()
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
return object->exists();
}
bool exists(const QString & fileName)
{
return QFile::exists(fileName);
}
QString readLink()
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
return object->readLink();
}
QString readLink(const QString & fileName)
{
return QFile::readLink(fileName);
}
inline QString symLinkTarget()
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
return object->symLinkTarget();
}
QString symLinkTarget(const QString & fileName)
{
return QFile::symLinkTarget(fileName);
}
bool remove()
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
return object->remove();
}
bool remove(const QString & fileName)
{
return QFile::remove(fileName);
}
bool rename(const QString & newName)
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
return object->rename(newName);
}
bool rename(const QString & oldName,const QString & newName)
{
return QFile::rename(oldName,newName);
}
bool link(const QString & newName)
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
return object->link(newName);
}
bool link(const QString & oldname,const QString & newName)
{
return QFile::link(oldname,newName);
}
bool copy(const QString & newName)
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
return object->copy(newName);
}
bool copy(const QString & fileName,const QString & newName)
{
return QFile::copy(fileName,newName);
}
bool open(int flags)
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
return object->open(QIODevice::OpenMode(flags));
}
bool open(FILE * f,int ioFlags,int handleFlags = QFileDevice::DontCloseHandle)
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
return object->open(f,QIODevice::OpenMode(ioFlags),QFileDevice::FileHandleFlags(handleFlags));
}
bool open(int fd,int ioFlags,int handleFlags = QFileDevice::DontCloseHandle)
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
return object->open(fd,QIODevice::OpenMode(ioFlags),QFileDevice::FileHandleFlags(handleFlags));
}
qint64 size()
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
return object->size();
}
bool resize(qint64 sz)
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
return object->resize(sz);
}
bool resize(const QString & filename,qint64 sz)
{
return QFile::resize(filename,sz);
}
int permissions()
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
return object->permissions();
}
int permissions(const QString & filename)
{
return QFile::permissions(filename);
}
bool setPermissions(int permissionSpec)
{
QFile *object = qscriptvalue_cast<QFile*>(thisObject());
return object->setPermissions(QFileDevice::Permissions(permissionSpec));
}
bool setPermissions(const QString & filename,int permissionSpec)
{
return QFile::setPermissions(filename,QFileDevice::Permissions(permissionSpec));
}
};
}

Q_DECLARE_METATYPE(QFile*)

#endif
