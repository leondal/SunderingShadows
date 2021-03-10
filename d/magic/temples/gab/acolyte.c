//Coded by Diego//

#include <std.h>
#include "../loviatar.h"

inherit VAULT;

void create(){
	::create();
	set_name("acolyte's room");
   set_short("acolyte's room");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"This cold miserable room is sparsely furnished with a "+
   	"few %^RESET%^%^ORANGE%^wooden bunks%^BOLD%^%^BLACK%^, with "+
   	"no matresses, a small shrine to %^RED%^Loviatar%^BLACK%^, "+
   	"and a rack of well worn whips.  The bare %^RESET%^%^ORANGE%^wooden floor "+
   	"%^BOLD%^%^BLACK%^is uneven, unpolished, and unfinished.  "+
   	"The meager %^YELLOW%^light %^BLACK%^provided from a couple "+
   	"of black candles make seeing difficult."+
   	"%^RESET%^\n"
   );
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","%^BOLD%^%^GREEN%^Something smells slightly "+
   	"putrid here.%^RESET%^");
   set_listen("default","You hear the subdued shuffling of barefooted "+
   	"acolytes around the room.");
   set_items(([
   	({"bunks","bunk"}) : "The plain bunks where the acolytes "+
   		"are required to sleep do not look like they provide "+
   		"much comfort.  The bare wood is devoid of any kind of "+
   		"bedding and a variety of pegs, notches, and bumps have "+
   		"been added to the surface to make sleeping on them a "+
   		"very uninspiring prospect.\n",
   	"shrine" : "A simple shrine to Loviatar is nestled in a small alcove.\n",
   	"floor" : "The floor is unpolished, uneven, unfinished, and "+
   		"with a number of cracks that significantly raise the chances "+
   		"of getting splinters if you were to walk across it barefoot.  "+
   		"There are some dark stains on the floor around the area of the shrine.\n",
   	({"spots","stains","spot","stain"}) : "The dark spots on the "+
   		"floor look like drops of dried blood.  You notice that there "+
   		"is a concentration of them right in front of the shrine.\n",
   	({"candle","candles"}) : "The dark stuff these candles are made of "+
   		"gives off a distinctly unpleasant smell and the small flames "+
   		"sputter constantly seeming to have to struggle to stay alight.\n",
   	({"whips","whip"}) : "The whips on the rack look worn and well "+
   		"used.  Their mottled appreance suggests that the aged leather "+
   		"has tasted blood on many occassions.\n"
  	]));
   set_exits(([
		"north" : GAB+"hall1"
	]));

  	set_door("pine door",GAB+"hall1","north","loviatar_holy_symbol");
   set_door_description("pine door","The door is made of pine "+
   	"and is banded in iron.\n");
   set_string("pine door","open","The door opens into a hall.\n");
 	set_open("pine door",1);
}
void reset(){
	::reset();
	if(!present("monster")){
//                new(GAB+"npc_acolyte")->move(TO);
//                new(GAB+"npc_acolyte")->move(TO);
	}
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
