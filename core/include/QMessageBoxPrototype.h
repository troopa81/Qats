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

#ifndef _QMESSAGEBOXPROTOTYPE_
#define _QMESSAGEBOXPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QMessageBox>

#include "QDialogPrototype.h"

inline QScriptValue scriptQMessageBoxConstructor(QScriptContext *context, QScriptEngine *engine)
{
QMessageBox *object = new QMessageBox(0);
return engine->newQObject(object, QScriptEngine::ScriptOwnership);
}

namespace qats
{

class QMessageBoxPrototype : public QDialogPrototype
{
Q_OBJECT

public:

static void registerToScriptEngine(QScriptEngine* engine)
{
engine->setDefaultPrototype(qMetaTypeId<QMessageBox*>(), engine->newQObject(new QMessageBoxPrototype(engine)));

QScriptValue ctor = engine->newFunction(scriptQMessageBoxConstructor);
QScriptValue metaObject = engine->newQMetaObject(&QMessageBox::staticMetaObject, ctor);
engine->globalObject().setProperty("QMessageBox", metaObject);
}

QMessageBoxPrototype(QObject* parent = 0):QDialogPrototype(parent){}
public slots:

void addButton(QAbstractButton * button,int role)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->addButton(button,QMessageBox::ButtonRole(role));
}
QPushButton * addButton(const QString & text,int role)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->addButton(text,QMessageBox::ButtonRole(role));
}
QPushButton * addButton(int button)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->addButton(QMessageBox::StandardButton(button));
}
void removeButton(QAbstractButton * button)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->removeButton(button);
}
void open(QObject * receiver,const char * member)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->open(receiver,member);
}
QList<QAbstractButton *> buttons()
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->buttons();
}
int buttonRole(QAbstractButton * button)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->buttonRole(button);
}
void setStandardButtons(int buttons)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setStandardButtons(QMessageBox::StandardButtons(buttons));
}
int standardButtons()
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->standardButtons();
}
int standardButton(QAbstractButton * button)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->standardButton(button);
}
QAbstractButton * button(int which)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->button(QMessageBox::StandardButton(which));
}
QPushButton * defaultButton()
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->defaultButton();
}
void setDefaultButton(QPushButton * button)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setDefaultButton(button);
}
void setDefaultButton(int button)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setDefaultButton(QMessageBox::StandardButton(button));
}
QAbstractButton * escapeButton()
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->escapeButton();
}
void setEscapeButton(QAbstractButton * button)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setEscapeButton(button);
}
void setEscapeButton(int button)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setEscapeButton(QMessageBox::StandardButton(button));
}
QAbstractButton * clickedButton()
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->clickedButton();
}
QString text()
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->text();
}
void setText(const QString & text)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setText(text);
}
int icon()
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->icon();
}
void setIcon(int param0)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setIcon(QMessageBox::Icon(param0));
}
QPixmap iconPixmap()
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->iconPixmap();
}
void setIconPixmap(const QPixmap & pixmap)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setIconPixmap(pixmap);
}
Qt::TextFormat textFormat()
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->textFormat();
}
void setTextFormat(Qt::TextFormat format)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setTextFormat(format);
}
void setTextInteractionFlags(Qt::TextInteractionFlags flags)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setTextInteractionFlags(flags);
}
Qt::TextInteractionFlags textInteractionFlags()
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->textInteractionFlags();
}
void setCheckBox(QCheckBox * cb)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setCheckBox(cb);
}
QCheckBox * checkBox()
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->checkBox();
}
QString buttonText(int button)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->buttonText(button);
}
void setButtonText(int button,const QString & text)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setButtonText(button,text);
}
QString informativeText()
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->informativeText();
}
void setInformativeText(const QString & text)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setInformativeText(text);
}
QString detailedText()
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->detailedText();
}
void setDetailedText(const QString & text)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setDetailedText(text);
}
void setWindowTitle(const QString & title)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setWindowTitle(title);
}
void setWindowModality(Qt::WindowModality windowModality)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setWindowModality(windowModality);
}
QPixmap standardIcon(int icon)
{
return QMessageBox::standardIcon(QMessageBox::Icon(icon));
}
void buttonClicked(QAbstractButton * button)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->buttonClicked(button);
}
};
}

Q_DECLARE_METATYPE(QMessageBox*)

#endif
