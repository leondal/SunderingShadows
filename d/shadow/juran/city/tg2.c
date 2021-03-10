#include <std.h>
#include "../juran.h"

inherit ROOM;

void create(){
    	::create();
    	set_name("The Fence");
    	set_short("The Fence");
   	set_terrain(STONE_BUILDING);
   	set_travel(PAVED_ROAD);
    	set_long(
		"The dark little room has a goblin sitting in the back corner "+
		"putting various items into his many sacks.  The room itself "+
		"is non-descript and out of the way.\n"+
		"<help fencing> would be a useful command here.\n"+
		"To see what is for sale type <list>."
    	);
    	set_property("indoors",1);
    	set_property("light",-2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    	set_property("no attack",1);
    	set_listen("default","You can hear the chatter of a few people "+
    		"browsing around the store.");
    	set_smell("default","Rust, oil, and the gentle scent of candles "+
    		"heavily taint the air.");
    	set_exits(([
    		"out" : JROOMS+"tg1"]));
}
void reset(){
    	::reset();
  	if(!present("glitter"))new(JMONS+"glitter")->move(TO);
}
