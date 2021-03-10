//church.c

#include <std.h>

inherit "/std/church";

void create(){
	::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
	
	set_properties((["light":2,"indoors":1,"no attack":0]));
	set("short","The church of Tharis");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^The church of Tharis%^RESET%^
This building has a high vaulted ceiling is adorned richly, reflecting
the gifts given by individual members. The pews are made of a fine dark
wood. The stained glass windows let colored light sparkle from the pews.
The gold that adorns the altar sparkles from new polish. The white washed
walls have the symbols of various gods hanging from them. You feel at peace
here.
OLI
	);
	set_exits(([
		"west":"/d/tharis/Tharis/mstreet1"
		]));
	set_items(([
		"pews":"These are made of a shiny dark wood. Obviously very expensive.",
		"ceiling":"Lined with fine wood elaborate designs of gods and goddesses span the ceiling.",
      "altar":"Lined with gold, you wonder how anyone can worship at such a gaudy object."
		]));
	
   set_smell("default","Incense and a sweetness tickle you nose.");
   set_listen("default","A low murmur of prayer echoes through the hall.");
}
