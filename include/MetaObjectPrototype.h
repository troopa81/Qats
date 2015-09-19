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

#ifndef _METAOBJECTPROTOTYPE_
#define _METAOBJECTPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QLineEdit>
#include <QScriptValue>
#include <QScriptEngine>
#include <QMetaProperty>

namespace qats
{

class MetaObjectPrototype : public QObject, public QScriptable
{
    Q_OBJECT

public:
    MetaObjectPrototype(QObject *parent = 0)
		: QObject(parent){}

public slots:

	int	indexOfProperty(QString name) const
	{
		QMetaObject *metaObject = qscriptvalue_cast<QMetaObject*>(thisObject());
		return metaObject->indexOfProperty( qPrintable( name ) );
	}

	QMetaProperty property(int index) const
	{
		QMetaObject *metaObject = qscriptvalue_cast<QMetaObject*>(thisObject());
		return metaObject->property( index );
	}

	QString className() const
	{
		QMetaObject *metaObject = qscriptvalue_cast<QMetaObject*>(thisObject());
		return QString( metaObject->className() );
	}

	QMetaObject* superClass() const
	{
		QMetaObject *metaObject = qscriptvalue_cast<QMetaObject*>(thisObject());
		return const_cast<QMetaObject*>( metaObject->superClass() );
	}
};
}

Q_DECLARE_METATYPE(QMetaObject*)

#endif 
