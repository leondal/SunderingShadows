//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit VAULT;

void set_rope(int rope);

int rope_present;

void create(){
	::create();
	set_name("laboratory");
   set_short("Laboratory");
   set_long(
   	"%^BOLD%^%^GREEN%^"+
   	"The tunnel has led you to a room that is deep within the bowels of the "+
   	"earth.  The room is very large and looks very used.  The entire south "+
   	"wall is full from floor to ceiling with bookshelves almost overloaded "+
   	"with books.  A workbench dominates the north wall.  The middle of the "+
   	"floor is left open and a pentagram is painted there in red.  Along the "+
   	"east wall is a large shelf that contains various, potions, powders, and "+
   	"glassware.\n"+
   	"%^RESET%^"
   	);
  	set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  	set_property("indoors",1);
   set_property("light",-3);
   set_smell("default","The room has the odor of chemical mixtures and brimstone.");
   set_listen("default","The room is as silent as a tomb.");
   set_items(([
     	"moss" : "Gray and benign it looks as if its only purpose is to cover "+
     		"the floor.\n",
     	({"walls","wall"}) : "The walls are smooth and gray and the stonework "+
     		"looks to be of dwarven quality.\n",
     	"floor" : "Covered with a gray moss the floor is smooth, level, and free "+
     		"of dirt and debris.\n",
     	"ceiling" : "About 10 feet overhead the ceiling looks to be smooth and even.\n",
		"workbench" : "On the workbench you can see many devices that you can "+
			"only imagine their usage.  While the workbench has many items "+
			"you would expect a mage to use it also seems to have items of a "+
			"more mundane nature.  You see items used for sharpening edged "+
			"weapons, tools that might be used to open locks, and items used "+
			"to mend and oil leather armor.  One stool is at the bench for "+
			"the use of the owner.\n",
		"bookshelf" : "The shelf is loaded from top to bottom with books.  The "+
			"language the books are written in are drow, so unless you can "+
			"speak that language you will get no use from trying to read them.\n",
		"pentagram" : "A large pentagram dominated the center of this "+
			"room.  The lines of the pentagram are painted in what looks "+
			"to be blood, but hopefully is only paint.  In the protected "+
			"center of the pentagram is a small brazier, but nothing burns "+
			"in it at this time.  Intricate symbols and glyphs decorate the "+
			"outer edge of the pentagram lending great strength to it "+
			"protective capabilities.\n",
		"shelf" : "This set of shelves is filled with more potions and reagents "+
			"along with glassware used in performing experiments.\n"
   ]));

   set_climb_exits((["climb":({DROOMS+"cbed4",20,6,100})]));
   set_fall_desc("%^BOLD%^%^RED%^You fall a long way tumbling into the "+
		"darkness bouncing off the sides of the tunnel until you come to a sudden "+
		"and painful stop at the bottom!%^RESET%^\n");

	set_search("shelf","You find that the shelf moves when you start searching "+
     		"it.  Maybe it can be moved so you can see what's behind it.\n");

	set_trap_functions(({"shelf"}),({"alarm_em"}),({"move"}));
}
void init() {
  	::init();
  	add_action("move","move");
}
int move(string str) {
   if(!str) {
     	tell_object(TP,"Move what?");
     	return 1;
   }
  	if(str == "shelf"){
  		if(member_array("east",TO->query_exits()) != -1) {
      	tell_object(TP,"The shelf has already been moved!.");
         return 1;
      }
     	tell_object(TP,"You move the shelves to the side and reveal a concealed opening "+
     		"into another room.\n");
     	tell_room(ETP,""+TPQCN+" moves the shelves to the side revealing an opening into "+
     		"another room.\n",TP);
      add_exit(DROOMS+"lab1","east");
	return 1;
	}
}
//not meant to hurt..meant to scare player and alert occupant//

int alarm_em(string str){
	tell_object(TP,"%^BOLD%^%^RED%^As you move the shelf you hear a click.%^RESET%^\n");
	tell_room(ETP,"You hear a tiny click.",TP);
	TP->force_me("emote looks concerned suddenly.");
	TP->force_me("emote gulps.");
	tell_room((DROOMS+"lab1"),"%^BOLD%^%^RED%^A bell rings four times.",TP);
	return 0;
}