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

#include <iostream>

#include <QTest>
#include <QToolButton>
#include <QLineEdit>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QDialog>
#include <QTreeView>
#include <QContextMenuEvent>
#include <QMenuBar>
#include <QMessageBox>
#include <QComboBox>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QLineEdit>
#include <QFileDialog>
#include <QSpinBox>
#include <QDesktopWidget>
#include <QElapsedTimer>
#include <QScriptEngine>
#include <QMainWindow>
#include <QToolBar>
#include <QCheckBox>
#include <QStaticAssertFailure>
#include <QScriptContextInfo>

#include "Test.h"
#include "Client.h"
#include "QLineEditPrototype.h"
#include "MetaObjectPrototype.h"
#include "QTestPrototype.h"
#include "QMetaPropertyPrototype.h"
#include "QApplicationPrototype.h"
#include "QWidgetPrototype.h"
#include "QTreeViewPrototype.h"
#include "QAbstractItemViewPrototype.h"
#include "QAbstractItemModelPrototype.h"
#include "QModelIndexPrototype.h"
#include "QObjectPrototype.h"
#include "QToolBarPrototype.h"
#include "QRectPrototype.h"
#include "QPointPrototype.h"
#include "QItemSelectionModelPrototype.h"
#include "QAbstractScrollAreaPrototype.h"
#include "QTimerPrototype.h"
#include "QMenuPrototype.h"
#include "QComboBoxPrototype.h"
#include "QScrollBarPrototype.h"
#include "QFramePrototype.h"
#include "QActionPrototype.h"
#include "QFilePrototype.h"
#include "QMessageBoxPrototype.h"
#include "QDialogPrototype.h"
#include "QAbstractButtonPrototype.h"
// #include "QElapsedTimerPrototype.h"
//#include "QContextMenuEventPrototype.h"

QScriptValue qTimerConstructor(QScriptContext *context,
							   QScriptEngine *engine)
{
    QObject *parent = context->argument(0).toQObject();
    QTimer *timer = new QTimer(parent);
    return engine->newQObject(timer, QScriptEngine::ScriptOwnership);
}

namespace qats
{

Test* Test::s_instance = 0;

/*!
  \class qats::Test
  \brief Provides helper method to test application
*/

/*!
  \return test instance
*/
Test* Test::get()
{
	if ( !s_instance ) 
	{
		s_instance = new Test();
	}

	return s_instance;
}

/*!
	Constructor
*/
Test::Test()
	: _delay( 50 )
{
}

/*!
  execute given \param scriptFilePath
*/
int Test::executeTest(const QString& scriptFilePath, int delay )
{
	// TODO better management of delay
	_delay = delay; 
	if ( !qputenv("QTEST_EVENT_DELAY", QByteArray::number( _delay ) ) )
	{
		qDebug() << "Could not set environment variable 'QTEST_EVENT_DELAY'";
	}

	// register enum as int because they are treated as int in javascript
	// TODO iterate over all enum to to do the same
	// TODO register only one somewhere...
	qRegisterMetaType<int>("Qt::MouseButton");
	qRegisterMetaType<int>("Qt::Key");
	qRegisterMetaType<int>("QMessageBox::StandardButton");
	qRegisterMetaType<int>("Qt::KeyboardModifiers");
	qRegisterMetaType<int>("QEventLoop::ProcessEventsFlag");
	qRegisterMetaType<Qt::MatchFlags>("Qt::MatchFlags");
	
	qRegisterMetaType< QWidgetList >("QWidgetList");
	qRegisterMetaType< QObjectList >("QObjectList");
	qRegisterMetaType< QModelIndex >("QModelIndex");
	qRegisterMetaType< QModelIndexList >("QModelIndexList");

	_scriptEngine = new QScriptEngine();

	QIODevicePrototype::registerToScriptEngine( _scriptEngine );
	QFileDevicePrototype::registerToScriptEngine( _scriptEngine );
	QFilePrototype::registerToScriptEngine( _scriptEngine );
	QMessageBoxPrototype::registerToScriptEngine( _scriptEngine );
	QDialogPrototype::registerToScriptEngine( _scriptEngine );
	QAbstractButtonPrototype::registerToScriptEngine( _scriptEngine );

	qScriptRegisterSequenceMetaType< QWidgetList >(_scriptEngine);
	qScriptRegisterSequenceMetaType< QObjectList >(_scriptEngine);
	qScriptRegisterSequenceMetaType< QModelIndexList >(_scriptEngine);
	qScriptRegisterSequenceMetaType< QList<QAction*> >(_scriptEngine);


	QScriptValue scriptTestObject = _scriptEngine->newQObject(Test::get());
	_scriptEngine->globalObject().setProperty("Qats", scriptTestObject);

	// TODO : no idea why we need this line => for enums ?
	_scriptEngine->globalObject().setProperty("Qt", _scriptEngine->newQMetaObject(&QObject::staticMetaObject));
	_scriptEngine->globalObject().setProperty("QMessageBox", _scriptEngine->newQMetaObject(&QMessageBox::staticMetaObject));
	_scriptEngine->globalObject().setProperty("QEventLoop", _scriptEngine->newQMetaObject(&QEventLoop::staticMetaObject));
	_scriptEngine->globalObject().setProperty("TestEnums", _scriptEngine->newQMetaObject(&Test::staticMetaObject));

//	_scriptEngine->globalObject().setProperty("QApplication", _scriptEngine->newQObject(QApplication::instance()));


	_scriptEngine->setDefaultPrototype(qMetaTypeId<QLineEdit*>(), _scriptEngine->newQObject(new QLineEditPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QTreeView*>(), _scriptEngine->newQObject(new QTreeViewPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QAbstractItemView*>(), _scriptEngine->newQObject(new QAbstractItemViewPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QAbstractItemModel*>(), _scriptEngine->newQObject(new QAbstractItemModelPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QModelIndex*>(), _scriptEngine->newQObject(new QModelIndexPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QModelIndex>(), _scriptEngine->newQObject(new QModelIndexPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QWidget*>(), _scriptEngine->newQObject(new QWidgetPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QMetaObject*>(), _scriptEngine->newQObject(new MetaObjectPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QMetaProperty*>(), _scriptEngine->newQObject(new QMetaPropertyPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QMetaProperty>(), _scriptEngine->newQObject(new QMetaPropertyPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QObject*>(), _scriptEngine->newQObject(new QObjectPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QTimer*>(), _scriptEngine->newQObject(new QTimerPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QToolBar*>(), _scriptEngine->newQObject(new QToolBarPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QRect*>(), _scriptEngine->newQObject(new QRectPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QRect>(), _scriptEngine->newQObject(new QRectPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QPoint*>(), _scriptEngine->newQObject(new QPointPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QPoint>(), _scriptEngine->newQObject(new QPointPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QItemSelectionModel*>(), _scriptEngine->newQObject(new QItemSelectionModelPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QAbstractScrollArea*>(), _scriptEngine->newQObject(new QAbstractScrollAreaPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QCoreApplication*>(), _scriptEngine->newQObject(new QCoreApplicationPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QMenu*>(), _scriptEngine->newQObject(new QMenuPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QComboBox*>(), _scriptEngine->newQObject(new QComboBoxPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QScrollBar*>(), _scriptEngine->newQObject(new QScrollBarPrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QFrame*>(), _scriptEngine->newQObject(new QFramePrototype) );
	_scriptEngine->setDefaultPrototype(qMetaTypeId<QAction*>(), _scriptEngine->newQObject(new QActionPrototype) );

	// _scriptEngine->setDefaultPrototype(qMetaTypeId<QElaspedTimer*>(), _scriptEngine->newQObject(new QElapsedTimerPrototype) );
	//_scriptEngine->setDefaultPrototype(qMetaTypeId<QContextMenuEvent*>(), _scriptEngine->newQObject(new QContextMenuEventPrototype) );

	// _scriptEngine->globalObject().setProperty("QContextMenuEvent", _scriptEngine->newFunction(qContextMenuEventConstructor, _scriptEngine->newQObject(new QContextMenuEventPrototype)));

    QScriptValue ctor = _scriptEngine->newFunction(qTimerConstructor);
    QScriptValue metaObject = _scriptEngine->newQMetaObject(&QTimer::staticMetaObject, ctor);
    _scriptEngine->globalObject().setProperty("QTimer", metaObject);

	// ctor = _scriptEngine->newFunction(qElapsedTimerConstructor);
    // metaObject = _scriptEngine->newQMetaObject(&QElapsedTimer::staticMetaObject, ctor);
    // _scriptEngine->globalObject().setProperty("QElapsedTimer", metaObject);

	_scriptEngine->globalObject().setProperty("QTest", _scriptEngine->newQObject(new QTestPrototype));

	_scriptEngine->globalObject().setProperty("QApplication", _scriptEngine->newQObject(new QApplicationPrototype));

	if ( !evaluateScript( _qatsFilePath ) )
	{
		return -1;
	}

	_scriptDir = QFileInfo( scriptFilePath ).dir();
	if ( !evaluateScript( scriptFilePath ) )
	{
		return -1;
	}

	return 0;
}

/*! 
  evaluate script \param filename and \return true if evaluation is OK
  \param scriptEngine the engine script in charge of evaluation
*/
bool Test::evaluateScript( const QString& fileName )
{
	// open file
	QFile scriptFile( fileName );
	if (!scriptFile.open(QIODevice::ReadOnly))
	{
		qWarning() << "Cannot open file '" << fileName << "'";
		return false; 
	}

    //load file
	QTextStream stream( &scriptFile );
	QString contents = stream.readAll();
	scriptFile.close();
	QScriptValue scriptValue = _scriptEngine->evaluate( contents, fileName );
	if ( scriptValue.isError() )
	{
		sendMessage( FAIL, QStringList() << QString( "Error while script evaluation '%1'" ).arg( scriptValue.toString() )
					 // TODO : backtrace won't display in MainWindow because we squeeze 3 first one and last one
					 << QString( "() at %1:%2" ).arg( fileName ).arg( _scriptEngine->uncaughtExceptionLineNumber() ) );
		return false;
	}

	return true;
}

/*! 
  \return current script backtrace
 */ 
QStringList Test::getBacktrace()
{
	return _scriptEngine->currentContext()->backtrace();
}

void Test::sendMessage( Test::MessageType type, QStringList content )
{
	QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
	out << type;

	foreach( QString elt, content )
	{
		out << elt;
	}

	Test::get()->_client->write( block );
	Test::get()->_client->flush();
}

/*! 
  \return qats script file path
*/
QString Test::getQatsFilePath() const
{
	return _qatsFilePath;
}

/*!
  set qats script file path 
  \param qatsFilePath qats script file path
 */
void Test::setQatsFilePath( const QString& qatsFilePath )
{
	_qatsFilePath = qatsFilePath;
}

/*!
  parse and \return backtrace according to string \param strBacktrace
*/
QList<Test::BacktraceElt> Test::parseBacktrace( const QString& strBacktrace )
{
	QRegularExpression re( "([^\\(]*)\\(([^\\)]*)\\) at ([^,]*),{0,1}" );
	QRegularExpressionMatchIterator itMatch = re.globalMatch( strBacktrace );
	QList<Test::BacktraceElt> backtrace;
	while( itMatch.hasNext() )
	{
		QRegularExpressionMatch match = itMatch.next();

		BacktraceElt backtraceElt; 
		backtraceElt._function = match.captured( 1 ); 
		backtraceElt._args = match.captured( 2 ); 

		QStringList fileLoc = match.captured( 3 ).split(":");
		backtraceElt._filePath = fileLoc.count() ? fileLoc.first() : QString(); 
		backtraceElt._lineNumber = fileLoc.count() > 1 ? fileLoc.at( 1 ).toInt() : -1;

		backtrace.prepend( backtraceElt );
	}

	return backtrace;
}

/*!
  \return line content from \param filePath at \param line
*/
QString Test::getLineFromFile( const QString& filePath, int line )
{
	QFile file( filePath );
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return tr( "Error: Cannot open '%1' file" ).arg( filePath );
	}
	
	QString lineContent = tr("Error: There is no line '%1' in file '%2'").arg( line ).arg( filePath );
	int i = 0;
	while(!file.atEnd() && i != line)
	{
		lineContent = file.readLine();
		i++;
	}

	return lineContent.trimmed();
}

/*! 
  include \param scriptFile into currently executed script file
  included script file is relative to currenly executed script file
*/
void Test::include( const QString& scriptFile )
{
	// share parent context with current context
    QScriptContext* context = _scriptEngine->currentContext();
    QScriptContext* parent = context->parentContext();
    if( parent )
    {
        context->setActivationObject( parent->activationObject() );
        context->setThisObject( parent->thisObject() );
    }

	if ( !evaluateScript( _scriptDir.absoluteFilePath( scriptFile ) ) )
	{
		// TODO : backtrace won't display in MainWindow because we squeeze 3 first one and last one
		sendMessage( FAIL, QStringList() << QString( "Cannot include file '%1'" ).arg( scriptFile )
					 << getBacktrace() );
	}
}

/*! 
  \return the current script filename
*/
QString Test::getCurrentScriptFile() const 
{
	// get parent context (current one is the native one)
	QScriptContext* parentContext = _scriptEngine->currentContext()->parentContext(); 

	return parentContext ? QScriptContextInfo( parentContext ).fileName() : QString();
}

/*! 
  \return the current script directory
*/
QString Test::getCurrentScriptDir() const
{
	return QFileInfo( getCurrentScriptFile() ).absolutePath();
}

}
