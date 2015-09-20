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

#ifndef _QTREEVIEWPROTOTYPE_
#define _QTREEVIEWPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QTreeView>
#include "QAbstractItemViewPrototype.h"

namespace qats
{


class QTreeViewPrototype : public QAbstractItemViewPrototype
{
Q_OBJECT

public:



QTreeViewPrototype(QObject* parent = 0):QAbstractItemViewPrototype(parent){}
public slots:


void setModel(QAbstractItemModel * model)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setModel(model);
}
void setRootIndex(const QModelIndex & index)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setRootIndex(index);
}
void setSelectionModel(QItemSelectionModel * selectionModel)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setSelectionModel(selectionModel);
}
QHeaderView * header()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->header();
}
void setHeader(QHeaderView * header)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setHeader(header);
}
int autoExpandDelay()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->autoExpandDelay();
}
void setAutoExpandDelay(int delay)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setAutoExpandDelay(delay);
}
int indentation()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->indentation();
}
void setIndentation(int i)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setIndentation(i);
}
bool rootIsDecorated()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->rootIsDecorated();
}
void setRootIsDecorated(bool show)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setRootIsDecorated(show);
}
bool uniformRowHeights()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->uniformRowHeights();
}
void setUniformRowHeights(bool uniform)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setUniformRowHeights(uniform);
}
bool itemsExpandable()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->itemsExpandable();
}
void setItemsExpandable(bool enable)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setItemsExpandable(enable);
}
bool expandsOnDoubleClick()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->expandsOnDoubleClick();
}
void setExpandsOnDoubleClick(bool enable)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setExpandsOnDoubleClick(enable);
}
int columnViewportPosition(int column)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->columnViewportPosition(column);
}
int columnWidth(int column)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->columnWidth(column);
}
void setColumnWidth(int column,int width)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setColumnWidth(column,width);
}
int columnAt(int x)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->columnAt(x);
}
bool isColumnHidden(int column)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->isColumnHidden(column);
}
void setColumnHidden(int column,bool hide)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setColumnHidden(column,hide);
}
bool isHeaderHidden()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->isHeaderHidden();
}
void setHeaderHidden(bool hide)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setHeaderHidden(hide);
}
bool isRowHidden(int row,const QModelIndex & parent)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->isRowHidden(row,parent);
}
void setRowHidden(int row,const QModelIndex & parent,bool hide)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setRowHidden(row,parent,hide);
}
bool isFirstColumnSpanned(int row,const QModelIndex & parent)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->isFirstColumnSpanned(row,parent);
}
void setFirstColumnSpanned(int row,const QModelIndex & parent,bool span)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setFirstColumnSpanned(row,parent,span);
}
bool isExpanded(const QModelIndex & index)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->isExpanded(index);
}
void setExpanded(const QModelIndex & index,bool expand)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setExpanded(index,expand);
}
void setSortingEnabled(bool enable)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setSortingEnabled(enable);
}
bool isSortingEnabled()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->isSortingEnabled();
}
void setAnimated(bool enable)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setAnimated(enable);
}
bool isAnimated()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->isAnimated();
}
void setAllColumnsShowFocus(bool enable)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setAllColumnsShowFocus(enable);
}
bool allColumnsShowFocus()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->allColumnsShowFocus();
}
void setWordWrap(bool on)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setWordWrap(on);
}
bool wordWrap()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->wordWrap();
}
void setTreePosition(int logicalIndex)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->setTreePosition(logicalIndex);
}
int treePosition()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->treePosition();
}
void keyboardSearch(const QString & search)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->keyboardSearch(search);
}
QRect visualRect(const QModelIndex & index)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->visualRect(index);
}


void scrollTo(const QModelIndex & index,QAbstractItemView::ScrollHint hint)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->scrollTo(index,hint);
}
QModelIndex indexAt(const QPoint & p)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->indexAt(p);
}
QModelIndex indexAbove(const QModelIndex & index)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->indexAbove(index);
}
QModelIndex indexBelow(const QModelIndex & index)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
return object->indexBelow(index);
}
void doItemsLayout()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->doItemsLayout();
}
void reset()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->reset();
}
void sortByColumn(int column,Qt::SortOrder order)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->sortByColumn(column,order);
}
void dataChanged(const QModelIndex & topLeft,const QModelIndex & bottomRight,const QVector<int> & roles)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->dataChanged(topLeft,bottomRight,roles);
}
void selectAll()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->selectAll();
}
void hideColumn(int column)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->hideColumn(column);
}
void showColumn(int column)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->showColumn(column);
}
void expand(const QModelIndex & index)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->expand(index);
}
void collapse(const QModelIndex & index)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->collapse(index);
}
void resizeColumnToContents(int column)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->resizeColumnToContents(column);
}
void sortByColumn(int column)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->sortByColumn(column);
}
void expandAll()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->expandAll();
}
void collapseAll()
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->collapseAll();
}
void expandToDepth(int depth)
{
QTreeView *object = qscriptvalue_cast<QTreeView*>(thisObject());
object->expandToDepth(depth);
}
};
}

Q_DECLARE_METATYPE(QTreeView*)

#endif
