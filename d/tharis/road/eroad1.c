#include <std.h>

inherit ROOM;


void create(){
	::create();

   set_terrain(CITY);
   set_travel(DIRT_ROAD);
	set_property("light",2);
	set_property("indoors",0);
	set("short","Road to the east of Tharis");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^The Road leading east from Tharis%^RESET%^
The east gates of Tharis loom to the west. These gates are the only ones 
through which elves are allowed to pass. To the east lies the road which 
serves partially as a border between the great forest to the north and
the mountains which loom large to the south. Tharis is a rich city. You
know that rich cities bring wealth, but with that wealth comes thieves in
great quantity.
OLI
	);
	set_exits(([
		"west":"/d/tharis/Tharis/estreet10",
           "east":"/d/tharis/road/eroad2",
		"north":"/d/tharis/road/road30"
	]));
	set_items(([]));
	set_smell("default","Hints of the forest to the north reach your nostrils.");
   set_listen("default","The sounds of people milling about reach your ears.");
	set_post_exit_functions(({"west"}),({"push_elf"}));
}


void reset(){
	::reset();
	if(!present("guard")){
		new("/d/tharis/monsters/eguard")->move(TO);		
		new("/d/tharis/monsters/eguard")->move(TO);
	}
}

void push_elf(){
   if(avatarp(TP)) return 1;
   if(TP->query_invis()) return 1;
   if((string)TP->query_race() != "elf" && (string)TP->query_race() != "drow") return;
	
	if(present("guard",ETP)) {
		write("%^BOLD%^%^RED%^The guard yells at you: Hey you into the registration office!");
		tell_room(ETP,"%^BOLD%^%^RED%^The guard yells at "+TPQCN+":
Hey you into the registration office!",TP);
		write("%^BOLD%^The guard shoves you roughly into the building to the south.");
		tell_room(ETP,"%^BOLD%^The guard shoves "+TPQCN+" roughly to the south",TP);
		TP->force_me("south");
	}
}
