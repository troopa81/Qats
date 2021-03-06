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

#ifndef QATS_TEST_H
#define QATS_TEST_H

#include <QTableView>
#include <QTreeView>
#include <QMenu>
#include <QDockWidget>
#include <QMessageBox>
#include <QComboBox>
#include <QScriptable>
#include <QScriptEngine>
#include <QToolBar>
#include <QMainWindow>
#include <QDir>

namespace qats
{

class Client;
class Test : public QObject, QScriptable
{
	Q_OBJECT

	Q_ENUMS(Qt::ItemDataRole);

public:

	enum MessageType
	{
		WARN, 
		FAIL, 
		FUNCTION_START,
		FUNCTION_PASS,
		TESTCASE_START,
		TESTCASE_END
	}; 
	Q_ENUMS(MessageType);


	struct BacktraceElt
	{
		QString _function;
		QString _args;
		QString _filePath; 
		int _lineNumber;
	
	BacktraceElt():_lineNumber(-1){}
	};

	int executeTest(const QString& scriptFilePath, int delay = 0 );
	
	void setQatsFilePath( const QString& qatsDirPath ); 
	QString getQatsFilePath() const;
	static QList<BacktraceElt> parseBacktrace( const QString& backtrace );
	static QString getLineFromFile( const QString& filePath, int line );

	Client* _client; 

public slots:

	static Test* get();
	
	void sendMessage( MessageType type, QStringList content );
	QStringList getBacktrace(); 
	void include( const QString& scriptFile );
	QString getCurrentScriptFile() const; 
	QString getCurrentScriptDir() const; 

protected:

	Test();
	~Test(){};

	bool evaluateScript( const QString& filename );

	QScriptEngine* _scriptEngine;
	QString _qatsFilePath;
	QDir _scriptDir;

	int   _delay;
	static Test* s_instance;
}; 

}; 


#endif
