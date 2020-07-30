MENWIZ_1_3_2_js_Digole

A modified version of brunialti's amazing MENWIZ menu library for Arduino.

This version is customized to use the Digole Serial Display/Adapter, and provides
the following added functionality:
- use of custom bitmaps for menu symbol indicators (vs the charset-based default symbols)
- a new 'boolean action' menu option, which provides an on/off toggle functionality that
  calls a callback method immediately upon comfirmation of the boolean variable change
- a new 'labeled action' menu option, which calls a callback method immediately upon
  confirmation of the choice selection
- a 'display only' menu option that can display text from a callback method (such
  as a dynamic status, memory usage, etc)
- a 'cleanup' method that frees dynamically allocated memory used by the menu, such as
  might be desired when closing the menu and resuming normal progam operation)
  
Despite being customized for use with the Digole Serial Display, this code should work
with little or no modification with the original LCD library (replacing the reference to
the Digole library with a reference to the LCD library), though I have not tested this.


Original README:

MENWIZ: YET ANOTHER CHARACTER LCD MENU GENERATOR LIBRARY


DESCRIPTION
- (near) asynchronous: the library does not take mu control while working; 
  this is usefull if your sketch need to work while you are using menus
- simple to use (compact and simple code, ortogonal interface)
- user defined splash screen (optional): if you need to show something at
  startup; time elapsed is user defined.
- user defined callback screen (optional) activated after a user defined 
  elapsed time since last button push. The menu gently leave the screen to
  the user sketch code, untill any button is pushed.  
- user-defined actions (callbacks) from inside the menu
- user defined variables binding: associate (bind) a sketch variable to any 
  menu object, whenever a value is changed inside the menus, the program 
  has direct access to that value via its own (binded) variable  
- built in 6-buttons and 4-buttons modes; the user can overload the  built-in
  mode, implementing its own navigation callback (e.g. analog buttons, 
  rotary encoders etc) 
- EEPROM support to save and load variables to/from EEPROM non volatile mamory; 
  it is possible to disable EEPROM support to spare some memory
- use of F() operator to store menu strings in progmem to save the heap 
  (starting from V 1.0).
- menu objects behaviours
- create users and assign grants to visualize menu branches
- Quick tour user manual 

WHAT IS NEW IN THE LATEST VERSION
Latest version: V 1.3.2 (April 29 2014):

- Fixed the option MW_MENU_INDEX bug.
- It is now possible to set up to 3 users and to set access grant to submenus for each one of   them with the following methods:
  menwiz::setCurrentUser(int);
  _menu:: setBehaviour(MW_GRANT_USERx, Boolean);
- New data type added: the long awaited editable text MW_EDIT_TEXT. It works for now *only*   in “6 buttons mode”. The variable is not buffered, that is any change will take immediate   effect: when you leave the variable editing with exit button, the changes will affect the   original char variable.
- The method getLastbutton of the class menwiz let available the last pushed button code

KNOWN LIMITATIONS AND BUGS

t.b.d.

BACKWARD COMPATIBILITY

Please read the manual (chhaper "MENWIZ changes history")
 
Warnings:

- MENWIZ requires New LiquidCrystal (*) and Buttons libraries, enclosed with
  the package. The New LiquidCrystal allows to use 4 wires, 8 wires, I2C, 
  serial and other LCDs. The use of New LiquidCrystal is beyond this 
  introduction
- the examples are done for 20x4 I2C LCD. other interfaces and screen dimensions
  can be used accordingly with New LiquidCrystal interface (changing 
  mode/interface does not affect library code, but only sketch code) 
- starting from 0.6.0 version, due to the EEPROM support, the sketch must
  include the file EEPROM.h (until you disable the EEPROM support)

The MENWIZ library is avalable at:
https://github.com/brunialti/MENWIZ
You can download all the stuff as ZIP file.
Due to github policy it is not avalilable anymore the /downloads directory

Please visit also the following forum topic:
http://arduino.cc/forum/index.php/topic,99693.msg866553.html#new

Comments, advices and user experiences are welcome


VERSION NUMBER CONVENTION

<version>.<subversion>.<build>
  <version>: 0=not officially released
             (check the latest available sources, the lib could work  not properly
  <subversion>: new functions, modified function interfaces
  <build>: bug fixing, minor internal changes


The TEST_LIB zip file contains all the library *required* to use MENWIZ lib.

(*) New LiquidCrystal is a replacement of the standard LiquidCrystal and 
    LiquidCrystal_I2C libraries. it is more efficient and very well supported
    The nice thing about the "New LiquidCrystal" library, is that it already 
    supports a wide range of LCD controllers:
    - I2C base on the PCF8574 or compatible
    - 4bit and 8bit parallel
    - ShiftRegister: 3wire, 2wire, 1wire (beta)
    You can load the latest version at:
    https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home

