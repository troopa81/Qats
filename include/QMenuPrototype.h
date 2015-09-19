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

#ifndef _QMENUPROTOTYPE_
#define _QMENUPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QMenu>

namespace qats
{

class QMenuPrototype : public QObject, public QScriptable
{
Q_OBJECT

public:

QMenuPrototype(QObject* parent = 0):QObject(parent){}
public slots:

QAction * addAction(const QString & text)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->addAction(text);
}
QAction * addAction(const QIcon & icon,const QString & text)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->addAction(icon,text);
}
QAction * addAction(const QString & text,const QObject * receiver,const char * member,const QKeySequence & shortcut = 0)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->addAction(text,receiver,member,shortcut);
}
QAction * addAction(const QIcon & icon,const QString & text,const QObject * receiver,const char * member,const QKeySequence & shortcut = 0)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->addAction(icon,text,receiver,member,shortcut);
}
QAction * addMenu(QMenu * menu)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->addMenu(menu);
}
QMenu * addMenu(const QString & title)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->addMenu(title);
}
QMenu * addMenu(const QIcon & icon,const QString & title)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->addMenu(icon,title);
}
QAction * addSeparator()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->addSeparator();
}
QAction * addSection(const QString & text)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->addSection(text);
}
QAction * addSection(const QIcon & icon,const QString & text)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->addSection(icon,text);
}
QAction * insertMenu(QAction * before,QMenu * menu)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->insertMenu(before,menu);
}
QAction * insertSeparator(QAction * before)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->insertSeparator(before);
}
QAction * insertSection(QAction * before,const QString & text)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->insertSection(before,text);
}
QAction * insertSection(QAction * before,const QIcon & icon,const QString & text)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->insertSection(before,icon,text);
}
bool isEmpty()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->isEmpty();
}
void clear()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
object->clear();
}
void setTearOffEnabled(bool param0)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
object->setTearOffEnabled(param0);
}
bool isTearOffEnabled()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->isTearOffEnabled();
}
bool isTearOffMenuVisible()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->isTearOffMenuVisible();
}
void hideTearOffMenu()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
object->hideTearOffMenu();
}
void setDefaultAction(QAction * param0)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
object->setDefaultAction(param0);
}
QAction * defaultAction()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->defaultAction();
}
void setActiveAction(QAction * act)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
object->setActiveAction(act);
}
QAction * activeAction()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->activeAction();
}
void popup(const QPoint & pos,QAction * at = 0)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
object->popup(pos,at);
}
QAction * exec()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->exec();
}
QAction * exec(const QPoint & pos,QAction * at = 0)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->exec(pos,at);
}
QAction * exec(QList<QAction *> actions,const QPoint & pos,QAction * at = 0,QWidget * parent = 0)
{
return QMenu::exec(actions,pos,at,parent);
}
QSize sizeHint()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->sizeHint();
}
QRect actionGeometry(QAction * param0)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->actionGeometry(param0);
}
QAction * actionAt(const QPoint& param0)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->actionAt(param0);
}
QAction * menuAction()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->menuAction();
}
QString title()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->title();
}
void setTitle(const QString & title)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
object->setTitle(title);
}
QIcon icon()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->icon();
}
void setIcon(const QIcon & icon)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
object->setIcon(icon);
}
void setNoReplayFor(QWidget * widget)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
object->setNoReplayFor(widget);
}
QPlatformMenu * platformMenu()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->platformMenu();
}
bool separatorsCollapsible()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->separatorsCollapsible();
}
void setSeparatorsCollapsible(bool collapse)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
object->setSeparatorsCollapsible(collapse);
}
bool toolTipsVisible()
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
return object->toolTipsVisible();
}
void setToolTipsVisible(bool visible)
{
QMenu *object = qscriptvalue_cast<QMenu*>(thisObject());
object->setToolTipsVisible(visible);
}
};
}

Q_DECLARE_METATYPE(QMenu*)

#endif
