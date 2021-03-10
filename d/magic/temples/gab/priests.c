//Coded by Diego//

#include <std.h>
#include "../loviatar.h"

inherit VAULT;

void create(){
	::create();
	set_name("priest's room");
   set_short("priest's room");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"This room is dark, but spacious and comfortably appointed.  "+
   	"There are enough chairs for up to eight people to be seated for "+
   	"discussions, rest, or prepare for the worship of "+
   	"%^RED%^Loviatar's glory%^BLACK%^.  There is a shrine to "+
   	"the goddess in a small alcove recessed into the wall about "+
   	"four feet above the floor and the bare floorboards in front "+
   	"of it are stained with many spots of some %^RESET%^%^RED%^dark "+
   	"liquid%^BOLD%^%^BLACK%^.  Elsewhere in the room, thick rugs cover "+
   	"the floor and there is a small hearth in front of an open fireplace.  "+
   	"A metal bucket beside the fireplace holds a number of pokers and there "+
   	"is a basket of coal on the other side."+
   	"%^RESET%^\n"
   );
   set_property("indoors",1);
   set_property("light",2);
   set_smell("default","The scent of burning coal drifts through the room.");
   set_listen("default","You can hear the low crackling of the fire and "+
   	"other muffled sounds from the temple.");
   set_items(([
   	({"chair","chairs"}) : "Simple padded chairs with adorned with "+
   		"odd looking studs on the seats and the backs.\n",
   	"shrine" : "A likeness of Loviatar's beautiful face cavred from "+
   		"ivory, or perhaps bone, sits before an small offering bowl.  "+
   		"It is decorated with small stones of onyx and jet and the light "+
   		"of a nearby candle glints from the gems.  The expression on the "+
   		"icon's face is one of terrifying cruelty mixed with unmistakable "+
   		"allure and the promise of dark pleasure.\n",
   	"floor" : "Most of the floor is covered with elagantly arranged, "+
   		"deep red, rugs, but the area in front of the shrine is clear.  "+
   		"Looking closely, the dark stains in front of the shrine appear "+
   		"to be dried blood.\n",
       ({"hearth","fireplace"}) : "The stone hearth prevents any embers from "+
   		"the fire from setting fire to the room.\n",
   	"fire" : "Dully glowing hot coals sit in the hearth, heating the "+
   		"room to a slightly uncomfortable temperature.\n",
   	"bucket" : "The various pokers and implements used to tend the fire "+
                "sit in the bucket.  You notice that some of them have strangely "+
                "shaped endings, with no obvious use you can detect.  Some look "+
                "like that could be used as a branding iron.\n",
   	"basket" : "A tall strong wicker basket holds a plentiful supply of "+
   		"coals for the fire.\n"
  	]));
   set_exits(([
		"west" : GAB+"hall2"
	]));
	
	set_search("shrine","%^BOLD%^%^BLACK%^Just curious here, but "+
		"does it seem like a good idea to be searching through a "+
		"shrine to the %^RED%^goddess of pain and suffering%^BLACK%^?  "+
		"In any case the offering bowl is empty at present.\n");
		
  	set_door("door",GAB+"hall2","west","loviatar_holy_symbol");
   set_door_description("door","The door is made of stout oak "+
   	"and is banded in iron.\n");
   set_string("door","open","The door opens into a hall.\n");
 	set_open("door",1);
}
void init() {
  	::init();
  	add_action("sit_em","sit");
}
int sit_em(string str) {
  	if(!str) {
   	tell_object(TP,"Sit where?");
      return 1;
   }
  	if(str == "chair" || str == "on chair"){
   	tell_object(TP,"%^BOLD%^As you sit down you realize that "+
   		"there are hard studs in the padding of the seat and the "+
   		"back of the chair which will make your sitting less comfortable "+
   		"than you originally thought.\n%^RESET%^");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" sits in one of the many chairs "+
      	"and fidgets to get comfortable.\n%^RESET%^",TP);
		return 1;
	}
}
void reset(){
	::reset();
	if(!present("monster")){
//                new(GAB+"npc_priest")->move(TO);
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
