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

#ifndef _QIODEVICEPROTOTYPE_
#define _QIODEVICEPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QIODevice>

#include "QObjectPrototype.h"

namespace qats
{

class QIODevicePrototype : public QObjectPrototype
{
Q_OBJECT

public:

static void registerToScriptEngine(QScriptEngine* engine)
{
engine->setDefaultPrototype(qMetaTypeId<QIODevice*>(), engine->newQObject(new QIODevicePrototype(engine)));

}

QIODevicePrototype(QObject* parent = 0):QObjectPrototype(parent){}
public slots:

int openMode()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->openMode();
}
void setTextModeEnabled(bool enabled)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
object->setTextModeEnabled(enabled);
}
bool isTextModeEnabled()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->isTextModeEnabled();
}
bool isOpen()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->isOpen();
}
bool isReadable()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->isReadable();
}
bool isWritable()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->isWritable();
}
bool isSequential()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->isSequential();
}
bool open(int mode)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->open(QIODevice::OpenMode(mode));
}
void close()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
object->close();
}
qint64 pos()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->pos();
}
qint64 size()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->size();
}
bool seek(qint64 pos)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->seek(pos);
}
bool atEnd()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->atEnd();
}
bool reset()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->reset();
}
qint64 bytesAvailable()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->bytesAvailable();
}
qint64 bytesToWrite()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->bytesToWrite();
}
qint64 read(char * data,qint64 maxlen)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->read(data,maxlen);
}
QByteArray read(qint64 maxlen)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->read(maxlen);
}
QByteArray readAll()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->readAll();
}
qint64 readLine(char * data,qint64 maxlen)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->readLine(data,maxlen);
}
QByteArray readLine(qint64 maxlen = 0)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->readLine(maxlen);
}
bool canReadLine()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->canReadLine();
}
qint64 write(const char * data,qint64 len)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->write(data,len);
}
qint64 write(const char * data)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->write(data);
}
inline qint64 write(const QByteArray & data)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->write(data);
}
qint64 peek(char * data,qint64 maxlen)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->peek(data,maxlen);
}
QByteArray peek(qint64 maxlen)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->peek(maxlen);
}
bool waitForReadyRead(int msecs)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->waitForReadyRead(msecs);
}
bool waitForBytesWritten(int msecs)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->waitForBytesWritten(msecs);
}
void ungetChar(char c)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
object->ungetChar(c);
}
bool putChar(char c)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->putChar(c);
}
bool getChar(char * c)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->getChar(c);
}
QString errorString()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
return object->errorString();
}
void readyRead()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
object->readyRead();
}
void bytesWritten(qint64 bytes)
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
object->bytesWritten(bytes);
}
void aboutToClose()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
object->aboutToClose();
}
void readChannelFinished()
{
QIODevice *object = qscriptvalue_cast<QIODevice*>(thisObject());
object->readChannelFinished();
}
};
}

Q_DECLARE_METATYPE(QIODevice*)

#endif
