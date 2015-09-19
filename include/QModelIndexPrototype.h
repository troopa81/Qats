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

#ifndef _QMODELINDEXPROTOTYPE_
#define _QMODELINDEXPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QModelIndex>

namespace qats
{

class QModelIndexPrototype : public QObject, public QScriptable
{
Q_OBJECT

public:

QModelIndexPrototype(QObject* parent = 0):QObject(parent){}
public slots:

Q_DECL_CONSTEXPR inline int row()
{
QModelIndex *object = qscriptvalue_cast<QModelIndex*>(thisObject());
return object->row();
}
Q_DECL_CONSTEXPR inline int column()
{
QModelIndex *object = qscriptvalue_cast<QModelIndex*>(thisObject());
return object->column();
}
Q_DECL_CONSTEXPR inline quintptr internalId()
{
QModelIndex *object = qscriptvalue_cast<QModelIndex*>(thisObject());
return object->internalId();
}
inline void * internalPointer()
{
QModelIndex *object = qscriptvalue_cast<QModelIndex*>(thisObject());
return object->internalPointer();
}
inline QModelIndex parent()
{
QModelIndex *object = qscriptvalue_cast<QModelIndex*>(thisObject());
return object->parent();
}
inline QModelIndex sibling(int row,int column)
{
QModelIndex *object = qscriptvalue_cast<QModelIndex*>(thisObject());
return object->sibling(row,column);
}
inline QModelIndex child(int row,int column)
{
QModelIndex *object = qscriptvalue_cast<QModelIndex*>(thisObject());
return object->child(row,column);
}
inline QVariant data(int role = Qt::DisplayRole)
{
QModelIndex *object = qscriptvalue_cast<QModelIndex*>(thisObject());
return object->data(role);
}
inline Qt::ItemFlags flags()
{
QModelIndex *object = qscriptvalue_cast<QModelIndex*>(thisObject());
return object->flags();
}
Q_DECL_CONSTEXPR inline const QAbstractItemModel * model()
{
QModelIndex *object = qscriptvalue_cast<QModelIndex*>(thisObject());
return object->model();
}
Q_DECL_CONSTEXPR inline bool isValid()
{
QModelIndex *object = qscriptvalue_cast<QModelIndex*>(thisObject());
return object->isValid();
}
};
}

Q_DECLARE_METATYPE(QModelIndex*)

#endif
