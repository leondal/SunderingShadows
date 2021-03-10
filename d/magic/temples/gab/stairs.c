//Coded by Diego//

#include <std.h>
#include "../loviatar.h"

inherit VAULT;

void create(){
	::create();
	set_name("top of the stairs");
   set_short("top of the stairs");
   set_long(
   	"%^RESET%^%^ORANGE%^"+
   	"You are at the top of the circular stairs.  There "+
   	"is a door in the east or you can go back down."+
   	"%^RESET%^\n"
   );
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","%^BOLD%^%^CYAN%^You can smell the heavy "+
   	"scent of wood.%^RESET%^");
   set_listen("default","%^YELLOW%^The screaming is a little "+
   	"fainter in here, the sound is muffled by the distance.%^RESET%^\n");
   set_items(([
  	]));
   set_exits(([
		"east" : GAB+"hall1",
		"down" : GAB+"vestry"
	]));

   set_door("door",GAB+"hall1","east","loviatar_holy_symbol");
   set_door_description("door","The door is made of stout oak "+
   	"and is banded in iron.\n");
   set_string("door","open","The door opens with a creak into a hallway.\n");
   set_locked("door",0,"lock");
	(GAB+"hall1")->set_locked("door",0,"lock");
 	set_open("door",1);
 	(GAB+"hall1")->set_open("door",1);
	
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
