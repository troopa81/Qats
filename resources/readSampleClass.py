#!/usr/bin/python
# -*- coding: utf-8 -*-

############################################################################
##
## Copyright (C) 2015 Cabieces Julien
## Contact: https://github.com/troopa81/Qats
##
## This file is part of Qats.
##
## Qats is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## Qats is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with Qats. If not, see <http://www.gnu.org/licenses/>.
##
############################################################################

import sys
import re
import os
import subprocess
import pprint

sys.path = ["../"] + sys.path
import CppHeaderParser

globalEnums = {}

def findEnumFromValue( enumValueName ):
    for (className, enums) in globalEnums.iteritems():
        for enum in enums:
            for enumValue in enum['values']:
                if enumValue['name'] == enumValueName:
                    return ( className, enum )

    return (None,None)

def findEnum( enumName ):
    for (className, enums) in globalEnums.iteritems():
        for enum in enums:
            if enum['name'] == enumName:
                return ( className, enum )

    return (None,None)

def treatType( typeName, cppClass, keepEnum ):

    # BUG
    typeName = re.sub( r"__", r"::", typeName) 

    enumClassName, enum = findEnum( typeName );

#    print("enumClassName="+ str(enumClassName) + " enum=" + str(enum) );

    if enumClassName != None and enum != None:
        return (enumClassName + "::" + typeName) if keepEnum else "int" ;
    elif typeName in cppClass[ 'typedefs' ][ 'public' ]:
        return cppClass['name'] + "::" + typeName
    else:
        return typeName

def remove( content, startRe, endRe ):
    # BUG PARSER
    
    while(True):

        index = content.find( startRe )
        if ( index == -1 ):
              return content

        end = re.search(endRe, content[index:]).end()
        content = content[:index] + content[index+end+1:]

def parseCppHeader( cppHeader, outputDir ):

    for className in cppHeader.classes.keys():

        # TODO do this more cleanly...
        if className in [ "QWidgetData" ]:
            continue;

        protoClassName = className + "Prototype"
        
        print( "Generate " + protoClassName + "..." );

        cppClass = cppHeader.classes[ className ];
        globalEnums[ className ] = cppClass[ 'enums' ][ 'public' ];
#        pprint.PrettyPrinter().pprint(globalEnums)
        f = open( os.path.join( outputDir, protoClassName + ".h" ),'w')

        ## write licence
        f.write("/****************************************************************************\n");
        f.write("**\n");
        f.write("** Copyright (C) 2015 Cabieces Julien\n");
        f.write("** Contact: https://github.com/troopa81/Qats\n");
        f.write("**\n");
        f.write("** This file is part of Qats.\n");
        f.write("**\n");
        f.write("** Qats is free software: you can redistribute it and/or modify\n");
        f.write("** it under the terms of the GNU Lesser General Public License as published by\n");
        f.write("** the Free Software Foundation, either version 3 of the License, or\n");
        f.write("** (at your option) any later version.\n");
        f.write("**\n");
        f.write("** Qats is distributed in the hope that it will be useful,\n");
        f.write("** but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
        f.write("** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
        f.write("** GNU Lesser General Public License for more details.\n");
        f.write("**\n");
        f.write("** You should have received a copy of the GNU Lesser General Public License\n");
        f.write("** along with Qats. If not, see <http://www.gnu.org/licenses/>.\n");
        f.write("**\n");
        f.write("****************************************************************************/\n");
        f.write("\n");
    
        f.write("#ifndef _" + protoClassName.upper() + "_\n");
        f.write("#define _" + protoClassName.upper() + "_\n");
    
        f.write("\n")
        f.write("#include <QObject>\n")
        f.write("#include <QScriptable>\n")
        f.write("#include <QScriptValue>\n")
        f.write("#include <QScriptEngine>\n")
        f.write("#include <" + className + ">\n")
        f.write("\n")

        f.write("namespace qats\n")
        f.write("{\n")
        f.write("\n")
        
        f.write("class " + protoClassName ); 

        # get possible inheritance
        inherited = "";
        for inheritedClass in cppHeader.classes[ className ]['inherits']:
            if inheritedClass['access'] == "public":

                # not suppose to happen with Qt
                if inherited != "":
                    print( "Error : multiple inheritance" );

                inherited = inheritedClass['class'] + "Prototype";
                
        f.write( " : public " + inherited if inherited != "" else "QObject, public QScriptable")

        f.write( "\n" );
        f.write("{\n")
        f.write("Q_OBJECT\n")
        f.write("\n")
        
        f.write("public:\n")
        f.write("\n")
        
        f.write(protoClassName + "(QObject* parent = 0):"+ (inherited if inherited != "" else "QObject") + "(parent){}\n")
        
        f.write("public slots:\n")
        f.write("\n")
        
        # public methods ...
        for method in cppHeader.classes[ className ][ 'methods' ][ 'public' ]:

            isStatic = method['static']
            
            # do not treat constructor and destructor
            if  method['constructor'] or method['destructor'] or method['name'] in [ "operator=", "operator==", "operator!=", "operator<" ]:
                continue

            returnType = method['rtnType']

            # BUG : remove static from type
            if isStatic:
                returnType = returnType[7:]
                
            # compute return type
            returnType = treatType( returnType, cppHeader.classes[ className ], False )
        

            f.write(returnType + " " + method['name'] + "(" )

            # remove weird case of default value as a type (see QWidget::grab)
            parameters = []
            for iParameter in range( 0, len(method['parameters'])) :
                if "(" not in method['parameters'][ iParameter ]['type']:
                    parameters.append( method['parameters'][ iParameter ] )
                elif iParameter > 0 :
                    del parameters[ iParameter-1 ][ 'defaultValue' ]

            parametersCast = []
            for iParam in range(0, len(parameters)):
                parameter = parameters[iParam]

                # compute parameter cast if needed
                enumClassName, enum = findEnum( parameter['type'] );
                parametersCast.append( enumClassName + "::" + enum['name'] if enumClassName != None and enum != None else None );

                paramType = treatType( parameter['type'], cppHeader.classes[ className ], False )                

                # bug in parser
                if ( parameter['name'] == "&" ):
                    paramType += "&"
                    parameter['name'] = ""

                if ( parameter['name'] == "" ):
                    parameter['name'] = "param" + str(iParam)

                f.write(paramType + " " + parameter['name'])

                # default value if any
                if "defaultValue" in parameter :
                    enumClassName, enum = findEnumFromValue( parameter['defaultValue'] )
                    f.write(" = "); 
                    if enumClassName != None and enum != None:
                        f.write( enumClassName + "::" + parameter['defaultValue'] );
                    else:
                        f.write(treatType( parameter['defaultValue'], cppHeader.classes[ className ], True ) )

                if ( iParam < len(parameters)-1 ):
                    f.write(",")

            f.write(")\n")
            f.write("{\n")

            if not isStatic:
                f.write(className + " *object = qscriptvalue_cast<" + className + "*>(thisObject());\n")

            if ( returnType != "void" ):
                f.write("return ")

            if isStatic:
                f.write( className + "::" )
            else:
                f.write( "object->" )

            f.write( method['name'] + "(" );

            # method parameters in call ...
            for iParam in range(0, len(parameters)):

                if parametersCast[ iParam ] != None:
                    f.write(parametersCast[ iParam ] + "(");
                
                f.write(parameters[iParam]['name'])
                if parametersCast[ iParam ] != None:
                    f.write(")");

                if ( iParam < len(parameters)-1 ):
                    f.write(",")

                
            f.write( ");\n" );
        
            f.write("}\n")

        f.write("};\n")
        f.write("}\n")
        f.write("\n")

        if className not in [ "QWidget" ]:
            f.write("Q_DECLARE_METATYPE(" + className + "*)\n")
            f.write("\n")

        f.write("#endif\n");
        f.close()

########################### main


if len(sys.argv) != 3: 
    print("[Usage] generateBindings <qt_dir> <output_dir>")
    sys.exit(0)

qtDir = sys.argv[1]
outputDir = sys.argv[2]

try:

    #"qtbase/src/corelib/kernel/qmetaobject.h"
    qtFiles = [ 
      #          "qtbase/src/widgets/kernel/qwidget.h", 
      #          "qtbase/src/widgets/widgets/qlineedit.h",
      #          "qtbase/src/widgets/kernel/qapplication.h", 
      #          "qtbase/src/widgets/itemviews/qtreeview.h",
      #          "qtbase/src/widgets/itemviews/qabstractitemview.h",
      #          "qtbase/src/corelib/itemmodels/qabstractitemmodel.h",
 # "qtbase/src/corelib/kernel/qobject.h"
#        "qtbase/src/widgets/widgets/qtoolbar.h"
# "qtbase/src/corelib/tools/qrect.h"
 #"qtbase/src/corelib/tools/qpoint.h"
#"qtbase/src/corelib/itemmodels/qitemselectionmodel.h"
#"qtbase/src/widgets/widgets/qabstractscrollarea.h"
#"qtbase/src/corelib/kernel/qcoreapplication.h"
#"qtbase/src/gui/kernel/qevent.h"
 #  "qtbase/src/corelib/tools/qelapsedtimer.h"
#        "qtbase/src/corelib/kernel/qtimer.h",
#        "qtbase/src/widgets/widgets/qmenu.h",
#"qtbase/src/widgets/widgets/qcombobox.h",
#"qtbase/src/widgets/widgets/qscrollbar.h",
#"qtbase/src/widgets/widgets/qframe.h",
#"qtbase/src/widgets/widgets/qframe.h",
#"qtbase/src/widgets/kernel/qaction.h", 
"qtbase/src/corelib/io/qiodevice.h",
"qtbase/src/corelib/io/qfiledevice.h",
"qtbase/src/corelib/io/qfile.h"
    ]

    for qtFile in qtFiles:

        sourceFileName = os.path.join( qtDir, qtFile )
        tmpPreprocessorFileName = "/tmp/tmpPreprocessorFile.h"
        
        # generate file without include
        subprocess.call(['/home/jcabieces/work/Qats/resources/prepareFile.sh', sourceFileName])

        sourceFile = open(tmpPreprocessorFileName,'r')
        sourceContent = sourceFile.read();
        sourceFile.close()

        sourceContent = re.sub( r"(Q_PROPERTY.*)", r"\1;", sourceContent) 

        # BUG PARSER
        sourceContent = sourceContent.replace( "Q_SLOTS", "" );
        sourceContent = re.sub( r"(Q_PROPERTY.*)", r"\1;", sourceContent) 
        sourceContent = re.sub( r"::", r"__", sourceContent) 
        sourceContent = re.sub( r"static Q_DECL_DEPRECATED.*;", r"", sourceContent )
        sourceContent = re.sub( r"Q_.*_EXPORT", r"", sourceContent )
        sourceContent = re.sub( r"Q_DECLARE_FLAGS\((.*),(.*)\)", r"typedef QFlags<\2> \1;", sourceContent )

        notdefs = [ "Q_COMPILER_DECLTYPE",
                    "(Q_COMPILER_DECLTYPE",
                    "QT_KEYPAD_NAVIGATION", "Q_OS_WINCE", "Q_WS_X11", "Q_WS_MAC",
                    "Q_QDOC", "QT_NO_QOBJECT"
                ]
        for notdef in notdefs:
            sourceContent = remove( sourceContent, "#ifdef " + notdef, "#endif" )
            sourceContent = remove( sourceContent, "#ifndef " + notdef, "#endif" )
            sourceContent = remove( sourceContent, "#if defined " + notdef, "#endif" )

        # BUG PARSER
        sourceContent = remove( sourceContent, "Q_SIGNALS", "public|protected|private|}" )
        sourceContent = remove( sourceContent, "#if QT_DEPRECATED_SINCE", "#endif" )
        sourceContent = remove( sourceContent, "Q_STATIC_ASSERT_X", ";" )
    

        tmpFileName = "/tmp/tmpFile.h"
        f = open(tmpFileName,'w')
        f.write( sourceContent )
        f.close()

        cppHeader = CppHeaderParser.CppHeader( tmpFileName )
        
        parseCppHeader( cppHeader, outputDir )

except CppHeaderParser.CppParseError as e:
    print(e)
    sys.exit(1)

