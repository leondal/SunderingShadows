//Coded by Diego//
// Updated by Lujke 20 October 2005
// Iron door removed due to a conflict with a trap in gath_room.c

#include <std.h>
#include "../loviatar.h"

inherit VAULT;

void create(){
	::create();
	set_name("alcove");
   set_short("alcove");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"This small alcove leads to a larger room to the west, "
       +"and has an iron door set in the wall to the east."+ // Altered by Lujke 20/10/05
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
		"east" : GAB+"alcove2",
		"west" : GAB+"gath_room"
	]));
// Iron door removed by Lujke 20 October 2005
//   set_door("iron door",GAB+"gath_room","west","loviatar_holy_symbol");
//   set_door_description("iron door","This door is made of iron and is "+
//   	"large.  Heavy and able to take much damage before opening if "+
//   	"barred, the door open and move with the lightest touch.\n");
//   set_string("iron door","open","The door swings open with the lightest "+
//   	"touch into a plain room.\n");
//  set_locked("iron door",0,"lock");
//		(GAB+"gath_room")->set_locked("iron door",0,"lock");
// 	set_open("iron door",1);
// 		(GAB+"gath_room")->set_open("iron door",1);
	
//Iron door moved here by Lujke 13 November 2005 (moved to be between the alcove and
//another small alcove, rather than between the alcove and the gathering room. This was 
//due to a conflict with the trap on the trapdoor in the gathering room.

      set_door("iron door",GAB+ "alcove2","east","loviatar_holy_symbol");
   set_door_description("iron door","This door is made of iron and is "+
      "large.  Heavy and able to take much damage before opening if "+
      "barred, the door open and move with the lightest touch.\n");
   set_string("iron door","open","The door swings open with the lightest"+
      " touch into another small alcove.\n");
      set_open("iron door",1);
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
