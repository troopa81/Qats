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

	// build tree view ation
	QAction* action = new QAction( "Test action", _ui->_treeWidget );
	action->setObjectName( "testAction" );
	_ui->_treeWidget->addAction( action );
	connect( action, &QAction::triggered, this, &TestMainWindow::onActionTriggered );

	// build tree view sub menu action
	action = new QAction( "Test Submenu action", _ui->_treeWidget );
	action->setObjectName( "testSubMenuAction" );
	_ui->_treeWidget->addAction( action );

	QMenu* rootMenu = new QMenu;
	action->setMenu( rootMenu );

	action = rootMenu->addAction( "Spain" );
	QMenu* menu = new QMenu; 
	action->setMenu( menu ); 
	menu->addAction( "Madrid" );
	menu->addAction( "Barcelone" );
	menu->addAction( "Bilbao" );

	action = rootMenu->addAction( "England" );
	menu = new QMenu; 
	action->setMenu( menu ); 
	menu->addAction( "London" );
	menu->addAction( "Manchester" );
	menu->addAction( "Liverpool" );

	action = rootMenu->addAction( "France" );
	menu = new QMenu; 
	action->setMenu( menu ); 
	menu->addAction( "Marseille" );
	menu->addAction( "Paris" );
	action = menu->addAction( "Toulouse" );
	action->setObjectName( "toulouseAction" );
	connect( action, &QAction::triggered, this, &TestMainWindow::onActionTriggered );

	// build tool bar action
	action = new QAction( "ToolBar Action", _ui->_toolBar );
	action->setObjectName( "toolBarAction" ); 
	_ui->_toolBar->addAction( action );
	connect( action, &QAction::triggered, this, &TestMainWindow::onActionTriggered );
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
  call whenever an action has been triggered
*/
void TestMainWindow::onActionTriggered()
{
	_ui->_testLabel->setText( sender()->objectName() + "Triggered" );
}

}
