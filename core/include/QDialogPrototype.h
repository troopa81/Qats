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

#ifndef _QDIALOGPROTOTYPE_
#define _QDIALOGPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QDialog>

#include "QWidgetPrototype.h"

inline QScriptValue scriptQDialogConstructor(QScriptContext *context, QScriptEngine *engine)
{
	Q_UNUSED(context);
QDialog *object = new QDialog(0);
return engine->newQObject(object, QScriptEngine::ScriptOwnership);
}

namespace qats
{

class QDialogPrototype : public QWidgetPrototype
{
Q_OBJECT

public:

static void registerToScriptEngine(QScriptEngine* engine)
{
engine->setDefaultPrototype(qMetaTypeId<QDialog*>(), engine->newQObject(new QDialogPrototype(engine)));

QScriptValue ctor = engine->newFunction(scriptQDialogConstructor);
QScriptValue metaObject = engine->newQMetaObject(&QDialog::staticMetaObject, ctor);
engine->globalObject().setProperty("QDialog", metaObject);
}

QDialogPrototype(QObject* parent = 0):QWidgetPrototype(parent){}
public slots:

int result()
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
return object->result();
}
void setVisible(bool visible)
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
object->setVisible(visible);
}
void setOrientation(Qt::Orientation orientation)
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
object->setOrientation(orientation);
}
Qt::Orientation orientation()
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
return object->orientation();
}
void setExtension(QWidget * extension)
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
object->setExtension(extension);
}
QWidget * extension()
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
return object->extension();
}
QSize sizeHint()
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
return object->sizeHint();
}
QSize minimumSizeHint()
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
return object->minimumSizeHint();
}
void setSizeGripEnabled(bool param0)
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
object->setSizeGripEnabled(param0);
}
bool isSizeGripEnabled()
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
return object->isSizeGripEnabled();
}
void setModal(bool modal)
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
object->setModal(modal);
}
void setResult(int r)
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
object->setResult(r);
}
void finished(int result)
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
object->finished(result);
}
void accepted()
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
object->accepted();
}
void rejected()
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
object->rejected();
}
void open()
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
object->open();
}
int exec()
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
return object->exec();
}
void done(int param0)
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
object->done(param0);
}
void accept()
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
object->accept();
}
void reject()
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
object->reject();
}
void showExtension(bool param0)
{
QDialog *object = qscriptvalue_cast<QDialog*>(thisObject());
object->showExtension(param0);
}
};
}

Q_DECLARE_METATYPE(QDialog*)

#endif
