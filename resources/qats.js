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

function qCompare(actual, expected) {
    if (actual != expected) {
		qFail( "Compare failed \n  Actual    : " + actual + "\n  Expected  : " + expected );
    }
}

function qVerify(condition, message) {
    if (!(condition)) {
		qFail( "Verify failed" + ( message ? " : " + message : "" ) );
	}
}

function qFail(message) {
	Qats.sendMessage( TestEnums.FAIL, [ message, Qats.getBacktrace() ] );

	// throw error to interrupt script
    var err = new Error();
    err.name = "QatsFailure";
    throw err;
}

function qWarn(message) {
	Qats.sendMessage( TestEnums.WARN, [ message, Qats.getBacktrace() ] );
}

function qCompareFile(file1, file2)
{
	// TODO enum not declared with Q_ENUM are not defined in javascript
	QIODevice.ReadOnly = 1; 

	f1 = new QFile();
	f1.setFileName( file1 );
	qVerify( f1.open( QIODevice.ReadOnly ), "Cannot open file '" + file1 + "'" ); 

	f2 = new QFile();
	f2.setFileName( file2 );
	qVerify( f2.open( QIODevice.ReadOnly ), "Cannot open file '" + file2 + "'" ); 

	qVerify( f1.readAll() == f2.readAll(), "'" + file1 + "' and '" + file2 + "' are different" );
}

Qats.executeTestCase = function(testcase) {

	Qats.sendMessage( TestEnums.TESTCASE_START, [ testcase['name'] ] );

    if (!Qats._executeTestFunction(testcase, "initTestCase")) 
	{
		return; 
	}

    for (var fn in testcase) 
	{
        if ( typeof testcase[fn] == "function" 
			 && fn != "initTestCase" && fn != "cleanupTestCase"
			 && !/.*_data$/.test( "fn"  ) )
		{
			Qats._executeTestFunction(testcase, fn);
        }
    }

    Qats._executeTestFunction(testcase, "cleanupTestCase");

	Qats.sendMessage( TestEnums.TESTCASE_END, [ ] );
}

Qats._prepareData = function( data )
{
	result = []
	
	// if no data return an element with one row to be sure function will be executed
	if ( data == undefined )
	{
		return [ {"" : null} ],
	}

	// compute rows number
	var nbRows = -1;
    for (var elt in data) 
	{
		if ( nbRows != -1 && nbRows != data[elt].length )
		{
			qFail( "Error with function data consistency, number of rows differs" );
		}
		else
		{
			nbRows = data[elt].length; 
		}
	}

	if ( nbRows == -1 )
	{
		qFail( "Error with function data consistency, no rows defined" );
	}

	// build array of dict
	for( var i=0; i<nbRows; i++ )
	{
		var dict = {};
		for (var elt in data)
		{
			dict[ elt ] = data[elt][i];
		}
		result.push( dict );
	}

	return result
}

Qats._executeTestFunction = function(testcase, fn) {

    var func = testcase[fn];

    var data = testcase[fn + "_data"];

	// special case : data is a function
    if (typeof data == "function")
	{
        data = data.apply(testcase);
	}

	// prepare data
	try 
	{
		data = Qats._prepareData( data );
	} catch (e) {
		if ((typeof e != "object") || (e.name != "QatsFailure"))
			throw e;
		return false;
	}

	Qats.sendMessage( TestEnums.FUNCTION_START, [ fn ] );
    
    var passed = true;
    for (var i=0; i<data.length; i++) 
	{
		// execute function
        try {
            func.apply(testcase, [ data[i] ] );
        } catch (e) {
            if ((typeof e != "object") || (e.name != "QatsFailure"))
                throw e;

            passed = false;
        }
    }

    if (passed) 
	{
		Qats.sendMessage( TestEnums.FUNCTION_PASS, [] );
    }
    return passed;
};

Qats.printObject = function (object)
{
	var str = "printObject ";
	if ( object == undefined )
	{
		str += "undefined"; 
	}
	else
	{
		str += object + " : ";
		for (property in object) 
		{
			str += property + ",";
		}
	}

	qWarn( str );
}

Qats.mouseTClick = function( widget, button )
{
	QTest.mouseDClick( widget, button );
	QTest.mouseClick( widget, button );
}

Qats.typeText = function( parent, widgetName, text )
{
	qVerify( parent, "Parameter 'parent' is null" );
	parent = typeof parent === 'string' ? Qats.findGuiObject( parent ) : parent;
	qVerify( parent, "Cannot find parameter '" + parent + "' in main window" );

	editWidget = parent.findChild( widgetName ); 
	qVerify( editWidget, "Cannot find widget '" + widgetName + "' as in '" + parent.objectName + "' widget" );

	metaObject = editWidget.metaObject(); 
	qVerify( metaObject ); 

	var iProperty = metaObject.indexOfProperty( "text" );
	if ( iProperty == -1 )
	{
		iProperty = metaObject.indexOfProperty( "plainText" );
	}
	qVerify( iProperty != -1 );

	// delete old content
	var propertyName = metaObject.property( iProperty ).name();
	if ( editWidget[ propertyName ] != "" )  
	{
		Qats.mouseTClick( editWidget, Qt.LeftButton );
		QTest.keyClick( editWidget, Qt.Key_Backspace );
	}

	// type new content
	QTest.keyClicks( editWidget, text );
}

Qats.getTopLevelWidget = function( widgetType ) 
{
	//	for ( widget in QApplication.topLevelWidgets() ) // TODO Don't work
	for ( i=0; i<QApplication.topLevelWidgets().length; i++ ) 
	{ 
		widget = QApplication.topLevelWidgets()[ i ]
		if ( widget.visible && widget.inherits( widgetType ) )
		{
			return widget;
		}
	}

	return null;
}

Qats.activeDialog = function()
{
	return Qats.getTopLevelWidget( "QDialog" );
}

Qats.getMainWindow = function()
{
	return Qats.getTopLevelWidget( "QMainWindow" );
}

Qats.activeDialogVisible = function()
{
	return Qats.activeDialog() && Qats.activeDialog().visible;
}

Qats.acceptDialog = function()
{
	dialog = Qats.activeDialog();
	qVerify( dialog );

	QTest.keyClick( dialog, Qt.Key_Enter );
	qVerify( !dialog.visible );
}

Qats._removeCurrentDelayedAction = function()
{
	Qats._delayedActions.splice( 0, 1); 
	if ( !Qats._delayedActions.length )
	{
		Qats._timer.stop();
	}
}

Qats._timer = new QTimer
Qats._timer.interval = 1000; // set the time in milliseconds
Qats._timer.singleShot = false; 
Qats._delayedActions = []; 
Qats._timer.timeout.connect(this, function(){

	qVerify( Qats._delayedActions.length );
	
	Qats._timer.stop(); 
	Qats._timer.start(); 
	
	var currentDelayedAction = Qats._delayedActions[ 0 ]; 
	if ( currentDelayedAction.triggerCondition() )
	{
		Qats._removeCurrentDelayedAction();
		currentDelayedAction.action();
	}
	else
	{
		currentDelayedAction.timeout -= 1000; 
		if ( currentDelayedAction.timeout < 0 )
		{
			Qats._removeCurrentDelayedAction();
			qFail( "Cannot execute delayed action, timeout on triggerCondition " );
		}
	}
});

Qats.delayedAction = function( action, triggerCondition, timeout )
{
	timeout = timeout ? timeout : 30000;

	Qats._delayedActions.unshift( { action: action, triggerCondition: triggerCondition, timeout: timeout } ); 

	Qats._timer.stop(); 
	Qats._timer.start(); 
	
	/*
	if ( !Qats._timer.active )
	{
		qWarn( "start timer!" );
		Qats._timer.start(); 
	}*/
}

/*! 
  \return a QModelIndex of item at the given path in the \param treeView. \return null if item doesn't 
  exist
  \param treeView can be an object that extends QAbstractItemView or a its name
  \param path list of nodes separated with '/'. Manage wildcard. Plan to manage XPath in the future
*/
Qats.getIndexFromPath = function( treeView, path )
{
	treeView = typeof itemView === 'string' ? Qats.findGuiObject( treeView ) : treeView;
	qVerify( treeView );
	qVerify( treeView.inherits( "QAbstractItemView" ) );

	qVerify( typeof path === 'string' );

	var model = treeView.model();
	if ( model == null ) return null;

	var index = model.index( 0, 0 );

	// remove first '/' if any
	if ( path.length > 0 && path[0] == '/' )
	{
		path = path.slice(1); 
	}

	var pathArray = path.split( "/" );
	
	var first = true;
	for( var i=0; i<pathArray.length; i++)
	{
		pathElt = pathArray[ i ];

		var indexes = model.match( first ? index : index.child( 0, 0), Qt.DisplayRole, pathElt, -1, Qt.MatchRegExp );
		if ( indexes.length != 1 ) return null;

		index = indexes[0]; 
		first = false;
		treeView.setExpanded( index, true ); // expand because of lazy treeview
	}
	
	return index.isValid() ? index : null;
}

Qats.findChildWithType = function( object, typeName )
{
	qVerify( typeof typeName === 'string' );

	if ( !object )
	{
		return null;
	}

 	for( i=0; i<object.children().length; i++ )
	{
		child = object.children()[ i ]; 
		if ( child.inherits( typeName ) )
		{
			return child;
		}
	}

	return null;
}

QatsToolBar = {}
QatsToolBar.executeAction = function( action )
{
	qVerify( action, "'action' parameter is null" );

	action = typeof action === 'string' ? Qats.findGuiObject( action ) : action;
	qVerify( action, "Cannot find action '" + action + "'" );

	mainWindow = Qats.getMainWindow();
	qVerify( mainWindow, "Cannot find main window" );

	toolBar = Qats.findChildWithType( mainWindow, "QToolBar" );
	qVerify( toolBar, "Cannot find main window tool bar" );

	center = toolBar.actionGeometry( action ).center();
	qVerify( !center.isNull(), "Cannot find action '" + action.objectName + "' from tool bar" );

	child = toolBar.childAt( center );
	qVerify( child, "Cannot find widget at position '" + center + "'"  );

	center = child.rect.center();
	qVerify( !center.isNull(), "Widget center is null" );

	QTest.mouseClick( child, Qt.LeftButton, Qt.NoModifier, center );
}

Qats.findDataInQTableView = function( tableView, data )
{
	model = tableView.model(); 
	qVerify( model );

	for( var row=0; row<model.rowCount(); row++ )
	{
		for( var col=0; col<model.columnCount(); col++ )
		{
			index = model.index( row, col );
			if ( model.data( index ) == data ) 
			{
				return index; 
			}
		}
	}

	return null;
}

/*!
  trigger \param action from \param menu
  if \param menu is null, we get the top level menu
*/
Qats.triggerMenuAction = function( action, menu )
{
	menu = menu ? menu : Qats.getTopLevelWidget( "QMenu" );
	qVerify( menu )
	qVerify( menu.visible )

	rect = menu.actionGeometry( action );
	qVerify( rect.isValid() );

	QTest.mouseMove( menu, rect.center() );
	QTest.mouseClick( menu, Qt.LeftButton, Qt.NoModifier, rect.center() );
}

Qats.isMenuVisible = function()
{
	menu = Qats.getTopLevelWidget( "QMenu" );
	return menu && menu.visible;
}

Qats.waitFor = function( conditionFunction, timeout )
{
	var timeout = timeout ? timeout : 30000;

	var timer = new QTimer;
	timer.singleShot = true;
	timer.interval = timeout;

	timer.start(); 

	while (!conditionFunction())
	{
		if (timer.remainingTime <= 0)
			break;

		QApplication.processEvents( QEventLoop.AllEvents, timer.remaining );
		QTest.qWait(1000);
	}
	
	qVerify( conditionFunction() );
}

/*! 
  debug function to list properties for an object
*/
Qats.listProperties = function(obj)
{
	var propList = "";
	for(var propName in obj)
	{
		if( obj[propName] ) 
		{
			propList += (propName + ", ");
		}
	}
}

QatsComboBox = {}

/*!
  select item from a QComboBox
  \param comboBox a QComboBox object or a its objectName
  \param value can be : 
  - a number : row to be selected
  - a string : string value to be selected. Regular expression is supported. It must be unique, else it
  fails.
*/
QatsComboBox.select = function( comboBox, value )
{
	qVerify( comboBox, "Invalid 'comboBox' parameter" );
	comboBox = typeof comboBox === 'string' ? Qats.findGuiObject( comboBox ) : comboBox;
	qVerify( comboBox, "Cannot find '" + comboBox + "' comboBox" );

	qVerify( value, "Invalid 'value' parameter" );

	// open combo
	QTest.mouseClick( comboBox, Qt.LeftButton );

	var view = comboBox.view(); 
	qVerify( view );
		
	// wait for menu to be opened
	Qats.waitFor( function() { 
		return view.isVisible() });

	var model = view.model();
	qVerify( model );

	// in case we have a textual value
	if ( typeof value === 'string' )
 	{
		var indexes = model.match( model.index( 0, 0 ), Qt.DisplayRole, value, 1, Qt.MatchRegExp );
		qCompare( indexes.length, 1, "Not exactly one match for '" + value + "' in comboBox '" + comboBox.objectName + "'" );
		qVerify( indexes[ 0 ], "match returned index is null" ); // not suppose to happen
		value = indexes[ 0 ].row(); 
	}

	var index = model.index( value, 0 ); 
	qVerify( index );
	qVerify( index.isValid() );

	// scroll to in case of long combo box
	view.scrollTo( index );

	var rect = view.visualRect( index );
	qVerify( rect.isValid() );

	// select item in combo
	QTest.mouseMove( view.viewport(), rect.center() );
	QTest.mouseClick( view.viewport(), Qt.LeftButton, Qt.NoModifier, rect.center() );

	// wait for menu to be closed
	Qats.waitFor( function() { return !view.isVisible() } );
}

/*!
  find and \return any gui object (widget, action, menu) according to his name \param objectName
*/
Qats.findGuiObject = function( objectName )
{
	mainWindow = Qats.getMainWindow();
	qVerify( mainWindow );
	
	return mainWindow.findChild( objectName );
}

QatsItemView = {}

/*! 
  change check state of an \param itemViewn item
  \param itemView an itemView
  \param index a QModelIndex item or path to the item
  \param isChecked true if item has to be checked
*/
QatsItemView.setChecked = function( itemView, index, isChecked )
{
	qVerify( itemView ); 

	qVerify( index ); 
	index = typeof index === 'string' ? Qats.getIndexFromPath( itemView, index ) : index; 
	qVerify( index, "Cannot find item '" + index + "'" );

	qVerify( isChecked != undefined && isChecked != null ); 
	
	var model = itemView.model(); 
	qVerify( model );

	itemView.scrollTo( index );

	// TODO we can't mouseClick on checkbox area because at the moment, I don't see a way to
	// find out where actually this area is

	// TODO : Qt.CheckStateRole instead of 10 when managing correctly CheckStateRole
	model.setData( index, isChecked ? Qt.Checked : Qt.Unchecked, 10 );
}

/*! 
  select item(s) from ItemView
  \param itemView could be either an objet that extend QAbstractItemView or the item view object name
  \param indexes can be : 
  - a QModelIndex
  - a path to the index
  - a list of mixed QModelIndex or path, meaning that several item has to be selected
*/
QatsItemView.select = function( itemView, indexes )
{
	itemView = typeof itemView === 'string' ? Qats.findGuiObject( itemView ) : itemView;
	qVerify( itemView );
	qVerify( itemView.inherits( "QAbstractItemView" ) );

	// be sure we have an array
	indexes = [].concat( indexes );

	model = itemView.model(); 
	qVerify( model );

	selectionModel = itemView.selectionModel(); 
	qVerify( selectionModel );

	// clear previous selection
	selectionModel.clear();

	// select all item
	for( var i=0; i<indexes.length; i++ )
	{
		index = indexes[ i ];
		
		index = typeof index === 'string' ? Qats.getIndexFromPath( itemView, index ) : index; 
		qVerify( index );
		qVerify( index.isValid() );

		itemView.scrollTo( index );

		rect = itemView.visualRect( index ); 
		qVerify( rect.isValid() );

		center = rect.center();
		qVerify( !center.isNull() );
		
		QTest.mouseClick( itemView.viewport(), Qt.LeftButton, Qt.ControlModifier, center );
	}
}

/*! 
  \return true if all item(s) are selected in ItemView
  \param itemView could be either an objet that extend QAbstractItemView or the item view object name
  \param indexes can be : 
  - a QModelIndex
  - a path to the index
  - a list of mixed QModelIndex or path, meaning that the function return true only if
  all item are selected
*/
QatsItemView.isSelected = function( itemView, indexes )
{
	itemView = typeof itemView === 'string' ? Qats.findGuiObject( itemView ) : itemView;
	qVerify( itemView );
	qVerify( itemView.inherits( "QAbstractItemView" ) );

	// be sure we have an array
	indexes = [].concat( indexes );

	model = itemView.model(); 
	qVerify( model );

	selectionModel = itemView.selectionModel(); 
	qVerify( selectionModel );

	// select all item
	for( var i=0; i<indexes.length; i++ )
	{
		index = indexes[ i ];
		
		index = typeof index === 'string' ? Qats.getIndexFromPath( itemView, index ) : index; 
		qVerify( index );
		qVerify( index.isValid() );

		if ( !selectionModel.isSelected( index ) )
		{
			return false; 
		}
	}

	return true;
}

/*! 
  find and \return action according to action description given as argument and contextual menu 
  containing the action
  \param action could be : 
    - a QAction object
	- a QAction objectName value
	- a QAction text property value
*/
Qats.getAction = function( action, menu )
{
	qVerify( action );
	qVerify( menu );

	var subActions = menu.actions(); 
	qVerify( subActions );

	// search for action
	for( var i=0; i<subActions.length; i++ )
	{
		var subAction = subActions[ i ];
		if( subAction.inherits( "QAction" ) && 
			(
				// current action is a string (object name or text)
				( typeof action === 'string' && ( subAction.text == action || subAction.objectName == action ) )
				// action is a QAction object
				|| ( action === subAction )
			)
		  )
		{
			return subAction;
		}
	}
	
	return null;
}

/*!
  Execute en action from an item view for a given \param index
  \param itemView could be either an objet that extend QAbstractItemView or the item view object name
  \param index item on which Qats has to trigger the action. Can be : 
     - a QModelIndex
	 - a path to the item (\sa getIndexFromPath)
	 - a list of mixed QModelIndex or item path
  \param actions could be a : 
     - a QAction object 
	 - an action object name
	 - an action text
	 - a list of the 3 previous options
  \param blockingContextMenu true if the contextmenu block Qt event loop. Default is true. It must be
  always true except if you display the menu by yourself using the popup, setVisible or show method
*/
QatsItemView.executeAction = function( itemView, indexes, actions, blockingContextMenu )
{
	// get item view
	qVerify( itemView, "Parameter 'itemView' is null" );
	itemView = typeof itemView === 'string' ? Qats.findGuiObject( itemView ) : itemView;
	qVerify( itemView, "Cannot find widget '" + itemView + "' in main window" );
	qVerify( itemView.inherits( "QAbstractItemView" ), "widget '" + itemView + "' is not an item view" );

	// be sure there is a context menu
	qVerify( itemView.contextMenuPolicy != Qt.PreventContextMenu && itemView.contextMenuPolicy != Qt.NoContextMenu, 
			 "Wrong context menu policy" );

	// default is true
	blockingContextMenu = blockingContextMenu != null && blockingContextMenu != undefined ? 
		blockingContextMenu : true; 

	// index can be an array defining a path
	qVerify( indexes, "Parameter 'indexes' is null" );

	var index = null;
	if ( Qats.isArray( indexes )  )
	{
		qVerify( indexes.length, "'indexes' array is empty" );

		// select all item
		QatsItemView.select( itemView, indexes );

		// click last one to trigger action
		index = indexes[ indexes.length - 1 ];
	}
	// not an array
	else
	{
		index = indexes; 
	}

	index = typeof index === 'string' ? Qats.getIndexFromPath( itemView, index ) : index;
	qVerify( index, "Cannot find index '" + index + "' from item view '" + itemView.objectName + "'" );

	qVerify( actions, "Parameter 'actions' is null" );
	actions = [].concat( actions );

	// scroll to index to be sure item is visible
	itemView.scrollTo( index );

	var rect = itemView.visualRect( index ); 
	qVerify( rect.isValid() );
	
	var center = rect.center();
	qVerify( !center.isNull() );

	var iAction = 0;
	var previousAction = null;

	// define a delayedAction function to click on action
	function clickAction()
	{
		qVerify( actions[ iAction ] );

		// the menu containing the current action
		var currentMenu = previousAction ? previousAction.menu() : Qats.getTopLevelWidget( "QMenu" ); 
		qVerify( currentMenu );
		qVerify( currentMenu.visible );

		// search for action
		var currentAction = Qats.getAction( actions[ iAction ], currentMenu );
		qVerify( currentAction, "Cannot find item '" + actions[ iAction ] + "'" );
	
		previousAction = currentAction;
		iAction++;

		// check if there is a next action
		var hasNextAction = iAction < actions.length;
		var nextMenu = currentAction.menu(); 
		if ( hasNextAction )
		{
			qVerify( nextMenu );
		}

		// delay action if blocking
		if ( blockingContextMenu && hasNextAction )
		{
			// the menu containing the next action
			Qats.delayedAction( clickAction, function(){ return nextMenu.visible } );
		}
		
		Qats.triggerMenuAction( currentAction, currentMenu );

		// execute action now if non blocking
		if ( !blockingContextMenu && hasNextAction )
		{
			Qats.waitFor( function(){ return nextMenu.visible; } );
			clickAction();
		}
	}

	if ( blockingContextMenu )
	{
		Qats.delayedAction( clickAction, Qats.isMenuVisible );
	}		

	// Move is mandatory because else, menu is displayed under mouse position, everywhere on the 
	// desktop
	// Don't forget Qt.ControlModifier if we have multi selection before
	QTest.mouseClick( itemView.viewport(), Qt.RightButton, Qats.isArray( indexes ) ? Qt.ControlModifier : Qt.NoModifier, center );
	QTest.mouseMove( itemView.viewport(), center );
	QTest.postContextMenuEvent( itemView.viewport(), center );
	QApplication.processEvents();

	if ( !blockingContextMenu )
	{
		Qats.waitFor( Qats.isMenuVisible );
		clickAction();
	}

	// in any case, we have to wait that no menu is no longer visible
	Qats.waitFor( function(){ return !Qats.isMenuVisible(); } );
}

/*! 
  \return true if \param object is an array
*/
Qats.isArray = function( object )
{
	return Object.prototype.toString.call( object ) === '[object Array]';
}

QatsMessageBox = {}

/*!
  Click on QMessageBox button
  \param buttonId the QMessageBox::StandardButton to be clicked
*/
QatsMessageBox.clickButton = function( buttonId )
{
	dialog = Qats.activeDialog();
	qVerify( dialog );

	button = dialog.button( buttonId ); 
	qVerify( button );

	QTest.mouseClick( button, Qt.LeftButton );
}

/*!
  trigger a mouse click
  \param widget could be a QWidget or a QWidget objectName
  \param mouse button to click
  \param modifier Ctrl, Alt, ...
  \param x and \paran y mouse position
 */
Qats.mouseClick = function( widget, button, modifier, x, y )
{
	qVerify( widget );
	widget = typeof widget === 'string' ? Qats.findGuiObject( widget ) : widget;

	var pt = new QPoint(); 
	pt.setX( x ); 
	pt.setY( y );

	QTest.mouseClick( widget, Qt.LeftButton, Qt.ControlModifier, pt );
}
