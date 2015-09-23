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
// #include "QElapsedTimerPrototype.h"
//#include "QContextMenuEventPrototype.h"

QScriptValue qTimerConstructor(QScriptContext *context,
							   QScriptEngine *engine)
{
    QObject *parent = context->argument(0).toQObject();
    QTimer *timer = new QTimer(parent);
    return engine->newQObject(timer, QScriptEngine::ScriptOwnership);
}


// QScriptValue qElapsedTimerConstructor(QScriptContext *context,
// 									  QScriptEngine *engine)
// {
//     QElapsedTimer *timer = new QElapsedTimer;
//     return engine->newQObject(timer, QScriptEngine::ScriptOwnership);
// }

// QScriptValue qContextMenuEventConstructor(QScriptContext *context, QScriptEngine *engine)
// {
// 	if (context->isCalledAsConstructor()) {
//         // initialize the new object


// 		QContextMenuEvent *object = qscriptvalue_cast<QContextMenuEvent*>(context->thisObject());

// 		qDebug() << "object=" << object << ",";

//         // ...
//         // return a non-object value to indicate that the
//         // thisObject() should be the result of the "new Foo()" expression
//         return engine->undefinedValue();
//     } 

// 	return QScriptValue(); 
// }

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

	Test::get()->_scriptEngine = new QScriptEngine();

	qScriptRegisterSequenceMetaType< QWidgetList >(Test::get()->_scriptEngine);
	qScriptRegisterSequenceMetaType< QObjectList >(Test::get()->_scriptEngine);
	qScriptRegisterSequenceMetaType< QModelIndexList >(Test::get()->_scriptEngine);


	QScriptValue scriptTestObject = Test::get()->_scriptEngine->newQObject(Test::get());
	Test::get()->_scriptEngine->globalObject().setProperty("Qats", scriptTestObject);

	// TODO : no idea why we need this line => for enums ?
	Test::get()->_scriptEngine->globalObject().setProperty("Qt", Test::get()->_scriptEngine->newQMetaObject(&QObject::staticMetaObject));
	Test::get()->_scriptEngine->globalObject().setProperty("QMessageBox", Test::get()->_scriptEngine->newQMetaObject(&QMessageBox::staticMetaObject));
	Test::get()->_scriptEngine->globalObject().setProperty("QEventLoop", Test::get()->_scriptEngine->newQMetaObject(&QEventLoop::staticMetaObject));
	Test::get()->_scriptEngine->globalObject().setProperty("TestEnums", Test::get()->_scriptEngine->newQMetaObject(&Test::staticMetaObject));

//	Test::get()->_scriptEngine->globalObject().setProperty("QApplication", Test::get()->_scriptEngine->newQObject(QApplication::instance()));


	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QLineEdit*>(), Test::get()->_scriptEngine->newQObject(new QLineEditPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QTreeView*>(), Test::get()->_scriptEngine->newQObject(new QTreeViewPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QAbstractItemView*>(), Test::get()->_scriptEngine->newQObject(new QAbstractItemViewPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QAbstractItemModel*>(), Test::get()->_scriptEngine->newQObject(new QAbstractItemModelPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QModelIndex*>(), Test::get()->_scriptEngine->newQObject(new QModelIndexPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QModelIndex>(), Test::get()->_scriptEngine->newQObject(new QModelIndexPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QWidget*>(), Test::get()->_scriptEngine->newQObject(new QWidgetPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QMetaObject*>(), Test::get()->_scriptEngine->newQObject(new MetaObjectPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QMetaProperty*>(), Test::get()->_scriptEngine->newQObject(new QMetaPropertyPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QMetaProperty>(), Test::get()->_scriptEngine->newQObject(new QMetaPropertyPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QObject*>(), Test::get()->_scriptEngine->newQObject(new QObjectPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QTimer*>(), Test::get()->_scriptEngine->newQObject(new QTimerPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QToolBar*>(), Test::get()->_scriptEngine->newQObject(new QToolBarPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QRect*>(), Test::get()->_scriptEngine->newQObject(new QRectPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QRect>(), Test::get()->_scriptEngine->newQObject(new QRectPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QPoint*>(), Test::get()->_scriptEngine->newQObject(new QPointPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QPoint>(), Test::get()->_scriptEngine->newQObject(new QPointPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QItemSelectionModel*>(), Test::get()->_scriptEngine->newQObject(new QItemSelectionModelPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QAbstractScrollArea*>(), Test::get()->_scriptEngine->newQObject(new QAbstractScrollAreaPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QCoreApplication*>(), Test::get()->_scriptEngine->newQObject(new QCoreApplicationPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QMenu*>(), Test::get()->_scriptEngine->newQObject(new QMenuPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QComboBox*>(), Test::get()->_scriptEngine->newQObject(new QComboBoxPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QScrollBar*>(), Test::get()->_scriptEngine->newQObject(new QScrollBarPrototype) );
	Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QFrame*>(), Test::get()->_scriptEngine->newQObject(new QFramePrototype) );

	// Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QElaspedTimer*>(), Test::get()->_scriptEngine->newQObject(new QElapsedTimerPrototype) );
	//Test::get()->_scriptEngine->setDefaultPrototype(qMetaTypeId<QContextMenuEvent*>(), Test::get()->_scriptEngine->newQObject(new QContextMenuEventPrototype) );

	// Test::get()->_scriptEngine->globalObject().setProperty("QContextMenuEvent", Test::get()->_scriptEngine->newFunction(qContextMenuEventConstructor, Test::get()->_scriptEngine->newQObject(new QContextMenuEventPrototype)));

    QScriptValue ctor = Test::get()->_scriptEngine->newFunction(qTimerConstructor);
    QScriptValue metaObject = Test::get()->_scriptEngine->newQMetaObject(&QTimer::staticMetaObject, ctor);
    Test::get()->_scriptEngine->globalObject().setProperty("QTimer", metaObject);

	// ctor = Test::get()->_scriptEngine->newFunction(qElapsedTimerConstructor);
    // metaObject = Test::get()->_scriptEngine->newQMetaObject(&QElapsedTimer::staticMetaObject, ctor);
    // Test::get()->_scriptEngine->globalObject().setProperty("QElapsedTimer", metaObject);

	Test::get()->_scriptEngine->globalObject().setProperty("QTest", Test::get()->_scriptEngine->newQObject(new QTestPrototype));

	Test::get()->_scriptEngine->globalObject().setProperty("QApplication", Test::get()->_scriptEngine->newQObject(new QApplicationPrototype));

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
					 << QString( "%1:%2" ).arg( fileName ).arg( _scriptEngine->uncaughtExceptionLineNumber() ) );
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
	//set ScriptContext
    QScriptContext *context = _scriptEngine->currentContext();
    QScriptContext *parent= context->parentContext();
    if(parent!=0)
    {
        context->setActivationObject(context->parentContext()->activationObject());
        context->setThisObject(context->parentContext()->thisObject());
    }

	if ( !evaluateScript( _scriptDir.absoluteFilePath( scriptFile ) ) )
	{
		// TODO : backtrace won't display in MainWindow because we squeeze 3 first one and last one
		sendMessage( FAIL, QStringList() << QString( "Cannot include file '%1'" ).arg( scriptFile )
					 << getBacktrace() );
	}
}

}
