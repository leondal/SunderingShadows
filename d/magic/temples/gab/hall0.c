//Coded by Diego//

#include <std.h>
#include "../loviatar.h"

inherit VAULT;

void create(){
	::create();
	set_name("south hall");
   set_short("south hall");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"Recessed from the temple proper this small "+
   	"hall ends in an wooden door to the south."+
   	"%^RESET%^\n"
   );
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","%^BOLD%^%^CYAN%^The air smells faintly "+
   	"of %^WHITE%^candles%^CYAN%^, %^RESET%^%^RED%^blood "+
   	"%^BOLD%^%^CYAN%^and %^MAGENTA%^incense%^CYAN%^.%^RESET%^");
   set_listen("default","%^YELLOW%^You hear tortured screams "+
   	"from deep within the temple.%^RESET%^\n");
   set_items(([
  	]));
   set_exits(([
		"north" : LOV+"loviatar",
		"south" : GAB+"library"
	]));

   set_door("wooden door",GAB+"library","south","loviatar_holy_symbol");
   set_door_description("wooden door","The door is made of stout oak "+
   	"and is banded in iron.\n");
   set_string("wooden door","open","The door opens with a creak into the library.\n");
   set_locked("wooden door",0,"lock");
	(GAB+"library")->set_locked("wooden door",0,"lock");
 	set_open("wooden door",1);
 	(GAB+"library")->set_open("wooden door",1);
	
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
