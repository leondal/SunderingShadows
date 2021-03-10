//Coded by Diego//

#include <std.h>
#include "../loviatar.h"

inherit VAULT;

void create(){
	::create();
	set_name("hallway");
   set_short("hallway");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"A simple, austere hallway leads east-west along the "+
   	"upper floor of Loviatar's temple.  Torch scones line "+
   	"the walls, but the flames burn low, almost subdued as "+
   	"if picking up the atmosphere of the place.  There is a "+
   	"door to the north, a door to the south and a door to the "+
   	"west.  The hall continues east."+
   	"%^RESET%^\n"
   );
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","%^BOLD%^The faint smell of wood polish and "+
   	"buring torches can be detected.%^RESET%^");
   set_listen("default","%^YELLOW%^You hear muffled screams "+
   	"from somewhere deep within the temple.%^RESET%^");
   set_items(([
  	]));
   set_exits(([
		"east" : GAB+"hall2",
		"north" : GAB+"hpriest",
		"south" : GAB+"acolyte",
		"west" : GAB+"stairs"
	]));
  	set_door("door",GAB+"stairs","west","loviatar_holy_symbol");
   set_door_description("door","The door is made of stout oak "+
   	"and is banded in iron.\n");
   set_string("door","open","The door opens with a creak to the top "+
   	"of a circular staircase.\n");
   set_open("door",1);

   set_door("walnut door",GAB+"hpriest","north","loviatar_holy_symbol");
   set_door_description("walnut door","The door is made of stout black walnut "+
   	"and is banded in iron.\n");
   set_string("walnut door","open","The door opens with into the high priests room.\n");
   set_locked("walnut door",1,"lock");
	(GAB+"hpriest")->set_locked("walnut door",1,"lock");

   set_door("pine door",GAB+"acolyte","south","loviatar_holy_symbol");
   set_door_description("pine door","The door is made of pine "+
   	"and is banded in iron.\n");
   set_string("pine door","open","The door opens with a creak into the acolytes room.\n");
   set_locked("pine door",0,"lock");
	(GAB+"acolyte")->set_locked("pine door",0,"lock");
 	set_open("pine door",1);
 	(GAB+"acolyte")->set_open("pine door",1);

}
void reset(){
	::reset();
	switch(random(10)){
		case 0..4 :
			break;
		case 5 :
			tell_room(TO,"%^BOLD%^%^RED%^Horrific screams can "+
				"be heard clearly nearby.");
			break;
		case 6 :
			tell_room(TO,"%^BOLD%^%^BLACK%^A feeling of fear "+
				"and panic fills you and then departs as suddenly as it started.");
			break;
		case 7 :
			tell_room(TO,"%^RED%^You hear the crack of a whip "+
				"followed closely by a scream and then a whimper.");
			break;
		case 8 :
			tell_room(TO,"%^CYAN%^The candles flicker and sputter as "+
				"if from an unseen wind.");
			break;
		case 9 :
			tell_room(TO,"%^BOLD%^%^RED%^Wailing and weeping can be "+
				"heard in the distance.");
			break;
		default :
			tell_room(TO,"%^BOLD%^%^RED%^There is a terrible shaking as the walls "+
				"crumble and fall in on your head!!\nYou take horrific "+
				"damage and will not fit in a plastic baggie if someone "+
				"can find a squeegie.\n%^YELLOW%^PSYKE!!! %^RED%^Either that or something "+
				"bugged and you need to ask a wiz.");
			break;
	}
}
