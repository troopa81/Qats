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
    name: "GuiTests",

	initTestCase: function() 
	{
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

		qVerify( testLabel.text == "toolBarActionTriggered" ) 
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

		QatsItemView.executeAction( treeWidget, index, [ "testAction" ] );

		dialogLabel = mainWindow.findChild( "_testLabel" );
		qVerify( dialogLabel );

		qCompare( dialogLabel.text, "testActionTriggered" );
	},

	treeWidgetSubMenuAction: function()
	{
		treeWidget = Qats.findGuiObject( "_treeWidget" );
		qVerify( treeWidget );

		index = Qats.getIndexFromPath( treeWidget, [ "foo", "bar", "to.*" ] );
		qVerify( index ); 
		qVerify( index.isValid() );

		QatsItemView.executeAction( treeWidget, index, [ "testSubMenuAction", "France", "Toulouse" ] );

		dialogLabel = Qats.findGuiObject( "_testLabel" );
		qVerify( dialogLabel );

		qCompare( dialogLabel.text, "toulouseActionTriggered" );
	},

	treeWidgetNonBlockingContextMenuAction: function()
	{
		mainWindow = Qats.getMainWindow();
		qVerify( mainWindow );

		treeWidget = mainWindow.findChild( "_treeWidgetCustomContextMenu" );
		qVerify( treeWidget );

		index = Qats.getIndexFromPath( treeWidget, [ "foo", "bar", "to.*" ] );
		qVerify( index && index.isValid() );

		QatsItemView.executeAction( treeWidget, index, [ "testAction" ], false );

		dialogLabel = mainWindow.findChild( "_testLabel" );
		qVerify( dialogLabel );

		qCompare( dialogLabel.text, "testActionTriggered" );
	},

	treeWidgetNonBlockingContextMenuSubMenuAction: function()
	{
		treeWidget = Qats.findGuiObject( "_treeWidgetCustomContextMenu" );
		qVerify( treeWidget );

		index = Qats.getIndexFromPath( treeWidget, [ "foo", "bar", "to.*" ] );
		qVerify( index ); 
		qVerify( index.isValid() );

		QatsItemView.executeAction( treeWidget, index, [ "testSubMenuAction", "France", "Toulouse" ], false );

		dialogLabel = Qats.findGuiObject( "_testLabel" );
		qVerify( dialogLabel );

		qCompare( dialogLabel.text, "toulouseActionTriggered" );
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
