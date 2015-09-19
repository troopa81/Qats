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

#include <QMessageBox>
#include <QAction>

#include "ui_TestMainWindow.h"
#include "TestMainWindow.h"

namespace qats
{

/*!
  \class qats::TestMainWindow
  \brief This class is used for testing the Qats application
*/

TestMainWindow::TestMainWindow( QWidget* parent )
: QMainWindow( parent )
{
	_ui = new Ui::TestMainWindow;
	_ui->setupUi( this );

	_ui->_treeWidget->setContextMenuPolicy(Qt::ActionsContextMenu);

	QAction* testAction = new QAction( "Test action", _ui->_treeWidget );
	testAction->setObjectName( "testAction" );
	_ui->_treeWidget->addAction( testAction );
	connect( testAction, &QAction::triggered, this, &TestMainWindow::onTestActionTriggered );

	QAction* toolBarAction = new QAction( "ToolBar Action", _ui->_toolBar );
	toolBarAction->setObjectName( "toolBarAction" ); 
	_ui->_toolBar->addAction( toolBarAction );
	connect( toolBarAction, &QAction::triggered, this, &TestMainWindow::onToolBarActionTriggered );
}

/*! 
  destructor
*/
TestMainWindow::~TestMainWindow()
{
	delete _ui;
}

/*! 
  called whenever open dialog button has been clicked
*/
void TestMainWindow::on__openDialog_clicked()
{
	QMessageBox::StandardButton res = QMessageBox::question( this, "test dialog", "Answer the question" );

	_ui->_testLabel->setText( res == QMessageBox::Yes ? "DialogYes" : "DialogNo" );
}

/*! 
  called whenever test action is triggered
*/
void TestMainWindow::onTestActionTriggered()
{
	_ui->_testLabel->setText( "ActionTriggered" );
}

/*! 
  called whenever tool bar action has been triggered
*/
void TestMainWindow::onToolBarActionTriggered()
{
	_ui->_testLabel->setText( "ToolBarActionTriggered" );
}

}
