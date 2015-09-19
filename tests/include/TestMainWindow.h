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

#include <Qats.h>

namespace Ui
{
class TestMainWindow;
}

namespace qats
{

class QATS_EXPORT TestMainWindow : public QMainWindow
{
	Q_OBJECT

  public:
	// public operations
	TestMainWindow( QWidget* parent = 0 );
	virtual ~TestMainWindow();

  protected slots:

	  void on__openDialog_clicked();
	  void onTestActionTriggered();
	  void onToolBarActionTriggered();

  protected: 

	Ui::TestMainWindow* _ui; 

};

};

#endif
