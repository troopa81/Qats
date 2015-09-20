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

#ifndef _QCOREAPPLICATIONPROTOTYPE_
#define _QCOREAPPLICATIONPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QCoreApplication>

namespace qats
{

class QCoreApplicationPrototype : public QObject, public QScriptable
{
Q_OBJECT

public:

QCoreApplicationPrototype(QObject* parent = 0):QObject(parent){}
public slots:

// TODO : not 'const' because compilation bug. Don't understand why
QMetaObject* metaObject()
{
QCoreApplication *object = qscriptvalue_cast<QCoreApplication*>(thisObject());
return const_cast<QMetaObject*>( object->metaObject() );
}

// TODO : not 'const' because compilation bug. Don't understand why
bool inherits( QString className )
{
QCoreApplication *object = qscriptvalue_cast<QCoreApplication*>(thisObject());
return object->inherits( qPrintable( className ) );
}

QStringList arguments()
{
return QCoreApplication::arguments();
}
void setAttribute(Qt::ApplicationAttribute attribute,bool on = true)
{
QCoreApplication::setAttribute(attribute,on);
}
bool testAttribute(Qt::ApplicationAttribute attribute)
{
return QCoreApplication::testAttribute(attribute);
}
void setOrganizationDomain(const QString & orgDomain)
{
QCoreApplication::setOrganizationDomain(orgDomain);
}
QString organizationDomain()
{
return QCoreApplication::organizationDomain();
}
void setOrganizationName(const QString & orgName)
{
QCoreApplication::setOrganizationName(orgName);
}
QString organizationName()
{
return QCoreApplication::organizationName();
}
void setApplicationName(const QString & application)
{
QCoreApplication::setApplicationName(application);
}
QString applicationName()
{
return QCoreApplication::applicationName();
}
void setApplicationVersion(const QString & version)
{
QCoreApplication::setApplicationVersion(version);
}
QString applicationVersion()
{
return QCoreApplication::applicationVersion();
}
QCoreApplication * instance()
{
return QCoreApplication::instance();
}
int exec()
{
return QCoreApplication::exec();
}
void processEvents(int flags = QEventLoop::AllEvents)
{
	QCoreApplication::processEvents(QEventLoop::ProcessEventsFlags(flags));
}
void processEvents(int flags,int maxtime)
{
	QCoreApplication::processEvents(QEventLoop::ProcessEventsFlags(flags),maxtime);
}
void exit(int retcode = 0)
{
QCoreApplication::exit(retcode);
}
bool sendEvent(QObject * receiver,QEvent * event)
{
return QCoreApplication::sendEvent(receiver,event);
}
void postEvent(QObject * receiver,QEvent * event,int priority = Qt::NormalEventPriority)
{
QCoreApplication::postEvent(receiver,event,priority);
}
void sendPostedEvents(QObject * receiver = 0,int event_type = 0)
{
QCoreApplication::sendPostedEvents(receiver,event_type);
}
void removePostedEvents(QObject * receiver,int eventType = 0)
{
QCoreApplication::removePostedEvents(receiver,eventType);
}
bool hasPendingEvents()
{
return QCoreApplication::hasPendingEvents();
}
QAbstractEventDispatcher * eventDispatcher()
{
return QCoreApplication::eventDispatcher();
}
void setEventDispatcher(QAbstractEventDispatcher * eventDispatcher)
{
QCoreApplication::setEventDispatcher(eventDispatcher);
}
bool notify(QObject * param0,QEvent * param1)
{
QCoreApplication *object = qscriptvalue_cast<QCoreApplication*>(thisObject());
return object->notify(param0,param1);
}
bool startingUp()
{
return QCoreApplication::startingUp();
}
bool closingDown()
{
return QCoreApplication::closingDown();
}
QString applicationDirPath()
{
return QCoreApplication::applicationDirPath();
}
QString applicationFilePath()
{
return QCoreApplication::applicationFilePath();
}
qint64 applicationPid()
{
return QCoreApplication::applicationPid();
}
void setLibraryPaths(const QStringList& param0)
{
QCoreApplication::setLibraryPaths(param0);
}
QStringList libraryPaths()
{
return QCoreApplication::libraryPaths();
}
void addLibraryPath(const QString& param0)
{
QCoreApplication::addLibraryPath(param0);
}
void removeLibraryPath(const QString& param0)
{
QCoreApplication::removeLibraryPath(param0);
}
bool installTranslator(QTranslator * messageFile)
{
return QCoreApplication::installTranslator(messageFile);
}
bool removeTranslator(QTranslator * messageFile)
{
return QCoreApplication::removeTranslator(messageFile);
}
QString translate(const char * context,const char * key,const char * disambiguation = 0,int n = - 1)
{
return QCoreApplication::translate(context,key,disambiguation,n);
}
void flush()
{
QCoreApplication::flush();
}
void installNativeEventFilter(QAbstractNativeEventFilter * filterObj)
{
QCoreApplication *object = qscriptvalue_cast<QCoreApplication*>(thisObject());
object->installNativeEventFilter(filterObj);
}
void removeNativeEventFilter(QAbstractNativeEventFilter * filterObj)
{
QCoreApplication *object = qscriptvalue_cast<QCoreApplication*>(thisObject());
object->removeNativeEventFilter(filterObj);
}
bool isQuitLockEnabled()
{
return QCoreApplication::isQuitLockEnabled();
}
void setQuitLockEnabled(bool enabled)
{
QCoreApplication::setQuitLockEnabled(enabled);
}
void quit()
{
QCoreApplication::quit();
}
};
}

Q_DECLARE_METATYPE(QCoreApplication*)

#endif
