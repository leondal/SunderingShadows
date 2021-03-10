#include <std.h>
#include <daemons.h>
#include "../defs.h"


inherit ROOM;

void create() {
	::create();
	set_light(2);
	set_indoors(1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
	set_short("Shadow's General Store");
set_long("%^BOLD%^Shadow's General Store%^RESET%^
%^ORANGE%^This shop looks like it usually sells a great number of things. There are shelves and a counter all of which display a number of items used for adventures and exploring. You could probably buy or sell items here."); 
	set_items(([
		"shop" : "A general store actually.",
		"store" : "A place where you can buy and sell stuff.",
		"counter" : "An worn and battered oak counter about waist high.",
		"shelves" : "The shelves are made of oak."
	]));
	set_exits(([
		"east"	:  ROOMS"melistela"
	]));
	set_smell("default","The smell of oil lanterns and rope fills your nostrils.");
	set_listen("default","You hear the sounds from the street outside.");
 }

void init(){
      ::init();
      if(!present("pendaxin",TO))
         find_object_or_load("/d/shadow/mon/pendaxin")->move(TO);

}
