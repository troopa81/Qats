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

#ifndef QATS_MAINWINDOW_H
#define QATS_MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "Qats.h"
#include "Test.h"

namespace Ui
{
class MainWindow;
}

namespace qats
{

class QATS_EXPORT MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	// public operations
	MainWindow( QWidget* parent = 0 );
	virtual ~MainWindow();

protected slots:

	void on__testCases_doubleClicked(const QModelIndex & index);
	void on__loadScripts_clicked();
	void onOutputReceived();

protected: 

	QString getLineFromFile( const QString& filePath, int line ) const;
	void addBacktraceItems( QStandardItem* root, const QString& strBacktrace ) const;

	Ui::MainWindow* _ui; 
	QStandardItemModel*    _model;
	QStandardItemModel*    _outputModel;
}; 

}; 

#endif
