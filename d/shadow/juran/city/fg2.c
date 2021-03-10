#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit ROOM;

void create() {
    	::create();
    	set_light(2);
    	set_indoors(1);
    	set_short("Fighter Store");
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
    	set_long(
		"%^BOLD%^WHITE%^Welcome to the Fighters Store.%^RESET%^\n"
		"The store is very large, and is very busy.  There are several "+
		"fighters lined up in a line to buy what they need.  There is "+
		"a large fighter who sits behind the counter who is taking "+
		"care of buying and selling things."
	);

    	set_items(([
    		"store" : "It is very busy, and is filled with many things.",
		"counter" : "There is a man who is taking care of all the sales behind it.",
    		"shelves" : "The shelvers are stocked with many things.",
	]));
     	set_exits( ([
     		"south" : JROOMS+"fg1"
     	]) );
   set_smell("default","You smell honing oil and leather.");
    	set_listen("default","You hear the clink of metal against metal.");
 }


void init(){
      ::init();
     	if(!present("blunt",TO))
      	new(JMONS+"blunt")->move(TO);

}
