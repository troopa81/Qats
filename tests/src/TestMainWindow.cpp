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

#include <QDebug>

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

/*! 
  Constructor
  \param parent parent object
*/
TestMainWindow::TestMainWindow( QWidget* parent )
	: QMainWindow( parent ),
	  _testAction( 0 ),
	  _testSubMenuAction( 0 )
{
	QAction* action = 0; 

	_ui = new Ui::TestMainWindow;
	_ui->setupUi( this );

	initMenuActions();

	_ui->_treeWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
	_ui->_treeWidget->addAction( _testAction );
	_ui->_treeWidget->addAction( _testSubMenuAction );

	_ui->_treeWidgetCustomContextMenu->setContextMenuPolicy(Qt::CustomContextMenu);

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

/*! 
  initialize the different menu actions
*/
void TestMainWindow::initMenuActions()
{
	QAction* action = 0;

	// build tree view ation
	_testAction = new QAction( "Test action", _ui->_treeWidget );
	_testAction->setObjectName( "testAction" );
	connect( _testAction, &QAction::triggered, this, &TestMainWindow::onActionTriggered );

	// build tree view sub menu action
	_testSubMenuAction = new QAction( "Test Submenu action", _ui->_treeWidget );
	_testSubMenuAction->setObjectName( "testSubMenuAction" );

	QMenu* rootMenu = new QMenu;
	_testSubMenuAction->setMenu( rootMenu );

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
}

/*! 
  call whenever a custom menu is request on _treeWidgetCustomContextMenu
*/
void TestMainWindow::on__treeWidgetCustomContextMenu_customContextMenuRequested( const QPoint& pos )
{
	QMenu* menu = new QMenu( _ui->_treeWidgetCustomContextMenu ); 

	menu->addAction( _testAction );
	menu->addAction( _testSubMenuAction );

	menu->popup( _ui->_treeWidgetCustomContextMenu->mapToGlobal( pos ) );
}

}
