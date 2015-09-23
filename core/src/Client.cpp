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

#include "Client.h"
#include "Test.h"

namespace qats
{

/*!
  Constructor
*/
Client::Client( QObject* parent )
	: QLocalSocket( parent )
{
	qDebug() << "Qats initialization";
	connectToServer( "qats" );

	connect( this, &QIODevice::readyRead, this, &Client::onMessageReceived );
}

/*!
  Destructor
*/
Client::~Client()
{
}

/*!
  Called whenever a message from the server is received
*/
void Client::onMessageReceived()
{
	QDataStream in(this);
    in.setVersion(QDataStream::Qt_4_0);

    QString qatsFilePath;
	QString scriptPath;
    in >> qatsFilePath;
	in >> scriptPath;
	
	Test::get()->setQatsFilePath( qatsFilePath );

	qDebug() << "Execute :" << scriptPath;
	Test::get()->executeTest( scriptPath, 50 );
}


};
