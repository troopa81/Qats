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

#ifndef _QABSTRACTTABLEMODELPROTOTYPE_
#define _QABSTRACTTABLEMODELPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QAbstractTableModel>

namespace qats
{

class QAbstractTableModelPrototype : public QObject, public QScriptable
{
Q_OBJECT

public:

QAbstractTableModelPrototype(QObject* parent = 0):QObject(parent){}
public slots:

// TODO : not 'const' because compilation bug. Don't understand why
QMetaObject* metaObject()
{
QAbstractTableModel *object = qscriptvalue_cast<QAbstractTableModel*>(thisObject());
return const_cast<QMetaObject*>( object->metaObject() );
}

// TODO : not 'const' because compilation bug. Don't understand why
bool inherits( QString className )
{
QAbstractTableModel *object = qscriptvalue_cast<QAbstractTableModel*>(thisObject());
return object->inherits( qPrintable( className ) );
}

QModelIndex index(int row,int column,const QModelIndex & parent = QModelIndex())
{
QAbstractTableModel *object = qscriptvalue_cast<QAbstractTableModel*>(thisObject());
return object->index(row,column,parent);
}
bool dropMimeData(const QMimeData * data,Qt::DropAction action,int row,int column,const QModelIndex & parent)
{
QAbstractTableModel *object = qscriptvalue_cast<QAbstractTableModel*>(thisObject());
return object->dropMimeData(data,action,row,column,parent);
}
Qt::ItemFlags flags(const QModelIndex & index)
{
QAbstractTableModel *object = qscriptvalue_cast<QAbstractTableModel*>(thisObject());
return object->flags(index);
}
inline QObject * parent()
{
QAbstractTableModel *object = qscriptvalue_cast<QAbstractTableModel*>(thisObject());
return object->parent();
}
};
}

Q_DECLARE_METATYPE(QAbstractTableModel*)

#endif
