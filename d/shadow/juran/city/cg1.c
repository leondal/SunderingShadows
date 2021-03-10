#include <std.h>
#include "../juran.h"

inherit VAULT;

void create(){
    	::create();
    	set_name("Dark Clerics guild");
    	set_short("Dark Clerics guild");
    	set_long(
   "You are in a room that is darkly adorned and smells of brimstone.  "+
		"This hall serves as a guild meeting hall for all the priests "+
		"of this city and those who would visit from other places.  "+
		"Many statues of the darker gods adorn the room.  The floor is "+
   "made from stone and looks to be cleaner than most of the other "+
		"buildings you have been in.  Torches light the room casting "+
		"ominous shadows about the statues."
    	);
    	set_property("indoors",1);
    	set_property("light",-2);
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    	set_listen("default","You can hear the faint prayers of other priests.");
    	set_smell("default","The smell of brimstone is strong.");
    	set_exits( ([
		"northwest" : JROOMS+"healer",
		"southeast" : JROOMS+"cg2",
    	]) );
}
