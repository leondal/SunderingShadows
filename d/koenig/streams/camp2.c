//camp2.c - Updated by Circe 11/28/03
#include <std.h>
#include "../koenig.h"
inherit ROOM;

void create()
{
	::create();
      set_terrain(VILLAGE);
      set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("The Latrines");
	set_long(
	   "Several outhouses have been built here for obvious reasons. Placing"+
	   " them southwest of the campground hopefully eliminates on the wind"+
	   " blowing the smell back to the poor campers, since the wind typically"+
	   " comes from the north. This is not the most pleasant of places, but"+
   	   " at least the stench has died down some over the years. A few flies"+
	   " still buzz about the outhouses.\n"
	);
	set_smell("default","A rather awful stench permeates the area.");
	set_listen("default","Flies buzz lazily around the outhouses.");
	set_items(([
	"flies" : "Several flies buzz around the outhouses.",
	({"outhouse","outhouses"}) : "Two large wooden outhouses have been"+
	   " constructed here. They have trenches dug beneath them for the refuse"+
	   " to fall into. They are much cleaner than simply expecting the tired"+
	   " adventurers take care of matters properly.",
	]));
	set_exits(([
	"east" : VILSTREAM"camp1",
	]));
}
