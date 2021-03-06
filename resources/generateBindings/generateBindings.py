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
import CppHeaderParser

# pprint.PrettyPrinter(depth=6).pprint( self.classInherits )

def remove( content, startRe, endRe ):
    # BUG PARSER
    
    while(True):
        
        index = content.find( startRe )
        if ( index == -1 ):
            return content

        end = re.search(endRe, content[index:]).end()
        content = content[:index] + content[index+end+1:]

class BindingGenerator:

    def __init__(self):
        self.globalEnums = {}
        self.f = None
        self.cppClass = None
        self.hasPublicConstructor = False
        self.isAbstract = False
        self.classInherits = {}
        self.inherited = ""; 
        self.notGeneratedMethods = { "QObject" : [ "connect", "disconnect", "connect_functor", "find_children", "find_child" ] }
        self.notGeneratedClass = [ "QObjectData", "QObjectUserData", "QSignalBlocker", "QWidgetData" ]

    def findEnumFromValue( self, enumValueName ):
        for (className, enums) in self.globalEnums.iteritems():
            for enum in enums:
                for enumValue in enum['values']:
                    if enumValue['name'] == enumValueName:
                        return ( className, enum )

        return (None,None)

    def findEnum( self, enumName ):
        for (className, enums) in self.globalEnums.iteritems():
            for enum in enums:
                if 'name' in enum and enum['name'] == enumName:
                    return ( className, enum )

        return (None,None)

    def treatType( self, typeName ):


        # BUG
        typeName = re.sub( r"__", r"::", typeName) 

        if ( typeName == "ButtonRole" ):
            print( "typeName=" + typeName  )
            #pprint.PrettyPrinter(depth=6).pprint( self.globalEnums )

        enumClassName, enum = self.findEnum( typeName );

        if enumClassName != None and enum != None:
            return (enumClassName + "::" + typeName);
        elif typeName in self.cppClass[ 'typedefs' ][ 'public' ]:
            return self.cppClass['name'] + "::" + typeName
        else:
            return typeName

    # return true if current class inherits from QObject
    def inheritsQObject(self): 
        parentClass = self.cppClass[ 'name' ]; 
        while parentClass in self.classInherits:
            parentClass = self.classInherits[ parentClass ];

        return parentClass == "QObject"; 

    def generateScriptConstructor(self):

        # script constructor only if class is not abstract and have a public constructor
        if self.isAbstract or not self.hasPublicConstructor:
            return None

        constructorName = "script" + self.cppClass[ 'name' ] + "Constructor";
        self.f.write("inline QScriptValue " + constructorName + "(QScriptContext *context, QScriptEngine *engine)\n");
        self.f.write("{\n");
        self.f.write("Q_UNUSED(context);\n");

        # TODO manage parameters for constructor
        #for method in self.cppClass[ 'methods' ]['public']:
        #    if method[ 'constructor' ]:
        #        print( "coucou" )
        #        for iParameter in range( 0, len(method['parameters'])) :
        #            print( "type="  + method['parameters'][ iParameter ]['type'] );

        if self.inheritsQObject(): 
            # TODO set the parent correctly. QWidget take QWidget as parent not QObject, so this need a cast
            #            self.f.write("QObject *parent = context->argument(0).toQObject();\n");
            self.f.write( self.cppClass['name'] + " *object = new " + self.cppClass['name'] + "(0);\n");
            self.f.write("return engine->newQObject(object, QScriptEngine::ScriptOwnership);\n");
        else:
            self.f.write( self.cppClass['name'] + " object;\n" );
            self.f.write( "return engine->newVariant( QVariant( object ) );");

        self.f.write("}\n\n");
        return constructorName

    def generateEngineRegistration( self, scriptConstructorName ):
        
        self.f.write("static void registerToScriptEngine(QScriptEngine* engine)\n")
        self.f.write("{\n")

        for strType in [ self.cppClass[ 'name' ], self.cppClass[ 'name' ] + "*" ]:
            self.f.write("engine->setDefaultPrototype(qMetaTypeId<"); 
            self.f.write( strType ); 
            self.f.write( ">(), engine->newQObject(new " + self.cppClass['name'] + "Prototype(engine)));\n" )

        self.f.write("\n")
        
        # script constructor only if class is not abstract 
        if scriptConstructorName :
            self.f.write("QScriptValue ctor = engine->newFunction(" + scriptConstructorName + ");\n");

        if self.inheritsQObject(): 
            self.f.write("QScriptValue metaObject = engine->newQMetaObject(&" + self.cppClass[ 'name' ] + "::staticMetaObject" ); 
            if scriptConstructorName : 
                self.f.write( ", ctor" ); 
                
            self.f.write( ");\n");

        # even if class is abstract we need an instance in order to access specific enum
        self.f.write("engine->globalObject().setProperty(\"" + self.cppClass['name'] + "\", "
                     + ( "metaObject" if self.inheritsQObject() else "ctor" ) + ");\n");

        self.f.write("}\n")
        self.f.write("\n")

    def parseCppHeader( self, cppHeader, outputDir ):

        for className in cppHeader.classes.keys():

            self.cppClass = cppHeader.classes[ className ];

            # Do not generate all classes...
            if className in self.notGeneratedClass:
                continue;

            protoClassName = className + "Prototype"

            # compute if class is abstract or not
            self.isAbstract = False
            for methods in self.cppClass[ 'methods' ].values():
                for method in methods:
                    if method[ 'pure_virtual' ] :
                        self.isAbstract = True
                        break

            self.hasPublicConstructor = False
            for method in self.cppClass[ 'methods' ]['public']:
                if method['constructor']:
                    self.hasPublicConstructor = True
                    break

            print( "Generate " + protoClassName + "..." );

            self.globalEnums[ className ] = self.cppClass[ 'enums' ][ 'public' ];
            self.f = open( os.path.join( outputDir, protoClassName + ".h" ),'w')

            ## write licence
            self.f.write("/****************************************************************************\n");
            self.f.write("**\n");
            self.f.write("** Copyright (C) 2015 Cabieces Julien\n");
            self.f.write("** Contact: https://github.com/troopa81/Qats\n");
            self.f.write("**\n");
            self.f.write("** This file is part of Qats.\n");
            self.f.write("**\n");
            self.f.write("** Qats is free software: you can redistribute it and/or modify\n");
            self.f.write("** it under the terms of the GNU Lesser General Public License as published by\n");
            self.f.write("** the Free Software Foundation, either version 3 of the License, or\n");
            self.f.write("** (at your option) any later version.\n");
            self.f.write("**\n");
            self.f.write("** Qats is distributed in the hope that it will be useful,\n");
            self.f.write("** but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
            self.f.write("** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
            self.f.write("** GNU Lesser General Public License for more details.\n");
            self.f.write("**\n");
            self.f.write("** You should have received a copy of the GNU Lesser General Public License\n");
            self.f.write("** along with Qats. If not, see <http://www.gnu.org/licenses/>.\n");
            self.f.write("**\n");
            self.f.write("****************************************************************************/\n");
            self.f.write("\n");

            self.f.write("#ifndef _" + protoClassName.upper() + "_\n");
            self.f.write("#define _" + protoClassName.upper() + "_\n");

            # get possible inheritance
            self.inherited = "";
            for inheritedClass in self.cppClass['inherits']:
                if inheritedClass['access'] == "public":

                    # not suppose to happen with Qt
                    # happen only for QWidget (keeps only first inherited which is QObject
                    if self.inherited != "":
                        print( "Error : multiple inheritance, take first inherited class" );
                    else:
                        self.inherited = inheritedClass['class'] + "Prototype"
                        self.classInherits[ className ] = inheritedClass['class'];

            self.f.write("\n")
            self.f.write("#include <QObject>\n")
            self.f.write("#include <QScriptable>\n")
            self.f.write("#include <QScriptValue>\n")
            self.f.write("#include <QScriptEngine>\n")
            self.f.write("#include <" + className + ">\n")
            self.f.write("\n")

            if self.inherited != "":
                self.f.write("#include \"" + self.inherited + ".h\"\n");

            self.f.write("\n")

            scriptConstructorName = self.generateScriptConstructor();

            self.f.write("namespace qats\n")
            self.f.write("{\n")
            self.f.write("\n")

            self.f.write("class " + protoClassName ); 

            self.f.write( " : public " + ( self.inherited if self.inherited != "" else " QObject, public QScriptable") )

            self.f.write( "\n" );
            self.f.write("{\n")
            self.f.write("Q_OBJECT\n")
            self.f.write("\n")

            self.f.write("public:\n")
            self.f.write("\n")

            self.generateEngineRegistration( scriptConstructorName );

            self.f.write(protoClassName + "(QObject* parent = 0):"+ (self.inherited if self.inherited != "" else "QObject") + "(parent){}\n")

            self.f.write("public slots:\n")
            self.f.write("\n")

            # public methods ...
            for method in self.cppClass[ 'methods' ][ 'public' ]:

                isStatic = method['static']

                # do not treat constructor and destructor
                notGeneratedMethods = self.notGeneratedMethods[ self.cppClass[ 'name' ] ] if self.cppClass['name'] in self.notGeneratedMethods else []
                if method['constructor'] or method['destructor'] or method['name'].startswith( "operator" ) or method[ 'name' ] in notGeneratedMethods or '<' in method['name']:
                    continue

                returnType = method['rtnType']

                # BUG : remove static from type
                if isStatic:
                    returnType = returnType[ returnType.find( "static") + 7:]

                # compute return type
                returnType = self.treatType( returnType )

                self.f.write(returnType + " " + method['name'] + "(" )

                # remove weird case of default value as a type (see QWidget::grab)
                parameters = []
                for iParameter in range( 0, len(method['parameters'])) :
                    if "(" not in method['parameters'][ iParameter ]['type']:
                        parameters.append( method['parameters'][ iParameter ] )
                    elif iParameter > 0 :
                        del parameters[ iParameter-1 ][ 'defaultValue' ]

                for iParam in range(0, len(parameters)):
                    parameter = parameters[iParam]

                    paramType = self.treatType( parameter['type'] )                

                    # bug in parser
                    if ( parameter['name'] == "&" ):
                        paramType += "&"
                        parameter['name'] = ""

                    if ( parameter['name'] == "" ):
                        parameter['name'] = "param" + str(iParam)

                    self.f.write(paramType + " " + parameter['name'])

                    # default value if any
                    if "defaultValue" in parameter :
                        enumClassName, enum = self.findEnumFromValue( parameter['defaultValue'] )
                        self.f.write(" = "); 
                        if enumClassName != None and enum != None:
                            self.f.write( enumClassName + "::" + parameter['defaultValue'] );
                        else:
                            self.f.write(self.treatType( parameter['defaultValue'] ) )

                    if ( iParam < len(parameters)-1 ):
                        self.f.write(",")

                self.f.write(")\n")
                self.f.write("{\n")

                if not isStatic:
                    self.f.write(className + " *object = qscriptvalue_cast<" + className + "*>(thisObject());\n")

                if ( returnType != "void" ):
                    self.f.write("return ")

                if isStatic:
                    self.f.write( className + "::" )
                else:
                    self.f.write( "object->" )

                self.f.write( method['name'] + "(" );

                # method parameters in call ...
                for iParam in range(0, len(parameters)):

                    self.f.write(parameters[iParam]['name'])

                    if ( iParam < len(parameters)-1 ):
                        self.f.write(",")


                self.f.write( ");\n" );

                self.f.write("}\n")

            self.f.write("};\n")
            self.f.write("}\n")
            self.f.write("\n")

            if className not in [ "QWidget" ]:
                self.f.write("Q_DECLARE_METATYPE(" + className + "*)\n")
                self.f.write("\n")

            self.f.write("#endif\n");
            f.close()

########################### main


if len(sys.argv) != 3: 
    print("[Usage] generateBindings <qt_include_dir> <output_dir>")
    sys.exit(0)

qtDir = sys.argv[1]
outputDir = sys.argv[2]

# assume output dir is created
if not os.path.exists( outputDir ):
    os.makedirs( outputDir )

try:

    #"qtbase/src/corelib/kernel/qmetaobject.h"
    qtFiles = [ 
        "QtCore/qobject.h",
        "QtWidgets/qwidget.h", 
#        "QtWidgets/qdialog.h",
#        "QtWidgets/qmessagebox.h"
        "QtWidgets/qabstractslider.h", 
        "QtWidgets/qslider.h", 
      #          "qtbase/src/widgets/widgets/qlineedit.h",
      #          "qtbase/src/widgets/kernel/qapplication.h", 
      #          "qtbase/src/widgets/itemviews/qtreeview.h",
      #          "qtbase/src/widgets/itemviews/qabstractitemview.h",
      #          "qtbase/src/corelib/itemmodels/qabstractitemmodel.h",
#        "qtbase/src/widgets/widgets/qtoolbar.h"
# "qtbase/src/corelib/tools/qrect.h"
# "qtbase/src/corelib/tools/qpoint.h"
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
#"qtbase/src/corelib/io/qiodevice.h",
#"qtbase/src/corelib/io/qfiledevice.h",
#"qtbase/src/corelib/io/qfile.h"
#"qtbase/src/widgets/widgets/qabstractbutton.h"
    ]

    generator = BindingGenerator() 

    for qtFile in qtFiles:

        sourceFileName = os.path.join( qtDir, qtFile )
        tmpPreprocessorFileName = "/tmp/tmpPreprocessorFile.h"

        # generate file without include
        scriptDir = os.path.abspath(os.path.dirname(__file__)); 
        subprocess.call([ os.path.join( scriptDir, 'prepareFile.sh' ), sourceFileName])

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
        
        generator.parseCppHeader( cppHeader, outputDir )

except CppHeaderParser.CppParseError as e:
    print(e)
    sys.exit(1)

