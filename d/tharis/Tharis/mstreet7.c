//mstreet1.c

#include <std.h>

inherit VAULT;

void create(){
	::create();
	set_terrain(CITY);
	set_travel(PAVED_ROAD);
	set_property("no sticks", 1);
	set_property("light",2);
	set_property("indoors",0);
	set("short","Middle street");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^Middle Street%^RESET%^
This street is lined by the houses of the moderately well to do. 
Clean streets are around you. Fine houses crowd you in. But you notice
that they are crowded. That's the main difference between these and the
wealthy houses. The street is lined with locked doors. To the north 
the stout city wall stands before you.
	
OLI
	);
	set_exits(([
		
		"south":"/d/tharis/Tharis/mstreet6"
		]));
	
	set_items(([
		"wall":"In large letters someone has written %^BOLD%^KILL ELVES%^RESET%^."]));
	
	set_listen("default","You hear only the sounds of the city.");
	set_smell("default","Wafts of baking and house hold smells circle you.");
}

void init(){
	::init();
	
	do_random_encounters(({"/d/tharis/monsters/mugger"}),10,1);
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/