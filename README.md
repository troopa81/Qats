# Qats
Qt Automated Test Scripting

Qats is an application designed to execute javascript tests inside a Qt 
application, in order to easily and rapidely write end to end tests.

Qats works actually with Qt 5.2. It's a new born project, so be indulgent :)

# Build Qats
Follow the instructions to build Qats 
$ git clone https://github.com/troopa81/Qats.git
$ cd Qats
$ mkdir build
$ cd build
$ cmake .. 
$ make install

If you want to install in a specifc directory, add this to cmake options 
-DCMAKE_INSTALL_PREFIX=$INSTALL_DIR

If you want to build with a specific Qt directory, add this to cmake options
-DCMAKE_PREFIX_PATH="$QT_DIR"

# Build Qats tests
from Qats root directory...
$ mkdir buildTests
$ cd buildTests
$ cmake ../tests 

If you want to use a specific Qt directory and custom Qats install, add this to cmake
-DCMAKE_PREFIX_PATH="$QT_DIR;$INSTALL_DIR"

# start Qats tests
First, check that your lib directory is in ld path. If not :
$ export LD_LIBRARY_PATH=$INSTALL_DIR:$LD_LIBRARY_PATH
$ qats&
$ qatsTets

Then click "Load script dir", select "Qats/tests/scripts" directory, and
finally double click on "tests.js". Then you see the tests getting executed on 
qatsTest and the result being display on qats 

# Plug Qats with your application
You can see Qats tests as an example on how to plug your application with Qats.
Basically you just have to compile your application with Qast. If you use CMake,
add this lines to your CMakeLists.txt : 

find_package(Qats REQUIRED)
include_directories(${QATS_INCLUDE_DIRS})
link_libraries(${QATS_LIBRARIES})

and this line in your source code, just before executing you Qt application
qats::initialize();		

and that's it!