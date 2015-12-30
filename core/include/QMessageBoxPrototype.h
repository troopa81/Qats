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
Q_UNUSED(context);
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

void addButton(QAbstractButton * button,QMessageBox::ButtonRole role)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->addButton(button,role);
}
QPushButton * addButton(const QString & text,QMessageBox::ButtonRole role)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->addButton(text,role);
}
QPushButton * addButton(QMessageBox::StandardButton button)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->addButton(button);
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
QMessageBox::ButtonRole buttonRole(QAbstractButton * button)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->buttonRole(button);
}
void setStandardButtons(QMessageBox::StandardButtons buttons)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setStandardButtons(buttons);
}
QMessageBox::StandardButtons standardButtons()
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->standardButtons();
}
QMessageBox::StandardButton standardButton(QAbstractButton * button)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->standardButton(button);
}
QAbstractButton * button(QMessageBox::StandardButton which)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->button(which);
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
void setDefaultButton(QMessageBox::StandardButton button)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setDefaultButton(button);
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
void setEscapeButton(QMessageBox::StandardButton button)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setEscapeButton(button);
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
QMessageBox::Icon icon()
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
return object->icon();
}
void setIcon(QMessageBox::Icon param0)
{
QMessageBox *object = qscriptvalue_cast<QMessageBox*>(thisObject());
object->setIcon(param0);
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
QMessageBox::StandardButton information(QWidget * parent,const QString & title,const QString & text,QMessageBox::StandardButtons buttons = QMessageBox::Ok,QMessageBox::StandardButton defaultButton = QMessageBox::NoButton)
{
return QMessageBox::information(parent,title,text,buttons,defaultButton);
}
QMessageBox::StandardButton question(QWidget * parent,const QString & title,const QString & text,QMessageBox::StandardButtons buttons = QMessageBox::StandardButtons(QMessageBox::Yes|QMessageBox::No),QMessageBox::StandardButton defaultButton = QMessageBox::NoButton)
{
return QMessageBox::question(parent,title,text,buttons,defaultButton);
}
QMessageBox::StandardButton warning(QWidget * parent,const QString & title,const QString & text,QMessageBox::StandardButtons buttons = QMessageBox::Ok,QMessageBox::StandardButton defaultButton = QMessageBox::NoButton)
{
return QMessageBox::warning(parent,title,text,buttons,defaultButton);
}
QMessageBox::StandardButton critical(QWidget * parent,const QString & title,const QString & text,QMessageBox::StandardButtons buttons = QMessageBox::Ok,QMessageBox::StandardButton defaultButton = QMessageBox::NoButton)
{
return QMessageBox::critical(parent,title,text,buttons,defaultButton);
}
void about(QWidget * parent,const QString & title,const QString & text)
{
QMessageBox::about(parent,title,text);
}
void aboutQt(QWidget * parent,const QString & title = QString())
{
QMessageBox::aboutQt(parent,title);
}
int information(QWidget * parent,const QString & title,const QString & text,int button0,int button1 = 0,int button2 = 0)
{
return QMessageBox::information(parent,title,text,button0,button1,button2);
}
int information(QWidget * parent,const QString & title,const QString & text,const QString & button0Text,const QString & button1Text = QString(),const QString & button2Text = QString(),int defaultButtonNumber = 0,int escapeButtonNumber = - 1)
{
return QMessageBox::information(parent,title,text,button0Text,button1Text,button2Text,defaultButtonNumber,escapeButtonNumber);
}
QMessageBox::StandardButton information(QWidget * parent,const QString & title,const QString & text,QMessageBox::StandardButton button0,QMessageBox::StandardButton button1 = QMessageBox::NoButton)
{
return QMessageBox::information(parent,title,text,button0,button1);
}
int question(QWidget * parent,const QString & title,const QString & text,int button0,int button1 = 0,int button2 = 0)
{
return QMessageBox::question(parent,title,text,button0,button1,button2);
}
int question(QWidget * parent,const QString & title,const QString & text,const QString & button0Text,const QString & button1Text = QString(),const QString & button2Text = QString(),int defaultButtonNumber = 0,int escapeButtonNumber = - 1)
{
return QMessageBox::question(parent,title,text,button0Text,button1Text,button2Text,defaultButtonNumber,escapeButtonNumber);
}
int question(QWidget * parent,const QString & title,const QString & text,QMessageBox::StandardButton button0,QMessageBox::StandardButton button1)
{
return QMessageBox::question(parent,title,text,button0,button1);
}
int warning(QWidget * parent,const QString & title,const QString & text,int button0,int button1,int button2 = 0)
{
return QMessageBox::warning(parent,title,text,button0,button1,button2);
}
int warning(QWidget * parent,const QString & title,const QString & text,const QString & button0Text,const QString & button1Text = QString(),const QString & button2Text = QString(),int defaultButtonNumber = 0,int escapeButtonNumber = - 1)
{
return QMessageBox::warning(parent,title,text,button0Text,button1Text,button2Text,defaultButtonNumber,escapeButtonNumber);
}
int warning(QWidget * parent,const QString & title,const QString & text,QMessageBox::StandardButton button0,QMessageBox::StandardButton button1)
{
return QMessageBox::warning(parent,title,text,button0,button1);
}
int critical(QWidget * parent,const QString & title,const QString & text,int button0,int button1,int button2 = 0)
{
return QMessageBox::critical(parent,title,text,button0,button1,button2);
}
int critical(QWidget * parent,const QString & title,const QString & text,const QString & button0Text,const QString & button1Text = QString(),const QString & button2Text = QString(),int defaultButtonNumber = 0,int escapeButtonNumber = - 1)
{
return QMessageBox::critical(parent,title,text,button0Text,button1Text,button2Text,defaultButtonNumber,escapeButtonNumber);
}
int critical(QWidget * parent,const QString & title,const QString & text,QMessageBox::StandardButton button0,QMessageBox::StandardButton button1)
{
return QMessageBox::critical(parent,title,text,button0,button1);
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
QPixmap standardIcon(QMessageBox::Icon icon)
{
return QMessageBox::standardIcon(icon);
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
