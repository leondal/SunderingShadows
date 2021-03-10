#include <std.h>

inherit ROOM;


void create(){
	::create();
	set_terrain(CITY);
	set_travel(PAVED_ROAD);

	set_property("light",2);
	set_property("indoors",0);
	set("short","Main street through the elven quarter");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^Main street through the elven quarter%^RESET%^
The east gates of Tharis loom to the east. These gates are the only ones 
through which elves are allowed to pass. Guards stand here to help regulate
flow and direct the appropriate people to the registration room to the
south. The elven quarter is the ignored and the hated part of Tharis.
Despite the neglect by the city you can see through the dirt the fine elven
workmanship. You wonder why anyone would lock this away.
OLI
	);
	set_exits(([
		"west":"/d/tharis/Tharis/estreet9",
             "east":"/d/tharis/road/eroad1",
		"south":"/d/tharis/Tharis/reg",
		"up":"/d/tharis/Tharis/tower9"
	]));
	set_items(([]));
   set_smell("default","The sweet fragrances of nature are strangely present here in the city.");
	set_listen("default","Mumbles and whispers reach your ears.");
}


void reset(){
	::reset();
	if(!present("guard")){
		new("/d/tharis/monsters/eguard")->move(TO);		
		new("/d/tharis/monsters/eguard")->move(TO);
	}
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/