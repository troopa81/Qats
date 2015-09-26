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

#ifndef _QACTIONPROTOTYPE_
#define _QACTIONPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QAction>

#include "QObjectPrototype.h"

namespace qats
{

class QActionPrototype : public QObjectPrototype
{
Q_OBJECT

public:

QActionPrototype(QObject* parent = 0):QObjectPrototype(parent){}
public slots:

void setActionGroup(QActionGroup * group)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setActionGroup(group);
}
QActionGroup * actionGroup()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->actionGroup();
}
void setIcon(const QIcon & icon)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setIcon(icon);
}
QIcon icon()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->icon();
}
void setText(const QString & text)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setText(text);
}
QString text()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->text();
}
void setIconText(const QString & text)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setIconText(text);
}
QString iconText()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->iconText();
}
void setToolTip(const QString & tip)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setToolTip(tip);
}
QString toolTip()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->toolTip();
}
void setStatusTip(const QString & statusTip)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setStatusTip(statusTip);
}
QString statusTip()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->statusTip();
}
void setWhatsThis(const QString & what)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setWhatsThis(what);
}
QString whatsThis()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->whatsThis();
}
void setPriority(QAction::Priority priority)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setPriority(priority);
}
QAction::Priority priority()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->priority();
}
QMenu * menu()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->menu();
}
void setMenu(QMenu * menu)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setMenu(menu);
}
void setSeparator(bool b)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setSeparator(b);
}
bool isSeparator()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->isSeparator();
}
void setShortcut(const QKeySequence & shortcut)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setShortcut(shortcut);
}
QKeySequence shortcut()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->shortcut();
}
void setShortcuts(const QList<QKeySequence> & shortcuts)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setShortcuts(shortcuts);
}
void setShortcuts(QKeySequence::StandardKey param0)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setShortcuts(param0);
}
QList<QKeySequence> shortcuts()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->shortcuts();
}
void setShortcutContext(Qt::ShortcutContext context)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setShortcutContext(context);
}
Qt::ShortcutContext shortcutContext()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->shortcutContext();
}
void setAutoRepeat(bool param0)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setAutoRepeat(param0);
}
bool autoRepeat()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->autoRepeat();
}
void setFont(const QFont & font)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setFont(font);
}
QFont font()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->font();
}
void setCheckable(bool param0)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setCheckable(param0);
}
bool isCheckable()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->isCheckable();
}
QVariant data()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->data();
}
void setData(const QVariant & var)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setData(var);
}
bool isChecked()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->isChecked();
}
bool isEnabled()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->isEnabled();
}
bool isVisible()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->isVisible();
}
void activate(QAction::ActionEvent event)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->activate(event);
}
bool showStatusText(QWidget * widget = 0)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->showStatusText(widget);
}
void setMenuRole(QAction::MenuRole menuRole)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setMenuRole(menuRole);
}
QAction::MenuRole menuRole()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->menuRole();
}
void setIconVisibleInMenu(bool visible)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setIconVisibleInMenu(visible);
}
bool isIconVisibleInMenu()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->isIconVisibleInMenu();
}
QWidget * parentWidget()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->parentWidget();
}
QList<QWidget *> associatedWidgets()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->associatedWidgets();
}
QList<QGraphicsWidget *> associatedGraphicsWidgets()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->associatedGraphicsWidgets();
}
void trigger()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->trigger();
}
void hover()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->hover();
}
void setChecked(bool param0)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setChecked(param0);
}
void toggle()
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->toggle();
}
void setEnabled(bool param0)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setEnabled(param0);
}
inline void setDisabled(bool b)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
return object->setDisabled(b);
}
void setVisible(bool param0)
{
QAction *object = qscriptvalue_cast<QAction*>(thisObject());
object->setVisible(param0);
}
};
}

Q_DECLARE_METATYPE(QAction*)

#endif
