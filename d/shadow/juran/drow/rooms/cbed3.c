//Coded by Diego//

#include <std.h>
#include "../jdrow.h"

inherit VAULT;

void create(){
  	::create();
  	set_name("torture chamber");
   set_short("Torture Chamber");
   set_long(
    	"%^RED%^"+
    	"This seems to be a guest room of another sort.  In the middle of the "+
    	"room two %^BOLD%^%^BLACK%^chains %^RESET%^%^RED%^hang from the ceiling "+
    	"with %^ORANGE%^leather %^RED%^cuffs at the end of each.   The "+
		"%^BOLD%^%^BLACK%^chains %^RESET%^%^RED%^are attached to two eyelets in "+
		"the ceiling and run to a wench with a crank located on the west wall.  "+
		"In the northeast corner is the room is a bed. The bed looks like it could "+
		"be very comfortable had you not noticed the %^BOLD%^%^BLACK%^chains "+
		"%^RESET%^%^RED%^attached to each corner of the bed with %^ORANGE%^leather "+
		"%^RED%^cuffs at the end.  Along the north wall is a wooden table with "+
		"ropes at each end.  The table has a small wench with a crank on only "+
		"one end.  This is what you have come to realize is a rack and it is big "+
		"enough to work its charm on anything from goblin size to firbolg.  In "+
		"the southwest corner of the room implements such as %^BOLD%^knives, "+
		"pokers, tongs, clamps, and whips%^RESET%^%^RED%^ are suspended from the "+
		"wall all very neatly.  Below the implements is a brazier and next to the "+
		"brazier is a bucket full of %^BOLD%^%^BLACK%^coal %^RESET%^%^RED%^for "+
		"%^BOLD%^firing %^RESET%^%^RED%^up the brazier.  Curiously this room has "+
		"sconces in each wall to hold %^YELLOW%^torches%^RESET%^%^RED%^.  The "+
		"room is very clean and the items are all free from reminders of past "+
		"occupants.\n"+
		"%^RESET%^"
   );
  	set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
 	set_property("indoors",1);
   set_property("light",-3);
   set_smell("default","The room while clean has the distinct smell of "+
   	"perspiration and maybe even a trace of fear.");
   set_listen("default","The room is quiet at this time although you almost "+
   	"imagine you can hear screams.");
   set_items(([
     	"moss" : "Gray and benign it looks as if its only purpose is to cover "+
     		"the floor.\n",
     	({"walls","wall"}) : "The walls are smooth and gray and the stonework "+
     		"looks to be of dwarven quality.\n",
     	"floor" : "Covered with a gray moss the floor is smooth, level, and "+
     		"free of dirt and debris.\n",
     	"ceiling" : "About 10 feet overhead the ceiling looks to be smooth and even.\n",
     	"bed" : "The bed looks comfortable and is large enough for two people.  "+
     		"You notice attached to each corner of the bed is a chain and the "+
     		"chains each end in a leather cuffs.\n",
     	"rack" : "This table has ropes at one end for securing the feet.  The "+
     		"rope at the other end attaches to the victim's wrists and to a "+
     		"wench.  The wench can then be turned with a crank and the rope is "+
     		"pulled taut stretching the victim in a most uncomfortable manner.  "+
     		"The table is large enough to handle victims from goblin size to "+
			"firbolg\n",
     	({"implements","knives","pokers","tongs","clamps","whips"}) : "Various "+
     		"items used in the pursuit of causing pain to another are "+
     		"hanging collectively in the southwest corner.  The collection "+
     		"seems to be very complete with every contingency of agony "+
     		"considered.\n",
     	"brazier" : "Coal can be lit in the brazier to create a small fire.  It "+
     		"is more likely that fire is used to heat the pokers hanging nearby "+
			"rather than to heat the room.\n"
	]));
   set_exits(([
		"south" : DROOMS+"cdd3"
   ]));

   set_door("north room door",DROOMS+"cdd3","south","obsidian key");
   set_door_description("north room door","This is a normal looking wooden door "+
   	"with a simple lock.");
   set_string("north room door","open","You open the door into a dark hallway.\n");

}