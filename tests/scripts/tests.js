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

var myTest = {
    name: "TestsUseCase",

    initTestCase: function() 
	{
	},

	basicTest: function()
	{
		qWarn( "test" );
		
		var test = "test"; 
		qVerify( test == "test" );

		qCompare( test, "test" );

		qFail( "fail!" );
	},

	dataTest_data: 
	{
		"intVal": [ 6, 1, 3], 
		"str": [ "a", "b", "c" ],
		"double": [1.2, 4.5, 3.7]
	},

	dataTest: function(data)
	{
		switch ( data[ "intVal" ] )
		{
		case 6:
			qCompare( data[ "str" ], "a" );
			qCompare( data[ "double" ], 1.2 );
			break; 
		
		case 1:
			qCompare( data[ "str" ], "b" );
			qCompare( data[ "double" ], 4.5 );
			break; 

		case 3:
			qCompare( data[ "str" ], "c" );
			qCompare( data[ "double" ], 3.7 );
			break; 

		default:
			qFail( "Wrong value!" );
		}
	},

	toolBarAction: function()
	{
		mainWindow = Qats.getMainWindow();
		qVerify( mainWindow );

		testLabel = mainWindow.findChild( "_testLabel" );
		qVerify( testLabel );

		// reset label
		testLabel.text = "";

		toolBarAction = mainWindow.findChild( "toolBarAction" );
		qVerify( toolBarAction );

		Qats.executeActionFromQToolBar( toolBarAction );

		qVerify( testLabel.text == "ToolBarActionTriggered" ) 
	},

	treeWidgetSelect: function()
	{
		mainWindow = Qats.getMainWindow();
		qVerify( mainWindow );
		
		treeWidget = mainWindow.findChild( "_treeWidget" );
		qVerify( treeWidget );

		index = Qats.getIndexFromPath( treeWidget, [ "foo", "bar", "tot.*" ] );
		qVerify( index && index.isValid() );

		Qats.selectFromQAbsractItemView( treeWidget, index );
	},

	treeWidgetAction: function()
	{
		mainWindow = Qats.getMainWindow();
		qVerify( mainWindow );

		treeWidget = mainWindow.findChild( "_treeWidget" );
		qVerify( treeWidget );

		index = Qats.getIndexFromPath( treeWidget, [ "foo", "bar", "to.*" ] );
		qVerify( index && index.isValid() );

		testAction = mainWindow.findChild( "testAction" );
		qVerify( testAction );

		Qats.executeActionFromQAbsractItemView( treeWidget, index, testAction );

		dialogLabel = mainWindow.findChild( "_testLabel" );
		qVerify( dialogLabel );

		qCompare( dialogLabel.text, "ActionTriggered" );
	},

	lineEditTypeText: function()
	{
		mainWindow = Qats.getMainWindow();
		qVerify( mainWindow );
		
		var text = "edition test"; 
		var widgetName = "_lineEdit"; 

		Qats.typeText( mainWindow, widgetName, text );

		editWidget = mainWindow.findChild( widgetName ); 
		qVerify( editWidget );

		qVerify( editWidget.text == text );
	},

	dialogYes : function()
	{
		mainWindow = Qats.getMainWindow();
		qVerify( mainWindow );

		openDialogBtn = mainWindow.findChild( "_openDialog" );
		qVerify( openDialogBtn );

		Qats.delayedAction( Qats.acceptDialog, Qats.activeDialogVisible );

		QTest.mouseClick( openDialogBtn, Qt.LeftButton ); 
	},


	comboBoxSelect: function()
	{
		mainWindow = Qats.getMainWindow();
		qVerify( mainWindow );
		
		var comboBox = mainWindow.findChild( "_comboBox" );
		qVerify( comboBox );

		// TODO try with string instead of index! 
		QatsComboBox.select( comboBox, 2 );
	},

	cleanupTestCase: function() {}
};

Qats.executeTestCase(myTest);