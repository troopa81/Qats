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

#ifndef _QCOMBOBOXPROTOTYPE_
#define _QCOMBOBOXPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QComboBox>

#include "QWidgetPrototype.h"

namespace qats
{

class QComboBoxPrototype : public QWidgetPrototype
{
Q_OBJECT

public:

QComboBoxPrototype(QObject* parent = 0):QWidgetPrototype(parent){}
public slots:

int maxVisibleItems()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->maxVisibleItems();
}
void setMaxVisibleItems(int maxItems)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setMaxVisibleItems(maxItems);
}
int count()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->count();
}
void setMaxCount(int max)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setMaxCount(max);
}
int maxCount()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->maxCount();
}
bool autoCompletion()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->autoCompletion();
}
void setAutoCompletion(bool enable)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setAutoCompletion(enable);
}
Qt::CaseSensitivity autoCompletionCaseSensitivity()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->autoCompletionCaseSensitivity();
}
void setAutoCompletionCaseSensitivity(Qt::CaseSensitivity sensitivity)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setAutoCompletionCaseSensitivity(sensitivity);
}
bool duplicatesEnabled()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->duplicatesEnabled();
}
void setDuplicatesEnabled(bool enable)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setDuplicatesEnabled(enable);
}
void setFrame(bool param0)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setFrame(param0);
}
bool hasFrame()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->hasFrame();
}
inline int findText(const QString & text,Qt::MatchFlags flags = static_cast <Qt::MatchFlags >(Qt::MatchExactly|Qt::MatchCaseSensitive))
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->findText(text,flags);
}
int findData(const QVariant & data,int role = Qt::UserRole,Qt::MatchFlags flags = static_cast <Qt::MatchFlags >(Qt::MatchExactly|Qt::MatchCaseSensitive))
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->findData(data,role,flags);
}
QComboBox::InsertPolicy insertPolicy()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->insertPolicy();
}
void setInsertPolicy(QComboBox::InsertPolicy policy)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setInsertPolicy(policy);
}
QComboBox::SizeAdjustPolicy sizeAdjustPolicy()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->sizeAdjustPolicy();
}
void setSizeAdjustPolicy(QComboBox::SizeAdjustPolicy policy)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setSizeAdjustPolicy(policy);
}
int minimumContentsLength()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->minimumContentsLength();
}
void setMinimumContentsLength(int characters)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setMinimumContentsLength(characters);
}
QSize iconSize()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->iconSize();
}
void setIconSize(const QSize & size)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setIconSize(size);
}
bool isEditable()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->isEditable();
}
void setEditable(bool editable)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setEditable(editable);
}
void setLineEdit(QLineEdit * edit)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setLineEdit(edit);
}
QLineEdit * lineEdit()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->lineEdit();
}
void setValidator(const QValidator * v)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setValidator(v);
}
const QValidator * validator()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->validator();
}
void setCompleter(QCompleter * c)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setCompleter(c);
}
QCompleter * completer()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->completer();
}
QAbstractItemDelegate * itemDelegate()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->itemDelegate();
}
void setItemDelegate(QAbstractItemDelegate * delegate)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setItemDelegate(delegate);
}
QAbstractItemModel * model()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->model();
}
void setModel(QAbstractItemModel * model)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setModel(model);
}
QModelIndex rootModelIndex()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->rootModelIndex();
}
void setRootModelIndex(const QModelIndex & index)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setRootModelIndex(index);
}
int modelColumn()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->modelColumn();
}
void setModelColumn(int visibleColumn)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setModelColumn(visibleColumn);
}
int currentIndex()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->currentIndex();
}
QString currentText()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->currentText();
}
QVariant currentData(int role = Qt::UserRole)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->currentData(role);
}
QString itemText(int index)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->itemText(index);
}
QIcon itemIcon(int index)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->itemIcon(index);
}
QVariant itemData(int index,int role = Qt::UserRole)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->itemData(index,role);
}
inline void addItem(const QString & text,const QVariant & userData = QVariant())
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->addItem(text,userData);
}
inline void addItem(const QIcon & icon,const QString & text,const QVariant & userData = QVariant())
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->addItem(icon,text,userData);
}
inline void addItems(const QStringList & texts)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->addItems(texts);
}
inline void insertItem(int index,const QString & text,const QVariant & userData = QVariant())
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->insertItem(index,text,userData);
}
void insertItem(int index,const QIcon & icon,const QString & text,const QVariant & userData = QVariant())
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->insertItem(index,icon,text,userData);
}
void insertItems(int index,const QStringList & texts)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->insertItems(index,texts);
}
void insertSeparator(int index)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->insertSeparator(index);
}
void removeItem(int index)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->removeItem(index);
}
void setItemText(int index,const QString & text)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setItemText(index,text);
}
void setItemIcon(int index,const QIcon & icon)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setItemIcon(index,icon);
}
void setItemData(int index,const QVariant & value,int role = Qt::UserRole)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setItemData(index,value,role);
}
QAbstractItemView * view()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->view();
}
void setView(QAbstractItemView * itemView)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setView(itemView);
}
QSize sizeHint()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->sizeHint();
}
QSize minimumSizeHint()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->minimumSizeHint();
}
void showPopup()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->showPopup();
}
void hidePopup()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->hidePopup();
}
bool event(QEvent * event)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->event(event);
}
QVariant inputMethodQuery(Qt::InputMethodQuery param0)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
return object->inputMethodQuery(param0);
}
void clear()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->clear();
}
void clearEditText()
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->clearEditText();
}
void setEditText(const QString & text)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setEditText(text);
}
void setCurrentIndex(int index)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setCurrentIndex(index);
}
void setCurrentText(const QString & text)
{
QComboBox *object = qscriptvalue_cast<QComboBox*>(thisObject());
object->setCurrentText(text);
}
};
}

Q_DECLARE_METATYPE(QComboBox*)

#endif
