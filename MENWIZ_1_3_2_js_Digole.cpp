// Do not remove the include below
#include "MENWIZ_1_3_2_js_Digole.h"


menwiz menu;
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

	_menu *r,*s1,*s2;

	Serial.begin(19200);
//	menu.begin(&lcd, 21, 6); //declare lcd object and screen size to menwiz lib
	menu.begin(&lcd, 21, 6, 200, '\xb7', '\xbb', '\xb0', '\x95');

	menu.addUsrNav(menuButtonMapper, 4);


	r=menu.addMenu(MW_ROOT,NULL,F("123456789012345678901"));//JKLMNOWXZ"));
	s1=menu.addMenu(MW_SUBMENU,r, F("Node1"));
	s2=menu.addMenu(MW_VAR,s1, F("Node3"));
	s2->addVar(MW_LIST,&list);
	s2->addItem(MW_LIST, F("Option1"));
	s2->addItem(MW_LIST, F("Option2"));
	s2->addItem(MW_LIST, F("Option3"));
	s2->addItem(MW_LIST, F("Option4"));
	s2->addItem(MW_LIST, F("Option5"));
	s2->addItem(MW_LIST, F("Option6"));
//	          s2->setBehaviour(MW_SCROLL_HORIZONTAL,true);
//	          s2->setBehaviour(MW_LIST_2COLUMNS,true);
//	          s2->setBehaviour(MW_LIST_3COLUMNS,true);

	s2=menu.addMenu(MW_VAR,s1, F("Node4"));
	s2->addVar(MW_AUTO_INT,&sp,0,120,10);
	s1=menu.addMenu(MW_VAR,r, F("Node2"));
	s1->addVar(MW_ACTION,myfunc);


	delay(500);


}

void loop(){
	menu.draw();
	delay(200);
}

