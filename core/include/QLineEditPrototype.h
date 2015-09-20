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

#ifndef _QLINEEDITPROTOTYPE_
#define _QLINEEDITPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QLineEdit>

namespace qats
{

class QLineEditPrototype : public QObject, public QScriptable
{
Q_OBJECT

public:

QLineEditPrototype(QObject* parent = 0):QObject(parent){}
public slots:

// TODO : not 'const' because compilation bug. Don't understand why
QMetaObject* metaObject()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return const_cast<QMetaObject*>( object->metaObject() );
}

// TODO : not 'const' because compilation bug. Don't understand why
bool inherits( QString className )
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->inherits( qPrintable( className ) );
}

QString text()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->text();
}
QString displayText()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->displayText();
}
QString placeholderText()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->placeholderText();
}
void setPlaceholderText(const QString& param0)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setPlaceholderText(param0);
}
int maxLength()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->maxLength();
}
void setMaxLength(int param0)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setMaxLength(param0);
}
void setFrame(bool param0)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setFrame(param0);
}
bool hasFrame()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->hasFrame();
}
void setClearButtonEnabled(bool enable)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setClearButtonEnabled(enable);
}
bool isClearButtonEnabled()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->isClearButtonEnabled();
}
QLineEdit::EchoMode echoMode()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->echoMode();
}
void setEchoMode(QLineEdit::EchoMode param0)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setEchoMode(param0);
}
bool isReadOnly()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->isReadOnly();
}
void setReadOnly(bool param0)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setReadOnly(param0);
}
void setValidator(const QValidator * param0)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setValidator(param0);
}
const QValidator * validator()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->validator();
}
void setCompleter(QCompleter * completer)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setCompleter(completer);
}
QCompleter * completer()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->completer();
}
QSize sizeHint()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->sizeHint();
}
QSize minimumSizeHint()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->minimumSizeHint();
}
int cursorPosition()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->cursorPosition();
}
void setCursorPosition(int param0)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setCursorPosition(param0);
}
int cursorPositionAt(const QPoint & pos)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->cursorPositionAt(pos);
}
void setAlignment(Qt::Alignment flag)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setAlignment(flag);
}
Qt::Alignment alignment()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->alignment();
}
void cursorForward(bool mark,int steps = 1)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->cursorForward(mark,steps);
}
void cursorBackward(bool mark,int steps = 1)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->cursorBackward(mark,steps);
}
void cursorWordForward(bool mark)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->cursorWordForward(mark);
}
void cursorWordBackward(bool mark)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->cursorWordBackward(mark);
}
void backspace()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->backspace();
}
void del()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->del();
}
void home(bool mark)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->home(mark);
}
void end(bool mark)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->end(mark);
}
bool isModified()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->isModified();
}
void setModified(bool param0)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setModified(param0);
}
void setSelection(int param0,int param1)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setSelection(param0,param1);
}
bool hasSelectedText()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->hasSelectedText();
}
QString selectedText()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->selectedText();
}
int selectionStart()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->selectionStart();
}
bool isUndoAvailable()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->isUndoAvailable();
}
bool isRedoAvailable()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->isRedoAvailable();
}
void setDragEnabled(bool b)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setDragEnabled(b);
}
bool dragEnabled()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->dragEnabled();
}
void setCursorMoveStyle(Qt::CursorMoveStyle style)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setCursorMoveStyle(style);
}
Qt::CursorMoveStyle cursorMoveStyle()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->cursorMoveStyle();
}
QString inputMask()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->inputMask();
}
void setInputMask(const QString & inputMask)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setInputMask(inputMask);
}
bool hasAcceptableInput()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->hasAcceptableInput();
}
void setTextMargins(int left,int top,int right,int bottom)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setTextMargins(left,top,right,bottom);
}
void setTextMargins(const QMargins & margins)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setTextMargins(margins);
}
void getTextMargins(int * left,int * top,int * right,int * bottom)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->getTextMargins(left,top,right,bottom);
}
QMargins textMargins()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->textMargins();
}
inline void addAction(QAction * action)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->addAction(action);
}
void addAction(QAction * action,QLineEdit::ActionPosition position)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->addAction(action,position);
}
QAction * addAction(const QIcon & icon,QLineEdit::ActionPosition position)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->addAction(icon,position);
}
void setText(const QString& param0)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->setText(param0);
}
void clear()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->clear();
}
void selectAll()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->selectAll();
}
void undo()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->undo();
}
void redo()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->redo();
}
void cut()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->cut();
}
void copy()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->copy();
}
void paste()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->paste();
}
void deselect()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->deselect();
}
void insert(const QString& param0)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
object->insert(param0);
}
QMenu * createStandardContextMenu()
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->createStandardContextMenu();
}
QVariant inputMethodQuery(Qt::InputMethodQuery param0)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->inputMethodQuery(param0);
}
bool event(QEvent * param0)
{
QLineEdit *object = qscriptvalue_cast<QLineEdit*>(thisObject());
return object->event(param0);
}
};
}

Q_DECLARE_METATYPE(QLineEdit*)

#endif
