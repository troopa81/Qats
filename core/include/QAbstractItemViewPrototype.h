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

#ifndef _QABSTRACTITEMVIEWPROTOTYPE_
#define _QABSTRACTITEMVIEWPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QAbstractItemView>

#include "QAbstractScrollAreaPrototype.h"

namespace qats
{

class QAbstractItemViewPrototype : public QAbstractScrollAreaPrototype
{
Q_OBJECT

public:

QAbstractItemViewPrototype(QObject* parent = 0):QAbstractScrollAreaPrototype(parent){}
public slots:

void setModel(QAbstractItemModel * model)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setModel(model);
}
QAbstractItemModel * model()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->model();
}
void setSelectionModel(QItemSelectionModel * selectionModel)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setSelectionModel(selectionModel);
}
QItemSelectionModel * selectionModel()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->selectionModel();
}
void setItemDelegate(QAbstractItemDelegate * delegate)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setItemDelegate(delegate);
}
QAbstractItemDelegate * itemDelegate()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->itemDelegate();
}
void setSelectionMode(QAbstractItemView::SelectionMode mode)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setSelectionMode(mode);
}
QAbstractItemView::SelectionMode selectionMode()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->selectionMode();
}
void setSelectionBehavior(QAbstractItemView::SelectionBehavior behavior)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setSelectionBehavior(behavior);
}
QAbstractItemView::SelectionBehavior selectionBehavior()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->selectionBehavior();
}
QModelIndex currentIndex()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->currentIndex();
}
QModelIndex rootIndex()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->rootIndex();
}
void setEditTriggers(QAbstractItemView::EditTriggers triggers)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setEditTriggers(triggers);
}
QAbstractItemView::EditTriggers editTriggers()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->editTriggers();
}
void setVerticalScrollMode(QAbstractItemView::ScrollMode mode)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setVerticalScrollMode(mode);
}
QAbstractItemView::ScrollMode verticalScrollMode()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->verticalScrollMode();
}
void setHorizontalScrollMode(QAbstractItemView::ScrollMode mode)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setHorizontalScrollMode(mode);
}
QAbstractItemView::ScrollMode horizontalScrollMode()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->horizontalScrollMode();
}
void setAutoScroll(bool enable)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setAutoScroll(enable);
}
bool hasAutoScroll()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->hasAutoScroll();
}
void setAutoScrollMargin(int margin)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setAutoScrollMargin(margin);
}
int autoScrollMargin()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->autoScrollMargin();
}
void setTabKeyNavigation(bool enable)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setTabKeyNavigation(enable);
}
bool tabKeyNavigation()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->tabKeyNavigation();
}
void setDropIndicatorShown(bool enable)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setDropIndicatorShown(enable);
}
bool showDropIndicator()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->showDropIndicator();
}
void setDragEnabled(bool enable)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setDragEnabled(enable);
}
bool dragEnabled()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->dragEnabled();
}
void setDragDropOverwriteMode(bool overwrite)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setDragDropOverwriteMode(overwrite);
}
bool dragDropOverwriteMode()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->dragDropOverwriteMode();
}
void setDragDropMode(QAbstractItemView::DragDropMode behavior)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setDragDropMode(behavior);
}
QAbstractItemView::DragDropMode dragDropMode()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->dragDropMode();
}
void setDefaultDropAction(Qt::DropAction dropAction)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setDefaultDropAction(dropAction);
}
Qt::DropAction defaultDropAction()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->defaultDropAction();
}
void setAlternatingRowColors(bool enable)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setAlternatingRowColors(enable);
}
bool alternatingRowColors()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->alternatingRowColors();
}
void setIconSize(const QSize & size)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setIconSize(size);
}
QSize iconSize()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->iconSize();
}
void setTextElideMode(Qt::TextElideMode mode)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setTextElideMode(mode);
}
Qt::TextElideMode textElideMode()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->textElideMode();
}
void keyboardSearch(const QString & search)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->keyboardSearch(search);
}
QRect visualRect(const QModelIndex & index)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->visualRect(index);
}
void scrollTo(const QModelIndex & index,QAbstractItemView::ScrollHint hint = QAbstractItemView::EnsureVisible)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->scrollTo(index,hint);
}
QModelIndex indexAt(const QPoint & point)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->indexAt(point);
}
QSize sizeHintForIndex(const QModelIndex & index)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->sizeHintForIndex(index);
}
int sizeHintForRow(int row)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->sizeHintForRow(row);
}
int sizeHintForColumn(int column)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->sizeHintForColumn(column);
}
void openPersistentEditor(const QModelIndex & index)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->openPersistentEditor(index);
}
void closePersistentEditor(const QModelIndex & index)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->closePersistentEditor(index);
}
void setIndexWidget(const QModelIndex & index,QWidget * widget)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setIndexWidget(index,widget);
}
QWidget * indexWidget(const QModelIndex & index)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->indexWidget(index);
}
void setItemDelegateForRow(int row,QAbstractItemDelegate * delegate)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setItemDelegateForRow(row,delegate);
}
QAbstractItemDelegate * itemDelegateForRow(int row)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->itemDelegateForRow(row);
}
void setItemDelegateForColumn(int column,QAbstractItemDelegate * delegate)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setItemDelegateForColumn(column,delegate);
}
QAbstractItemDelegate * itemDelegateForColumn(int column)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->itemDelegateForColumn(column);
}
QAbstractItemDelegate * itemDelegate(const QModelIndex & index)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->itemDelegate(index);
}
QVariant inputMethodQuery(Qt::InputMethodQuery query)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->inputMethodQuery(query);
}
inline void update()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
return object->update();
}
void reset()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->reset();
}
void setRootIndex(const QModelIndex & index)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setRootIndex(index);
}
void doItemsLayout()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->doItemsLayout();
}
void selectAll()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->selectAll();
}
void edit(const QModelIndex & index)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->edit(index);
}
void clearSelection()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->clearSelection();
}
void setCurrentIndex(const QModelIndex & index)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->setCurrentIndex(index);
}
void scrollToTop()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->scrollToTop();
}
void scrollToBottom()
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->scrollToBottom();
}
void update(const QModelIndex & index)
{
QAbstractItemView *object = qscriptvalue_cast<QAbstractItemView*>(thisObject());
object->update(index);
}
};
}

Q_DECLARE_METATYPE(QAbstractItemView*)

#endif
