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
    name: "ItemViewTests",

	initTestCase: function() 
	{
	},

	select: function()
	{
		mainWindow = Qats.getMainWindow();
		qVerify( mainWindow );
		
		treeWidget = mainWindow.findChild( "_treeWidget" );
		qVerify( treeWidget );

		index = Qats.getIndexFromPath( treeWidget, [ "foo", "bar", "tot.*" ] );
		qVerify( index && index.isValid() );

		Qats.selectFromQAbsractItemView( treeWidget, index );
	},

	action: function()
	{
		mainWindow = Qats.getMainWindow();
		qVerify( mainWindow );

		treeWidget = mainWindow.findChild( "_treeWidget" );
		qVerify( treeWidget );

		index = Qats.getIndexFromPath( treeWidget, [ "foo", "bar", "to.*" ] );
		qVerify( index && index.isValid() );

		QatsItemView.executeAction( treeWidget, index, "testAction" );

		dialogLabel = mainWindow.findChild( "_testLabel" );
		qVerify( dialogLabel );

		qCompare( dialogLabel.text, "testActionTriggered" );
	},

	subMenuAction: function()
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

	nonBlockingContextMenuAction: function()
	{
		mainWindow = Qats.getMainWindow();
		qVerify( mainWindow );

		treeWidget = mainWindow.findChild( "_treeWidgetCustomContextMenu" );
		qVerify( treeWidget );

		index = Qats.getIndexFromPath( treeWidget, [ "foo", "bar", "to.*" ] );
		qVerify( index && index.isValid() );

		QatsItemView.executeAction( treeWidget, index, "testAction", false );

		dialogLabel = mainWindow.findChild( "_testLabel" );
		qVerify( dialogLabel );

		qCompare( dialogLabel.text, "testActionTriggered" );
	},

	nonBlockingContextMenuSubMenuAction: function()
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

	blockingMenuDialogAction: function()
	{
		treeWidget = Qats.findGuiObject( "_treeWidget" );
		qVerify( treeWidget );

		index = Qats.getIndexFromPath( treeWidget, [ "foo", "bar", "to.*" ] );
		qVerify( index ); 
		qVerify( index.isValid() );

		Qats.delayedAction( Qats.acceptDialog, Qats.activeDialogVisible );

		QatsItemView.executeAction( treeWidget, index, "dialogAction" );

		dialogLabel = Qats.findGuiObject( "_testLabel" );
		qVerify( dialogLabel );

		qCompare( dialogLabel.text, "dialogActionTriggered" );
	},

	nonBlockingMenuDialogAction: function()
	{
		treeWidget = Qats.findGuiObject( "_treeWidgetCustomContextMenu" );
		qVerify( treeWidget );

		index = Qats.getIndexFromPath( treeWidget, [ "foo", "bar", "to.*" ] );
		qVerify( index ); 
		qVerify( index.isValid() );

		Qats.delayedAction( Qats.acceptDialog, Qats.activeDialogVisible );

		QatsItemView.executeAction( treeWidget, index, "dialogAction", false );

		dialogLabel = Qats.findGuiObject( "_testLabel" );
		qVerify( dialogLabel );

		qCompare( dialogLabel.text, "dialogActionTriggered" );
	},
		
	cleanupTestCase: function() {}
};

Qats.executeTestCase(myTest);
