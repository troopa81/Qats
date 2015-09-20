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

#ifndef _QITEMSELECTIONMODELPROTOTYPE_
#define _QITEMSELECTIONMODELPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QItemSelectionModel>

namespace qats
{

class QItemSelectionModelPrototype : public QObject, public QScriptable
{
Q_OBJECT

public:

QItemSelectionModelPrototype(QObject* parent = 0):QObject(parent){}
public slots:

// TODO : not 'const' because compilation bug. Don't understand why
QMetaObject* metaObject()
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
return const_cast<QMetaObject*>( object->metaObject() );
}

// TODO : not 'const' because compilation bug. Don't understand why
bool inherits( QString className )
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
return object->inherits( qPrintable( className ) );
}

QModelIndex currentIndex()
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
return object->currentIndex();
}
bool isSelected(const QModelIndex & index)
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
return object->isSelected(index);
}
bool isRowSelected(int row,const QModelIndex & parent)
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
return object->isRowSelected(row,parent);
}
bool isColumnSelected(int column,const QModelIndex & parent)
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
return object->isColumnSelected(column,parent);
}
bool rowIntersectsSelection(int row,const QModelIndex & parent)
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
return object->rowIntersectsSelection(row,parent);
}
bool columnIntersectsSelection(int column,const QModelIndex & parent)
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
return object->columnIntersectsSelection(column,parent);
}
bool hasSelection()
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
return object->hasSelection();
}
QModelIndexList selectedIndexes()
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
return object->selectedIndexes();
}
QModelIndexList selectedRows(int column = 0)
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
return object->selectedRows(column);
}
QModelIndexList selectedColumns(int row = 0)
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
return object->selectedColumns(row);
}
const QItemSelection selection()
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
return object->selection();
}
const QAbstractItemModel * model()
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
return object->model();
}
void setCurrentIndex(const QModelIndex & index,QItemSelectionModel::SelectionFlags command)
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
object->setCurrentIndex(index,command);
}
void select(const QModelIndex & index,QItemSelectionModel::SelectionFlags command)
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
object->select(index,command);
}
void select(const QItemSelection & selection,QItemSelectionModel::SelectionFlags command)
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
object->select(selection,command);
}
void clear()
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
object->clear();
}
void reset()
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
object->reset();
}
void clearSelection()
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
object->clearSelection();
}
void clearCurrentIndex()
{
QItemSelectionModel *object = qscriptvalue_cast<QItemSelectionModel*>(thisObject());
object->clearCurrentIndex();
}
};
}


#endif
