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

#ifndef _QABSTRACTLISTMODELPROTOTYPE_
#define _QABSTRACTLISTMODELPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QAbstractListModel>

namespace qats
{

class QAbstractListModelPrototype : public QObject, public QScriptable
{
Q_OBJECT

public:

QAbstractListModelPrototype(QObject* parent = 0):QObject(parent){}
public slots:

// TODO : not 'const' because compilation bug. Don't understand why
QMetaObject* metaObject()
{
QAbstractListModel *object = qscriptvalue_cast<QAbstractListModel*>(thisObject());
return const_cast<QMetaObject*>( object->metaObject() );
}

// TODO : not 'const' because compilation bug. Don't understand why
bool inherits( QString className )
{
QAbstractListModel *object = qscriptvalue_cast<QAbstractListModel*>(thisObject());
return object->inherits( qPrintable( className ) );
}

QModelIndex index(int row,int column = 0,const QModelIndex & parent = QModelIndex())
{
QAbstractListModel *object = qscriptvalue_cast<QAbstractListModel*>(thisObject());
return object->index(row,column,parent);
}
bool dropMimeData(const QMimeData * data,Qt::DropAction action,int row,int column,const QModelIndex & parent)
{
QAbstractListModel *object = qscriptvalue_cast<QAbstractListModel*>(thisObject());
return object->dropMimeData(data,action,row,column,parent);
}
Qt::ItemFlags flags(const QModelIndex & index)
{
QAbstractListModel *object = qscriptvalue_cast<QAbstractListModel*>(thisObject());
return object->flags(index);
}
inline QObject * parent()
{
QAbstractListModel *object = qscriptvalue_cast<QAbstractListModel*>(thisObject());
return object->parent();
}
};
}

Q_DECLARE_METATYPE(QAbstractListModel*)

#endif
