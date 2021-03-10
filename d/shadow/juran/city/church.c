#include "/d/shadow/room/shadow.h"
#include "../juran.h"

inherit "/std/church";

void create() {
   	::create();
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
    	set_short("Juran Church");
    	set_long("%^BOLD%^You are in the dark church of Juran.%^RESET%^\n"+
		"This huge ruined church was originally built by the good "+
		"people of Juran before the city was taken by evil.  In this "+
		"church the dead can come to pray for resurrection."
	);
    	set_exits(([
		"northwest" : JROOMS+"r42"
	]));
	remove_property("light");
    	set_property("light", -2);
    	set_property("indoors", 1);
    	set_items(([
    		"church" : "This building is in ruins, but still provides services.", 
          	"sign":"You should read it.",
	  	"chamber" : "People come here to pray for resurrection "+
	    		"when they die."
	]));
    	set_listen("default", "You hear the faint sounds of chanting "+
    		"from the back of the church.");
    	set_smell("default","You smell the odor of a pungent incense and sweat.");
}
void reset(){
   ::reset();
   if(!present("shade")) new (JMONS+"jshade")->move(TO);
}
