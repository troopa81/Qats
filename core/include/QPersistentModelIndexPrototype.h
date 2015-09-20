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

#ifndef _QPERSISTENTMODELINDEXPROTOTYPE_
#define _QPERSISTENTMODELINDEXPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QPersistentModelIndex>

namespace qats
{

class QPersistentModelIndexPrototype : public QObject, public QScriptable
{
Q_OBJECT

public:

QPersistentModelIndexPrototype(QObject* parent = 0):QObject(parent){}
public slots:

inline void swap(QPersistentModelIndex & other)
{
QPersistentModelIndex *object = qscriptvalue_cast<QPersistentModelIndex*>(thisObject());
return object->swap(other);
}
int row()
{
QPersistentModelIndex *object = qscriptvalue_cast<QPersistentModelIndex*>(thisObject());
return object->row();
}
int column()
{
QPersistentModelIndex *object = qscriptvalue_cast<QPersistentModelIndex*>(thisObject());
return object->column();
}
void * internalPointer()
{
QPersistentModelIndex *object = qscriptvalue_cast<QPersistentModelIndex*>(thisObject());
return object->internalPointer();
}
quintptr internalId()
{
QPersistentModelIndex *object = qscriptvalue_cast<QPersistentModelIndex*>(thisObject());
return object->internalId();
}
QModelIndex parent()
{
QPersistentModelIndex *object = qscriptvalue_cast<QPersistentModelIndex*>(thisObject());
return object->parent();
}
QModelIndex sibling(int row,int column)
{
QPersistentModelIndex *object = qscriptvalue_cast<QPersistentModelIndex*>(thisObject());
return object->sibling(row,column);
}
QModelIndex child(int row,int column)
{
QPersistentModelIndex *object = qscriptvalue_cast<QPersistentModelIndex*>(thisObject());
return object->child(row,column);
}
QVariant data(int role = Qt::DisplayRole)
{
QPersistentModelIndex *object = qscriptvalue_cast<QPersistentModelIndex*>(thisObject());
return object->data(role);
}
Qt::ItemFlags flags()
{
QPersistentModelIndex *object = qscriptvalue_cast<QPersistentModelIndex*>(thisObject());
return object->flags();
}
const QAbstractItemModel * model()
{
QPersistentModelIndex *object = qscriptvalue_cast<QPersistentModelIndex*>(thisObject());
return object->model();
}
bool isValid()
{
QPersistentModelIndex *object = qscriptvalue_cast<QPersistentModelIndex*>(thisObject());
return object->isValid();
}
};
}

Q_DECLARE_METATYPE(QPersistentModelIndex*)

#endif
