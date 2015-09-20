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

#ifndef _QTESTPROTOTYPE_
#define _QTESTPROTOTYPE_

#include <QObject>
#include <QScriptable>
#include <QScriptValue>
#include <QScriptEngine>
#include <QTest>
#include <QContextMenuEvent>

namespace qats
{

class QTestPrototype : public QObject, public QScriptable
{
    Q_OBJECT

public:
    QTestPrototype(QObject *parent = 0)
		: QObject(parent){}

public slots:


	void qWait(int ms)
	{
		QTest::qWait(ms);
	}

	// TODO : to be removed when we succeed in create QContextMenuEvent from script
	void postContextMenuEvent( QWidget* widget, QPoint pos )
	{
		QApplication::instance()->postEvent( widget, new QContextMenuEvent( QContextMenuEvent::Mouse, pos ) );
	}

	void keyClick(QWidget * widget, Qt::Key key, Qt::KeyboardModifiers modifier = Qt::NoModifier, int delay = -1)
	{
		QTest::keyClick( widget, key, modifier, delay );
	}

	void mouseMove(QWidget * widget, QPoint pos = QPoint(), int delay = -1)
	{
		QTest::mouseMove( widget, pos, delay );
	}

	void mouseClick(QWidget * widget, Qt::MouseButton button, Qt::KeyboardModifiers modifier = 0, QPoint pos = QPoint(), int delay = -1)
	{
		QTest::mouseClick( widget, button, modifier, pos, delay );
	}

	void mouseDClick(QWidget * widget, Qt::MouseButton button, Qt::KeyboardModifiers modifier = 0, QPoint pos = QPoint(), int delay = -1)
	{
		QTest::mouseDClick( widget, button, modifier, pos, delay );
	}

	void keyClicks(QWidget * widget, const QString & sequence, Qt::KeyboardModifiers modifier = Qt::NoModifier, int delay = -1)
	{
		QTest::keyClicks( widget, sequence, modifier, delay );
	}
};
}

#endif 
