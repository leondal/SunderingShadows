#include <std.h>
#include "../juran.h"

inherit ROOM;

void create(){
    	::create();
    	set_name("Floor 3 of the Mage Tower");
    	set_short("%^BOLD%^%^BLACK%^Third floor of the Mage Tower%^RESET%^");
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
    	set_long(query_short() + "\n" +
		"%^MAGENTA%^You are on the third floor of Juran's mage tower. The room "+
   "is, like the rest of the tower, nothing but walls of gray "+
      "stone. There is a staircase leading down here and an archway to the north that leads into a store."
    	);
    	set_property("light",-2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    	set_property("indoors",1);
    	set_smell("default","You can smell the dusty gray walls throughout the room.");
    	set_listen("default","You can hear the busy shuffling of other mages.");
    	set_items( ([
        	({"walls","wall","stone","gray stone"}):"The walls are "+
            	"made of a cold and featureless gray stone.",
        	({"ceiling","up","hole","circle"}):"You see a wide "+
            	"circular hole piercing through the stone ceiling "+
            	"from the room above.",
        	({"floor","down"}):"The floor is solid gray and smooth, "+
            	"completely barren.",
        	({"archway","archways"}):"The archways are made of smooth "+
            	"gray stone bricks that line the outline of the opening.",
        	({"store","south","spell store","shop","spell shop"}):
            	"This store is often too expensive for what it sells.  "+
            	"Yet spells are the core component to a mage's power, "+
            	"so such a supplier is valuable in a mage tower, and "+
            	"therefore wanted."
    	]) );
    	set_exits( ([
	    	"store" : JROOMS+"spell_store",
        	"down" : JROOMS+"mt2"
    	]) );
}
