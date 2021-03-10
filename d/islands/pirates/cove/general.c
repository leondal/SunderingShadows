#include <std.h>
#include <daemons.h>
#include "../piratedefs.h"
inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("The Wide Open Port");
   set_short("The Wide Open Port");
   set_long("%^BOLD%^The Wide Open Port%^RESET%^\n"
"This is a rather small room, crowded on every side with shelves and tables.  These are stacked with various "
"mundane items, many covered in a thin coat of %^ORANGE%^dust%^RESET%^.  A layer of %^BLACK%^%^BOLD%^grime "
"%^RESET%^covers almost every surface here, including the single dirty window that peers out onto the street "
"outside.");
   set_smell("default","A dusty smell permeates the air, making your nose itch.");
   set_listen("default","The murmur of customers fills your ears.");
   set_exits(([
     "southeast":COVE+"path9",
   ]));
   set_items(([
     ({"shelves","tables"}): "The small room is crowded on every side with various shelves and tables, which "
"are stacked with a variety of %^ORANGE%^dust-coated%^RESET%^ items.",
     "window": "The %^BLACK%^%^BOLD%^dirt-smudged%^RESET%^ window offers a cloudy view of the street "
"oustide.",
   ]));
}

void reset() {
   ::reset();
   if(!present("tannora")) 
	find_object_or_load(MON"tannora")->move(TO);
}
