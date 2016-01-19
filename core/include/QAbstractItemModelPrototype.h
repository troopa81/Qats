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

#ifndef _QABSTRACTITEMMODELPROTOTYPE_
#define _QABSTRACTITEMMODELPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QAbstractItemModel>
#include "Test.h"

namespace qats
{

class QAbstractItemModelPrototype : public QObjectPrototype
{
Q_OBJECT

public:

QAbstractItemModelPrototype(QObject* parent = 0):QObjectPrototype(parent){}
public slots:

bool hasIndex(int row,int column,const QModelIndex & parent = QModelIndex())
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->hasIndex(row,column,parent);
}
QModelIndex index(int row,int column,const QModelIndex & parent = QModelIndex())
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->index(row,column,parent);
}
QModelIndex parent(const QModelIndex & child)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->parent(child);
}
QModelIndex sibling(int row,int column,const QModelIndex & idx)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->sibling(row,column,idx);
}
int rowCount(const QModelIndex & parent = QModelIndex())
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->rowCount(parent);
}
int columnCount(const QModelIndex & parent = QModelIndex())
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->columnCount(parent);
}
bool hasChildren(const QModelIndex & parent = QModelIndex())
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->hasChildren(parent);
}
QVariant data(const QModelIndex & index,int role = Qt::DisplayRole)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->data(index,role);
}
bool setData(const QModelIndex & index,const QVariant & value,int role = Qt::EditRole)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->setData(index,value,role);
}
QVariant headerData(int section,Qt::Orientation orientation,int role = Qt::DisplayRole)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->headerData(section,orientation,role);
}
bool setHeaderData(int section,Qt::Orientation orientation,const QVariant & value,int role = Qt::EditRole)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->setHeaderData(section,orientation,value,role);
}
QMap<int, QVariant> itemData(const QModelIndex & index)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->itemData(index);
}
bool setItemData(const QModelIndex & index,const QMap<int, QVariant> & roles)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->setItemData(index,roles);
}
QStringList mimeTypes()
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->mimeTypes();
}
QMimeData * mimeData(const QModelIndexList & indexes)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->mimeData(indexes);
}
bool canDropMimeData(const QMimeData * data,Qt::DropAction action,int row,int column,const QModelIndex & parent)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->canDropMimeData(data,action,row,column,parent);
}
bool dropMimeData(const QMimeData * data,Qt::DropAction action,int row,int column,const QModelIndex & parent)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->dropMimeData(data,action,row,column,parent);
}
Qt::DropActions supportedDropActions()
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->supportedDropActions();
}
Qt::DropActions supportedDragActions()
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->supportedDragActions();
}
bool insertRows(int row,int count,const QModelIndex & parent = QModelIndex())
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->insertRows(row,count,parent);
}
bool insertColumns(int column,int count,const QModelIndex & parent = QModelIndex())
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->insertColumns(column,count,parent);
}
bool removeRows(int row,int count,const QModelIndex & parent = QModelIndex())
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->removeRows(row,count,parent);
}
bool removeColumns(int column,int count,const QModelIndex & parent = QModelIndex())
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->removeColumns(column,count,parent);
}
bool moveRows(const QModelIndex & sourceParent,int sourceRow,int count,const QModelIndex & destinationParent,int destinationChild)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->moveRows(sourceParent,sourceRow,count,destinationParent,destinationChild);
}
bool moveColumns(const QModelIndex & sourceParent,int sourceColumn,int count,const QModelIndex & destinationParent,int destinationChild)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->moveColumns(sourceParent,sourceColumn,count,destinationParent,destinationChild);
}
inline bool insertRow(int row,const QModelIndex & parent = QModelIndex())
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->insertRow(row,parent);
}
inline bool insertColumn(int column,const QModelIndex & parent = QModelIndex())
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->insertColumn(column,parent);
}
inline bool removeRow(int row,const QModelIndex & parent = QModelIndex())
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->removeRow(row,parent);
}
inline bool removeColumn(int column,const QModelIndex & parent = QModelIndex())
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->removeColumn(column,parent);
}
inline bool moveRow(const QModelIndex & sourceParent,int sourceRow,const QModelIndex & destinationParent,int destinationChild)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->moveRow(sourceParent,sourceRow,destinationParent,destinationChild);
}
inline bool moveColumn(const QModelIndex & sourceParent,int sourceColumn,const QModelIndex & destinationParent,int destinationChild)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->moveColumn(sourceParent,sourceColumn,destinationParent,destinationChild);
}
void fetchMore(const QModelIndex & parent)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
object->fetchMore(parent);
}
bool canFetchMore(const QModelIndex & parent)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->canFetchMore(parent);
}
Qt::ItemFlags flags(const QModelIndex & index)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->flags(index);
}
void sort(int column,Qt::SortOrder order = Qt::AscendingOrder)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
object->sort(column,order);
}
QModelIndex buddy(const QModelIndex & index)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->buddy(index);
}
QModelIndexList match(const QModelIndex & start,int role,const QVariant & value,int hits, Qt::MatchFlags flags)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->match(start,role,value,hits,flags);
}

QSize span(const QModelIndex & index)
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->span(index);
}
QHash<int, QByteArray> roleNames()
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->roleNames();
}
inline QObject * parent()
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->parent();
}
bool submit()
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
return object->submit();
}
void revert()
{
QAbstractItemModel *object = qscriptvalue_cast<QAbstractItemModel*>(thisObject());
object->revert();
}
};
}

Q_DECLARE_METATYPE(QAbstractItemModel*)

#endif
