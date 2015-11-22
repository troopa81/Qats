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

#include <QStandardItemModel>
#include <QFileDialog>
#include <QSettings>

#define METHOD_NAME Qt::UserRole + 2

#include "ui_MainWindow.h"
#include "MainWindow.h"
#include "Test.h"
#include "Server.h"
#include "TestCase.h"
#include "TestFunction.h"
#include "Message.h"

namespace qats
{

/*!
  \class qats::MainWindow
  \brief class display test cases and allow to execute them
*/

MainWindow::MainWindow( QWidget* parent )
: QMainWindow( parent )
{
	_ui = new Ui::MainWindow;
	_ui->setupUi( this );

	_model = new QStandardItemModel( this );

	_ui->_testCases->setModel( _model );
	_ui->_testCases->setEditTriggers( QAbstractItemView::NoEditTriggers );

	connect( Server::get(), &Server::outputReceived, this, &MainWindow::onOutputReceived );
	connect( Server::get(), &Server::testedApplicationFinished, this, &MainWindow::onTestedApplicationFinished );

	_outputModel = new QStandardItemModel( _ui->_output );
	_ui->_output->setModel( _outputModel );

	_ui->_startStopBtn->setIcon( QIcon( "icons:start.svg" ) );

	readSettings(); 
}

/*! 
  destructor
*/
MainWindow::~MainWindow()
{
	delete _ui;
}

/*!
  called whenever use doucle click on test Case tree view
 */
void MainWindow::on__testCases_doubleClicked(const QModelIndex & index)
{
	// clear previous content
	_outputModel->clear();
	Server::get()->clear();

	QStandardItem* item = _model->itemFromIndex( index ); 
	QVariant var = item ? item->data() : QVariant(); 

	// get script path
	QString scriptPath = var.toString();
   	if ( scriptPath.isEmpty() ) 
	{
		qWarning() << QString( "Cannot execute test case '%1'" ).arg( item->text() );
		return;
	}

	QByteArray methodName = item->data( METHOD_NAME ).toByteArray(); 
	Server::get()->executeTest( scriptPath );
}

/*! 
  load script directory \param dir
*/ 
void MainWindow::loadScriptDir( const QString& dir )
{
	// display script use case
	QDir scriptDir( dir );
	foreach( QString scriptFileName, scriptDir.entryList( QStringList() << "*.js" ) )
	{
		QStandardItem* item = new QStandardItem( scriptFileName );
		item->setData( scriptDir.absoluteFilePath( scriptFileName ) );				
		
		_model->appendRow( item );
	}
}

/*! 
  called whenever select the load script action has been triggered 
*/
void MainWindow::on__loadScriptDirAction_triggered()
{
	QString dir = QFileDialog::getExistingDirectory( this, tr( "Open scripts directory") );
	if ( dir.isEmpty() )
	{
		return;
	}

	loadScriptDir( dir );

	// insert a new item on top in recent script directories action 
	addRecentScriptDir( dir );
}

/*! 
  called whenever a recent script dir action has been triggered
*/
void MainWindow::onRecentScriptDirActionTriggered()
{
	QAction* action = qobject_cast<QAction*>( sender() ); 
	Q_ASSERT( action );

	loadScriptDir( action->text() );
}

/*! 
  called whenever output from script execution is received
*/
void MainWindow::onOutputReceived( )
{
	int nbColumns = 3; 

	_outputModel->clear();
	_outputModel->setColumnCount( nbColumns );

	QString richOutput; 


	TestCase* testCase = Server::get()->getCurrentTestCase();  
	Message* failedMessage = Server::get()->getFailedMessage();  
	if ( testCase )
	{
		foreach( TestFunction* testFunction, testCase->getTestFunctions() )
		{
			QStandardItem* functionItem = new QStandardItem( testFunction->objectName() );

			// compute icon name according to status
			QString iconName; 
			switch( testFunction->getState() )
			{
			case TestFunction::PASSED: 
				iconName = "succeeded.png"; 
				break; 

			case TestFunction::FAILED: 
				iconName = "failed.png"; 
				break; 

			case TestFunction::RUNNING: 
				iconName = "running.png"; 
				break; 
			}

			functionItem->setIcon( QIcon( "icons:" + iconName ) ); 
			_outputModel->appendRow( functionItem );

			foreach( Message* message, testFunction->getWarnMessages() )
			{
				QStandardItem* warnItem = new QStandardItem( QIcon( "icons:warn.png" ), message->getMessage() );
				functionItem->appendRow( warnItem );

				addBacktraceItems( warnItem, message->getBacktrace() );
			}

			if ( testFunction->getState() == TestFunction::FAILED)
			{
				const Message* message = testFunction->getFailedMessage();
				Q_ASSERT( message );

				QStandardItem* failedItem = new QStandardItem( QIcon("icons:failed.png"), message->getMessage() );
				addBacktraceItems( failedItem, message->getBacktrace() );
				functionItem->appendRow( failedItem );
			}
			else if ( testFunction->getState() == TestFunction::PASSED)
			{
				richOutput += "<font color='green'>OK</font>";
			}

			richOutput += "</p>";
		}
	}
	
	if ( failedMessage )
	{
		QStandardItem* failedItem = new QStandardItem( QIcon("icons:failed.png"), failedMessage->getMessage() );
		addBacktraceItems( failedItem, failedMessage->getBacktrace() );
		_outputModel->appendRow( failedItem );
	}

	// resize columns
	for( int col=0; col<nbColumns; col++ )
	{
		_ui->_output->resizeColumnToContents( col );
	}
}

/*!
  add backtrace item under \param root according to string \param backtrace
*/
void MainWindow::addBacktraceItems( QStandardItem* root, const QString& strBacktrace ) const
{
	QList<Test::BacktraceElt> backtrace = Test::parseBacktrace( strBacktrace );

	// remove 3 first elements and last one because useless
	//for( int i=3; i<backtrace.count()-1; i++ )
	for( int i=0; i<backtrace.count(); i++ )
	{
		Test::BacktraceElt backtraceElt = backtrace.at( i ); 
		QFileInfo fileInfo( backtraceElt._filePath );
		root->appendRow( QList<QStandardItem*>() << new QStandardItem( fileInfo.fileName() )
						 << new QStandardItem( QString::number( backtraceElt._lineNumber ) )
						 << new QStandardItem( Test::getLineFromFile( fileInfo.absoluteFilePath(), backtraceElt._lineNumber ) ) );
	}
}

/*! 
  called whenever the startStop button is clicked. start or stop the current tested application
  according to either it's started or not
*/
void MainWindow::on__startStopBtn_clicked()
{
	if ( Server::get()->isStartedTestedApplication() )
	{
		Server::get()->closeTestedApplication(); 
	}
	else
	{
		QString command = _ui->_testedApplicationCmb->currentText(); 
		bool ok = Server::get()->startTestedApplication( command, QStringList() ); 

		// add item to the combo box or move it to first place if already existing
		if ( ok )
		{
			for( int i=0; i<_ui->_testedApplicationCmb->count(); i++ )
			{
				if ( command == _ui->_testedApplicationCmb->itemText( i ) )
				{
					_ui->_testedApplicationCmb->removeItem( i ); 
					break; 
				}
			}

			_ui->_testedApplicationCmb->insertItem( 0, command );
		}

		// update combo current text
		_ui->_testedApplicationCmb->setCurrentText( QString( "%1 [%2]" ).arg( command ).arg( Server::get()->getTestedApplicationPid() ) );
	}

	_ui->_startStopBtn->setIcon( QIcon( Server::get()->isStartedTestedApplication() ? "icons:stop.svg" : "icons:start.svg" ) );
	_ui->_testedApplicationCmb->setEnabled( !Server::get()->isStartedTestedApplication() );
}

/*!
  read settings and initialize main window
*/
void MainWindow::readSettings()
{
	QSettings settings;

	// recent directories
	foreach( QString dir, settings.value( "recentScriptDirs" ).toStringList() )
	{
		if ( QDir( dir ).exists() )
		{
			addRecentScriptDir( dir );
		}
	}
	
	// tested application 
	int size = settings.beginReadArray( "testedApplications" );
	for (int i = 0; i < size; ++i) 
	{
		settings.setArrayIndex(i);
		_ui->_testedApplicationCmb->addItem( settings.value( "command" ).toString() );
	}

	settings.endArray();
} 

/*!
  update settings according to current value from the main windowg
*/
void MainWindow::writeSettings()
{
	QSettings settings;
	
	// recent directories
	QStringList recentDirs; 
	foreach( QAction* action, _ui->_recentScriptDirsAction->menu()->actions() )
	{
		recentDirs.append( action->text() );
	}
	settings.setValue( "recentScriptDirs", recentDirs );

	// tested application
	settings.beginWriteArray( "testedApplications" );
	for (int i = 0; i < _ui->_testedApplicationCmb->count(); ++i) 
	{
		settings.setArrayIndex(i);
		settings.setValue( "command", _ui->_testedApplicationCmb->itemText( i ) );
	}

	settings.endArray();
}

/*! 
  \overlaoded
*/
void MainWindow::closeEvent(QCloseEvent *event)
{
	writeSettings();
	QMainWindow::closeEvent( event );
}

/*! 
  add recent script dir \param dir to open recent script dir action menu
  \param first true if it has to be added before all other action
*/
void MainWindow::addRecentScriptDir( const QString& dir, bool first )
{
	// insert a new item on top in recent script directories action 
	QMenu* menu = _ui->_recentScriptDirsAction->menu(); 
	if ( !menu )
	{
		menu = new QMenu( this );
		_ui->_recentScriptDirsAction->setMenu( menu );
	}

	QAction* action = new QAction( dir, this ); 
	connect( action, &QAction::triggered, this, &MainWindow::onRecentScriptDirActionTriggered );

	// check that dir doesn't already exists in the list
	foreach( QAction* action, menu->actions() )
	{
		// TODO up action in the list instead of simply remove it 
		if ( action->text() == dir )
		{
			return; 
		}
	}

	menu->insertAction( first && menu->actions().count() ? menu->actions().first() : 0, action ); 
}

/*! 
  called whenever tested application has finished
*/
void MainWindow::onTestedApplicationFinished()
{
	_ui->_startStopBtn->setIcon( QIcon( "icons:start.svg" ) );
	_ui->_testedApplicationCmb->setEnabled( true );
	_ui->_testedApplicationCmb->setCurrentText( _ui->_testedApplicationCmb->count() ? _ui->_testedApplicationCmb->itemText( 0 ) : "" );
}

}
