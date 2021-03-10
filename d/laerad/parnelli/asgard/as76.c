//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create() {
    ::create();
/*
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_name("Asgard's component shop");
    set_short("Asgard's component shop");
    set_long(
	"%^BOLD%^Asgard's component shop%^RESET%^
You have walked into a mage's component shop.  The room glows with a "+
	"magical radiance.  Special items from all over the realm line the "+
	"walls.  Mages use these objects for the casting of their spells.  "+
	"There is a counter at the south end of the room where a "+
	"shopkeeper waits to help you."
    );
    set_property("light",2);
    set_property("indoors",1);
    set_smell("default","The room smells of herbs and potions.");
    set_listen("default","The store is very quiet.");
*/
   set_long(::query_long()+"\nOne wall full of shelves still stands here, "
      "but anything that was one them has been cleared out.  The remnants "
      "of diamond dust and fireflies reveals this to be the remains of "
      "Asgard's components shop.\n");
    set_exits( ([
	"west":"/d/laerad/parnelli/asgard/as71"
    ]) );
}
/*
void reset(){
    ::reset();
    if(!present("neptune")){
	new("/d/laerad/mon/neptune")->move(this_object());
    }
}
*/