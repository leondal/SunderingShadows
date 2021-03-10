//Coded by Diego//

#include <std.h>
#include "../mos.h"
inherit VAULT;

void create(){
    	::create();
   	set_short("Lounge");
    	set_long(
    		"%^RESET%^%^CYAN%^"+
    		"This room is large and luxuriously decorated.  There are no less than "+
    		"six overstuffed leather chairs and a couch arranged about the room to "+
    		"maximize comfort, conversation and meditation. There are small tables "+
    		"at each end of the couch and small tables next to each chair.  Large, "+
    		"thick, expensive, woven rugs are spread through the room to provide even "+
    		"more comfort for the occupants.  There are colorful, well "+
    		"made, tapestries on the walls which show different individuals, some "+
    		"mages and some obviously not, engaged in various battles.  Some of the "+
    		"deeds you think you have heard tales of.  There is a fireplace in the "+
    		"west wall.  Above the fireplace you notice a plaque.  The plaque is "+
    		"large and glowing with its own light.\n"+
    		"%^RESET%^"
    	);
    	set_property("indoors",1);
    	set_property("light",2);
    	set_smell("default","The room smells of old tobacco smoke mingled with new "+
    		"and traces of other herbs that have been smoked as well.");
    	set_listen("default","You hear traces of past present and future conversations.");
    	set_items(([
        	({"chair","chairs"}) : "There are no less that six chairs here, four of "+
        		"normal size, one that is very large, and one that is small.  No "+
        		"expense was spared in purchasing these chairs so that comfort was "+
        		"maximized.\n",
        	({"table","tables"}) : "The tables are small and are placed for the "+
        		"convenience of the occupants of the room.  Not large enough to hold "+
        		"many items, they are just the right size to hold a drink and something "+
        		"to eat.\n",
		"fireplace" : "The small fireplace provide warmth for the room a.  No smoke or "+
			"smell is detected from the fireplace and the wood inside does not "+
			"appear to be consumed in the flames.\n",
		({"tapestries","tapestry"}) : "The tapestries are very colorful and very "+
			"well done.  Each one depicts an individual that is engaged in a "+
			"battle or a deed that looks momentous in scope.\n",
		"plaque" : "The plaque has writing on it and is made of brass, edged with "+
			"gold and platinum and framed in black walnut.\n"

     	]));
     	set_exits(([
   		"west" : MROOMS+"moscom"
 	]));

    	set_door("black door",MROOMS+"moscom","west","guild earring");
    	set_door_description("black door","This is a normal "+
    		"looking wooden door painted %^BOLD%^%^BLACK%^black %^RESET%^with "+
    		"a simple lock.");
   	set_string("black door","open","You open the door "+
   		"noiselessly into the antechamber.\n");
}
void init() {
  ::init();
  add_action("read","read");
}
int read(string str) {
  if(!str) {
        tell_object(TP,"Read what?");
        return 1;
    }
  if(str == "plaque"){
     write("%^BOLD%^%^BLUE%^"+
		"The plaque reads in bold and flowing script: \n"+
		"\n"+
		"%^YELLOW%^This mage lab is one of the marks left by \n"+
		"the last of the %^BOLD%^%^RED%^Crimson Daggers%^RESET%^, "+
		"%^MAGENTA%^Vethor%^YELLOW%^,\n"+
		"as a mutually beneficial gift to the mages of his \n"+
		"guild, the Tempered Blades.%^RESET%^");
     return 1;
     }
}
