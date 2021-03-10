//Coded by Diego//

#include <std.h>
#include "../loviatar.h"

inherit VAULT;

void create(){
	::create();
	set_name("vestry");
   set_short("vestry");
   set_long(
   	"%^RESET%^%^ORANGE%^"+
   	"This small oak panelled room is decorated with a "+
   	"small %^BOLD%^%^WHITE%^ivory statue %^RESET%^%^ORANGE%^on "+
   	"a pedestal at the far end.  On either side of the room "+
   	"are racks containing the %^BOLD%^%^BLACK%^ceremonial "+
   	"vestments %^RESET%^%^ORANGE%^used by the Loviatan "+
   	"priesthood during their ritual worship.  Just behind "+
   	"one of the racks of cloths is a narrow spiraling set "+
   	"of wooden stairs leading upward with a door at the top."+
   	"%^RESET%^\n"
   );
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","%^BOLD%^%^CYAN%^You can smell the heavy "+
   	"scent of wood and the faint aroma of mothballs.%^RESET%^");
   set_listen("default","%^YELLOW%^The screaming is a little "+
   	"fainter in here, the sound is muffled by the panelled walls.%^RESET%^\n");
   set_items(([
   	"statue" : "Peering closely at the statue you can see the white "+
   		"ivory is flecked with red.  The statue depicts a "+
   		"half-naked man, tied to a pole with his hands above "+
   		"hit head.  His face reflects pain and his skin is marked "+
   		"across the chest and belly with nine parallel angry red welts.\n",
   	({"rack","vestments","robes"}) : "The priests' robes are cut "+
   		"from coarse black silk with varied designs.  The designs "+
   		"could mean alomost anything from personal choice to rank "+
   		"within the church.  Most carry the mark of the nine-tailed "+
   		"whip somewhere in the design.\n",
   	"stairs" : "The plain stairs lead up and end in a small door.\n"
  	]));
   set_exits(([
		"south" : GAB+"hall",
		"up" : GAB+"stairs"
	]));

  	set_door("wooden door",GAB+"hall","south","loviatar_holy_symbol");
   set_door_description("wooden door","The door is made of stout oak "+
   	"and is banded in iron.\n");
   set_string("wooden door","open","The door opens with a creak into a hall.\n");
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
