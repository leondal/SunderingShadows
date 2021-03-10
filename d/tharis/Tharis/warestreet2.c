//warestreet1.c

#include <std.h>

inherit ROOM;

void create(){
	::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
	
	set_properties((["indoors":1,"light":2]));
	set("short","Ware street");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^Ware Street%^RESET%^
To each side of you rise large warehouses and minor places of operations.
Not an extremely clean area, the warehouse district leaves much to be
desired for those who enjoy the finer beauties of life. This however, as
many people realize, is where the wealth of Tharis lies. In these
warehouses are stored the gold, the copper, the silver, the lumber and
everything else that the city sends to Shadow and to the Tsarvan Empire.
Few people walk through here. Only the private security and the occasional
drunk wonder these streets.
OLI
	);
	set_items(([
		"warehouses":"These large builds will and have inside them great riches."
		]));
	
	set_exits(([
		"south":"/d/tharis/Tharis/warestreet1",
            "north":"/d/tharis/Tharis/warestreet3"
		]));
	set_smell("default","A dusty and dirty area brings dust and dirt.");
   set_listen("default","An occasional drunk sings loudly and a security guard yells.");
}

void init(){
	::init();
	
	do_random_encounters(({"/d/tharis/monsters/security"}),30,2);
	}
