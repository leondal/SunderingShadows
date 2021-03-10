//Coded by Diego//

#include <std.h>
#include "../mos.h"
inherit VAULT;

void create(){
    	::create();
   	set_short("%^BOLD%^%^BLUE%^Mosutha's Office%^RESET%^");
    	set_long(
    		"%^BOLD%^%^BLUE%^"+
    		"This offices furnishings, while nice, seem to be more functional than "+
		"decorative in nature.  The ancient looking desk is a little larger than "+
		"others you have seen and its accompanying chair looks comfortable, but "+
		"well worn from use.  Another chair with an ottoman sits in the far "+
		"corner.  There are stacks of tomes and books on the floor and the east "+
		"wall shelves are filled with the same.  The south wall has labeled cubby "+
		"holes which seem hardly used as there are, also, stacks of papers and "+
		"rolled up scrolls lying in the corner of the room.  On the wall behind "+
		"the desk chair there is a painting of a lovely half-elf woman.  A small "+
		"fireplace in the corner provides warmth to this room.\n"+
		"%^RESET%^"
    	);
    	set_property("indoors",1);
    	set_property("light",2);
    	set_smell("default","The smell of old, dry, crumbling parchment dominates "+
    		"this rooms and keeps you on the verge of a sneezing fit.");
    	set_listen("default","The room is very quiet.");
    	set_items(([
		({"books","book","tomes","tome"}) : "Various sizes of books and tomes "+
			"partially fill the shelves and the table in this room.  A quick "+
			"glance reveals that all the material refers to some aspect of magic, "+
			"or its use.\n",
		({"shelf","shelves"}) : "The shelves look sturdy and able to hold many "+
			"texts.\n",
		"desk" : "The desk is ancient and large.\n",
		({"chairs","chair","ottoman"}) : "The chair behind the desk looks to be "+
			"very comfortable and has seen much use.  The chair in the corner "+
			"with the ottoman looks to be used when the rooms occupant wishes "+
			"to relax.  The ottoman is plush and looks to be very comfortable "+
			"to resting feet.\n",
		"fireplace" : "The small fireplace provide warmth for the room and keeps "+
			"the air dry to protect the precious pages of the texts.  No smoke or "+
			"smell is detected from the fireplace and the wood inside does not "+
			"appear to be consumed in the flames.\n",
		({"portrait","painting"}) : "The painting has a brass plate at the bottom "+
			"with the name Ianthe engraved in a flowing script.  The portrait "+
			"itself is of a lovely young half-elven woman with long flowing "+
			"black hair and piercing blue eyes.  While looking at "+
			"the portrait from one place in the room you see the woman is "+
			"garbed in elegant evening attire, but when you move to another "+
			"location you see the painting magically change to show the same "+
			"woman wearing metal armor with her fists full of steel.\n",
		({"cubby holes","cubby hole","holes","hole"}) : "The south wall has "+
			"labeled cubby holes which seem hardly used as there are, also, "+
			"stacks of apers and rolled up scrolls laying in the corner of the "+
			"room.\n"
     	]));
     	set_exits(([
   		"southwest" : MROOMS+"mosal1"
 	]));

    	set_door("blue door",MROOMS+"mosal1","southwest","guild earring");
    	set_door_description("blue door","This is a normal "+
    		"looking wooden door painted %^BOLD%^%^BLUE%^blue %^RESET%^with a simple lock.");
   	set_string("blue door","open","You open the door "+
   		"noiselessly into an alcove just off the main library.\n");

}
