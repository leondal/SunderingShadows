//rstreet1.c

#include <std.h>

inherit ROOM;

void create(){
	::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
	set_properties((["light":2,"indoors":0]));
   set_short("A street through a wealthy area");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^End of a street through the wealthy section%^RESET%^
This is the end of this section of bricked streets that have been well cleaned. Locked doors line the streets, all adorned with the marks of wealth. The smooth 
red bricks on the road are clean and almost shine. You see an occasional coach drive by and are passed by a few security guards as you go. 
OLI
	);
	set_exits(([
		"north":"/d/tharis/Tharis/rstreet6"
		
		]));
	set_items(([]));
	
	set_smell("default","You can almost smell the flaunted money.");
	set_listen("default","Private chit chat and politenesses reach your ears.");
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/