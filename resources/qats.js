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
	editWidget = parent.findChild( widgetName ); 
	qVerify( editWidget );

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

Qats.findChildWithType = function( object, typeName )
{
	for( i=0; i<object.children().count(); i++ )
	{
		child = object.children().at( i ); 
		if ( child.inherits( typeName ) )
		{
			return child;
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
	QTest.keyClick( dialog, Qt.Key_Enter );
}

Qats.delayedAction = function( action, triggerCondition, timeout )
{
	timeout = timeout ? timeout : 30000;

	if ( triggerCondition() )
	{
		action();
	}
	else if ( timeout > 0 )
	{
		var timer = new QTimer;
		timer.interval = 1000; // set the time in milliseconds
		timer.singleShot = true; // in-case if setTimout and false in-case of setInterval 
		timer.timeout.connect(this, function(){
			Qats.delayedAction( action, triggerCondition, timeout-1000 );
		});
		timer.start();
	}
	else
	{
		qFail( "Cannot execute delayed action, timeout on triggerCondition " );
	}
}

Qats.getIndexFromPath = function( treeView, path )
{
	var model = treeView.model();
	if ( model == null ) return null;

	var index = model.index( 0, 0 );

	var first = true;
	for( var i=0; i<path.length; i++)
	{
		pathElt = path[ i ];

		var indexes = model.match( first ? index : index.child( 0, 0), Qt.DisplayRole, pathElt, -1, Qt.MatchRegExp );
		if ( indexes.length != 1 ) return null;

		index = indexes[0]; 
		first = false;
		treeView.setExpanded( index, true ); // expand because of lazy treeview
	}
	
	return index;
}

Qats.findChildWithType = function( object, typeName )
{
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

Qats.executeActionFromQToolBar = function( action )
{
	mainWindow = Qats.getMainWindow();
	qVerify( mainWindow );

	toolBar = Qats.findChildWithType( mainWindow, "QToolBar" );
	qVerify( toolBar );

	center = toolBar.actionGeometry( action ).center();
	qVerify( !center.isNull() );

	child = toolBar.childAt( center );
	qVerify( child );

	center = child.rect.center();
	qVerify( !center.isNull() );

	QTest.mouseClick( child, Qt.LeftButton, Qt.NoModifier, center );
}


Qats.selectInQAbstractItemView = function( itemView, index )
{
	qVerify( itemView );
	qVerify( index.isValid() );

	model = itemView.model(); 
	qVerify( model );

	selectionModel = itemView.selectionModel(); 
	qVerify( selectionModel );

	selectionModel.clear();

	itemView.scrollTo( index );

	rect = itemView.visualRect( index ); 
	qVerify( rect.isValid() );

	center = rect.center();
	qVerify( !center.isNull() );

	QTest.mouseClick( itemView.viewport(), Qt.LeftButton, Qt.NoModifier, center );
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

Qats.triggerMenuAction = function( action )
{
	menu = Qats.getTopLevelWidget( "QMenu" );
	qVerify( menu )
	qVerify( menu.visible )

	rect = menu.actionGeometry( action );
	qVerify( rect.isValid() );

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

Qats.executeActionFromQAbsractItemView = function( itemView, index, action )
{
	var rect = itemView.visualRect( index ); 
	qVerify( rect.isValid() );
	
	var center = rect.center();
	qVerify( !center.isNull() );

	var app = QApplication.instance();
	qVerify( app );

	Qats.delayedAction( function(){ Qats.triggerMenuAction( action ) }, Qats.isMenuVisible );

	QTest.mouseClick( itemView.viewport(), Qt.RightButton, Qt.NoModifier, center );
	QTest.mouseMove( itemView.viewport(), center );
	QTest.postContextMenuEvent( itemView.viewport(), center );
	QApplication.processEvents();
}

Qats.selectFromQAbsractItemView = function( itemView, index )
{
	var rect = itemView.visualRect( index ); 
	qVerify( rect.isValid() );
	
	var center = rect.center();
	qVerify( !center.isNull() );

	QTest.mouseClick( itemView.viewport(), Qt.LeftButton, Qt.NoModifier, center );
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

QatsComboBox.select = function( comboBox, value )
{
	// open combo
	QTest.mouseClick( comboBox, Qt.LeftButton );

	var view = comboBox.view(); 
	qVerify( view );
		
	// wait for menu to be opened
	Qats.waitFor( function() { 
		return view.isVisible() });

	var model = view.model();
	qVerify( model );

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
