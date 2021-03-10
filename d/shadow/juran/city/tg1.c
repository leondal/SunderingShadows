#include <std.h>
#include "../juran.h"

inherit ROOM;

void create(){
	::create();
    	set_name("Juran thieves guild");
    	set_short("Juran thieves guild");
   	set_terrain(STONE_BUILDING);
   	set_travel(PAVED_ROAD);
    	set_long(
		"You are in the underground hideout of the local thieves.  "+
		"In these rooms thieves meet to plan out their dark deeds and "+
		"boast of their exploits.  The room is darkened and the shadows "+
		"move and sigh.  Many nefarious individuals frequent these rooms.  "+
   "The room itself is very opulent compared to the surroundings you "+
		"passed through to get into here.  Overpadded leather chairs sit "+
		"against the walls and velvet curtains of rich, vibrant colors add "+
   "to the decor.  There is a common looking tapestry hanging in the "+
		"southwest corner of the room.\n"
    	);
    	set_property("indoors",1);
    	set_property("light",-2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    	set_listen("default","You can hear a rustling in the shadows.");
    	set_smell("default","The smell of blood and alcohol fills the air.");
    	set_items( ([
		({"chair","chairs","overpadded chairs","overpadded chair"}) : "The "+
			"chairs look very comfortable and soft.",
		({"shadows","shadow"}) : "The dark shadows defy your attempts to "+
			"look into them.  A soft chuckle comes from the darkest shadow.",
		"tapestry" : "The tapestry depicts a common rustic setting.  The "+
			"tapestry is very normal looking and made up of drab colors.  "+
			"The tapestry shifts a bit from unfelt breezes.\n"
    	]) );

	set_search("tapestry","The tapestry moves to an unfelt breeze, maybe "+
		"the tapestry covers an exit to another room.\n");

    	set_exits(([
    		"out" : JROOMS+"a3",
    		"tapestry" : JROOMS+"tg2"
    	]));

     	set_invis_exits(({"tapestry"}));
}