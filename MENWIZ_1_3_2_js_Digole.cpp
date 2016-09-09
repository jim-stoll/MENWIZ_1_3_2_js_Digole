// Do not remove the include below
#include "MENWIZ_1_3_2_js_Digole.h"


DigoleSerialDisp lcd(&Wire,'\x27');
int  list,sp=110;

void myfunc(){
  Serial.println("ACTION FIRED");
}

static const byte button1Pin = 51;
static const byte button2Pin = 53;
static const byte button3Pin = 47;
static const byte button4Pin = 49;
static const long debounceMillis = 50;

static Button button1 = Button(button1Pin, BUTTON_PULLUP_INTERNAL, debounceMillis);
static Button button2 = Button(button2Pin, BUTTON_PULLUP_INTERNAL, debounceMillis);
static Button button3 = Button(button3Pin, BUTTON_PULLUP_INTERNAL, debounceMillis);
static Button button4 = Button(button4Pin, BUTTON_PULLUP_INTERNAL, debounceMillis);

//modify images to match these 11px heights and vertical spacing, so they'll clear out their full space when drawn
//reduce these to 6 wide (not really needed, as setting w/h in drawBitmap, and have nothing in last 2 spots of last nibble anyway - reduced width graphic will result in same bytes...)
//apply styled arrow to n/m indicator in top line
// parameterize (constructor?) whether to use text-based or bitmap-based symbols, and take appropriate steps in code
// pass symbol w/h for bitmaps, and use w,h for drawBitmap calls, as well as i*h for vertical placement of symbols (again, conditionally, based on whether text or bitmap symbols)
const unsigned char nodeBitmap[] PROGMEM = {
	0x00
	,0x00
	,0x00
	,0x00
	,0x30
	,0x30
	,0x00
	,0x00
	,0x00
	,0x00
	,0x00
};

const unsigned char currentNodeBitmap[] PROGMEM = {
	0x00
	,0x00
	,0x00
	,0x20
	,0x10
	,0xf8
	,0x10
	,0x20
	,0x00
	,0x00
	,0x00
};

const unsigned char noUserGrantBitmap[] PROGMEM = {
	0x00
	,0x00
	,0x28
	,0x7c
	,0x38
	,0x7c
	,0x28
	,0x00
	,0x00
	,0x00
	,0x00
};

const unsigned char itemBitmap[] PROGMEM = {
	0x00
	,0x00
	,0x30
	,0x48
	,0x84
	,0x84
	,0x48
	,0x30
	,0x00
	,0x00
	,0x00
};

const unsigned char selectedItemBitmap[] PROGMEM = {
	0x00
	,0x00
	,0x30
	,0x48
	,0xb4
	,0xb4
	,0x48
	,0x30
	,0x00
	,0x00
	,0x00
};

//menwiz menu(&lcd, 128, 64, 200, 6, 11, '\xb7', '\xbb', '\xb0', '\x95', '#');
menwiz menu(&lcd, 128, 64, 200, 6, 11, nodeBitmap, currentNodeBitmap, itemBitmap, selectedItemBitmap, noUserGrantBitmap);

void onButtonRelease(Button& b) {
	Serial.print("button pin hit: ");
	Serial.println(b.pin);
}

int menuButtonMapper() {
  if (button1.uniquePress()) {
    return MW_BTD;
  }

  if (button2.uniquePress()) {
    return MW_BTU;
  }

  if (button3.uniquePress()) {
    return MW_BTC;
  }

  if (button4.uniquePress()) {
    return MW_BTE;
  }

  return MW_BTNULL;
}

void setup() {

	_menu *r,*s1,*s1_1, *s1_2, *s2, *s3, *s4, *s5, *s6, *s7, *s8, *s9, *s10, *s11, *s12;

	Serial.begin(19200);
	menu.begin();

	menu.addUsrNav(menuButtonMapper, 4);

	r=menu.addMenu(MW_ROOT,NULL,F("123456789012345678901"));//JKLMNOWXZ"));
	s1=menu.addMenu(MW_SUBMENU,r, F("Node 1"));
	s1_1=menu.addMenu(MW_VAR,s1, F("Node 1-1 Long Name..."));
	s1_1->addVar(MW_LIST,&list);
	s1_1->addItem(MW_LIST, F("Opt1"));
	s1_1->addItem(MW_LIST, F("Opt2"));
	s1_1->addItem(MW_LIST, F("Opt3"));
	s1_1->addItem(MW_LIST, F("Opt4"));
	s1_1->addItem(MW_LIST, F("Opt5"));
	s1_1->addItem(MW_LIST, F("Opt6"));
	s1_1->addItem(MW_LIST, F("Opt7"));
	s1_1->addItem(MW_LIST, F("Opt8"));
	s1_1->addItem(MW_LIST, F("Opt9"));
	s1_1->addItem(MW_LIST, F("Opt10"));
	s1_1->addItem(MW_LIST, F("Opt11"));
	s1_1->addItem(MW_LIST, F("Opt12"));
//	s2->addItem(MW_LIST, F("Opt13"));
//	          s2->setBehaviour(MW_SCROLL_HORIZONTAL,true);
//	          s2->setBehaviour(MW_LIST_2COLUMNS,true);
//	          s2->setBehaviour(MW_LIST_3COLUMNS,true);

	s1_2=menu.addMenu(MW_VAR,s1, F("Node 1-2"));
	s1_2->addVar(MW_AUTO_INT,&sp,0,120,10);
	s1=menu.addMenu(MW_VAR,r, F("Node 2"));
	s1->addVar(MW_ACTION,myfunc);

	s5 = menu.addMenu(MW_SUBMENU, r, F("Node 3"));
	s6 = menu.addMenu(MW_SUBMENU, r, F("Node 4"));
	s7 = menu.addMenu(MW_SUBMENU, r, F("Node 5"));
	s8 = menu.addMenu(MW_SUBMENU, r, F("Node 6"));
	s9 = menu.addMenu(MW_SUBMENU, r, F("Node 7"));
	s10 = menu.addMenu(MW_SUBMENU, r, F("Node 8"));
	s9 = menu.addMenu(MW_SUBMENU, r, F("Node 9"));
	s10 = menu.addMenu(MW_SUBMENU, r, F("Node 10"));
	s11 = menu.addMenu(MW_SUBMENU, r, F("Node 11"));
	s12 = menu.addMenu(MW_SUBMENU, r, F("Node 12"));

	delay(500);


}

void loop(){
	menu.draw();
	delay(200);
}

