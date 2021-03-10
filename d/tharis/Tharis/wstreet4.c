//wstreet4.c

#include <std.h>

inherit CROOM;

void create(){
    set_monsters(({"/d/tharis/monsters/patrol"}),({ random(3) }));
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
	::create();
	
	set_property("light",2);
	set_property("indoors",0);
	
	set("short","The street on the West of Tharis");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^West street through Tharis%^RESET%^
This is the west street through Tharis. To the west will eventually
be the West gate. To the east is the market place. The streets here
are lined with storage rooms and warehouses. Here is where the wealth
of Tharis is stored while it's readied for the trip north to Shadow.
occasionally you see a well guarded wagon load go by. But mostly the
caravans have stopped because of the troubles caused by the recent raids. 
You are not really worried about pick pockets here but you are worried a 
little about muggers. 
	To the north is a small street leading between warehouses.
	
OLI
	);
	set_exits(([
		"east":"/d/tharis/Tharis/wstreet3",
		"west":"/d/tharis/Tharis/wstreet5",
		"north":"/d/tharis/Tharis/warestreet1"
		]));
	set_items(([]));
	set_smell("default","The unique smells of the city attack you.");
	set_listen("default","The city bustles around you.");
}

/* changed to using CROOM since they wander
void reset(){
	int i,j;
	::reset();
	
	if(!present("patrol")){
		j = random(2);
		for(i=0;i<j;i++)
			new("/d/tharis/monsters/patrol")->move(TO);
	}
	
	if(!present("citizen")){
		j = random(2);
		for(i=0;i<j;i++)
			new("/d/tharis/monsters/citizen")->move(TO);
	}
}
*/

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/