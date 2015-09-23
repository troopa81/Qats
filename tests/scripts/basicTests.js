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

Qats.include("imported/imported.js")

var myTest = {
    name: "BasicTests",

    initTestCase: function() 
	{
	},

	qWarnTest: function()
	{
		qWarn( "test" );
	},

	qFailTest: function()
	{
		qFail( "fail!" );
	},

	qCompareTest: function()
	{
		qCompare( "titi", "titi" );
	},

	qCompareFailTest: function()
	{
		qCompare( "titi", "toto" );
	},

	qVerifyTest: function()
	{
		qVerify( "titi" == "titi" );
	},

	qVerifyFailTest: function()
	{
		qVerify( "titi" == "toto" );
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

	importTest: function()
	{
		importedFunction();
	},

	importFailTest: function()
	{
		failImportedFunction();
	},

	cleanupTestCase: function() {}
};

Qats.executeTestCase(myTest);
