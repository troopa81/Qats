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

#ifndef _QAPPLICATIONPROTOTYPE_
#define _QAPPLICATIONPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QApplication>

#include "QCoreApplicationPrototype.h"

namespace qats
{

class QApplicationPrototype : public QCoreApplicationPrototype
{
Q_OBJECT

public:

QApplicationPrototype(QObject* parent = 0):QCoreApplicationPrototype(parent){}
public slots:

// TODO : not 'const' because compilation bug. Don't understand why
QMetaObject* metaObject()
{
QApplication *object = qscriptvalue_cast<QApplication*>(thisObject());
return const_cast<QMetaObject*>( object->metaObject() );
}

// TODO : not 'const' because compilation bug. Don't understand why
bool inherits( QString className )
{
QApplication *object = qscriptvalue_cast<QApplication*>(thisObject());
return object->inherits( qPrintable( className ) );
}

QStyle * style()
{
return QApplication::style();
}
void setStyle(QStyle * param0)
{
QApplication::setStyle(param0);
}
QStyle * setStyle(const QString& param0)
{
return QApplication::setStyle(param0);
}
int colorSpec()
{
return QApplication::colorSpec();
}
void setColorSpec(int param0)
{
QApplication::setColorSpec(param0);
}
QPalette palette()
{
return QApplication::palette();
}
QPalette palette(const QWidget * param0)
{
return QApplication::palette(param0);
}
QPalette palette(const char * className)
{
return QApplication::palette(className);
}
void setPalette(const QPalette& param0,const char * className = 0)
{
QApplication::setPalette(param0,className);
}
QFont font()
{
return QApplication::font();
}
QFont font(const QWidget * param0)
{
return QApplication::font(param0);
}
QFont font(const char * className)
{
return QApplication::font(className);
}
void setFont(const QFont& param0,const char * className = 0)
{
QApplication::setFont(param0,className);
}
QFontMetrics fontMetrics()
{
return QApplication::fontMetrics();
}
void setWindowIcon(const QIcon & icon)
{
QApplication::setWindowIcon(icon);
}
QIcon windowIcon()
{
return QApplication::windowIcon();
}
QWidgetList allWidgets()
{
return QApplication::allWidgets();
}
QWidgetList topLevelWidgets()
{
return QApplication::topLevelWidgets();
}
QDesktopWidget * desktop()
{
return QApplication::desktop();
}
QWidget * activePopupWidget()
{
return QApplication::activePopupWidget();
}
QWidget * activeModalWidget()
{
return QApplication::activeModalWidget();
}
QWidget * focusWidget()
{
return QApplication::focusWidget();
}
QWidget * activeWindow()
{
return QApplication::activeWindow();
}
void setActiveWindow(QWidget * act)
{
QApplication::setActiveWindow(act);
}
QWidget * widgetAt(const QPoint & p)
{
return QApplication::widgetAt(p);
}
inline QWidget * widgetAt(int x,int y)
{
return QApplication::widgetAt(x,y);
}
QWidget * topLevelAt(const QPoint & p)
{
return QApplication::topLevelAt(p);
}
inline QWidget * topLevelAt(int x,int y)
{
return QApplication::topLevelAt(x,y);
}
void beep()
{
QApplication::beep();
}
void alert(QWidget * widget,int duration = 0)
{
QApplication::alert(widget,duration);
}
void setCursorFlashTime(int param0)
{
QApplication::setCursorFlashTime(param0);
}
int cursorFlashTime()
{
return QApplication::cursorFlashTime();
}
void setDoubleClickInterval(int param0)
{
QApplication::setDoubleClickInterval(param0);
}
int doubleClickInterval()
{
return QApplication::doubleClickInterval();
}
void setKeyboardInputInterval(int param0)
{
QApplication::setKeyboardInputInterval(param0);
}
int keyboardInputInterval()
{
return QApplication::keyboardInputInterval();
}
void setWheelScrollLines(int param0)
{
QApplication::setWheelScrollLines(param0);
}
int wheelScrollLines()
{
return QApplication::wheelScrollLines();
}
void setGlobalStrut(const QSize& param0)
{
QApplication::setGlobalStrut(param0);
}
QSize globalStrut()
{
return QApplication::globalStrut();
}
void setStartDragTime(int ms)
{
QApplication::setStartDragTime(ms);
}
int startDragTime()
{
return QApplication::startDragTime();
}
void setStartDragDistance(int l)
{
QApplication::setStartDragDistance(l);
}
int startDragDistance()
{
return QApplication::startDragDistance();
}
bool isEffectEnabled(Qt::UIEffect param0)
{
return QApplication::isEffectEnabled(param0);
}
void setEffectEnabled(Qt::UIEffect param0,bool enable = true)
{
QApplication::setEffectEnabled(param0,enable);
}
int exec()
{
return QApplication::exec();
}
bool notify(QObject * param0,QEvent * param1)
{
QApplication *object = qscriptvalue_cast<QApplication*>(thisObject());
return object->notify(param0,param1);
}
QString styleSheet()
{
QApplication *object = qscriptvalue_cast<QApplication*>(thisObject());
return object->styleSheet();
}
void setStyleSheet(const QString & sheet)
{
QApplication *object = qscriptvalue_cast<QApplication*>(thisObject());
object->setStyleSheet(sheet);
}
void setAutoSipEnabled(const bool enabled)
{
QApplication *object = qscriptvalue_cast<QApplication*>(thisObject());
object->setAutoSipEnabled(enabled);
}
bool autoSipEnabled()
{
QApplication *object = qscriptvalue_cast<QApplication*>(thisObject());
return object->autoSipEnabled();
}
void closeAllWindows()
{
QApplication::closeAllWindows();
}
void aboutQt()
{
QApplication::aboutQt();
}
};
}

Q_DECLARE_METATYPE(QApplication*)

#endif
