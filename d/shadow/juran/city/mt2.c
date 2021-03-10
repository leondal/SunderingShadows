#include <std.h>
#include "../juran.h"

inherit VAULT;

void create(){
    	::create();
    	set_name("Floor 2 of Mage Tower");
    	set_short("%^BOLD%^%^BLACK%^Second floor of the Mage Tower%^RESET%^");
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
    	set_long(query_short() +
		"\n%^MAGENTA%^You are on the second floor of Juran's mage tower. "+
		"The room is, like the rest of the tower, nothing but "+
		"walls of gray stone. A staircase leads both up and down "+
		"from here and you see a door to the north."
    	);
    	set_property("light",-2);
    	set_property("indoors",1);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
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
    	]) );
    	set_exits( ([
        	"down" : JROOMS+"mt1",
     		"north" : JROOMS+"lab",
        	"up" : JROOMS+"mt3"
    	]) );
    	set_door("door",JROOMS+"lab","north",0);
}
void reset(){
    	::reset();
    	if(!present("carver"))new(JMONS+"carver")->move(TO);
}
