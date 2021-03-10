//updated by Circe 6/2/04 with new desc, color, etc.
#include <std.h>
#include <daemons.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
	::create();
	set_travel(DIRT_ROAD);
	set_terrain(CITY);
	set_light(2);
	set_indoors(1);
	set_name("Tabor Dry Goods Store");
	set_short("Tabor Dry Goods Store");
	set_long(
@TABOR
%^BOLD%^Tabor Dry Goods Store%^RESET%^
%^ORANGE%^This is a simple, clean wooden shop with walls lined in shelves.  
Several %^WHITE%^crates %^ORANGE%^and %^WHITE%^barrels %^ORANGE%^are piled on the floor under the 
shelves and seem to contain such things as flour and barley.  Arranged 
neatly around the room are many items a person travelling might need, 
especially one who planned to sleep outdoors.  %^RED%^Rations%^ORANGE%^, %^YELLOW%^rope%^RESET%^%^ORANGE%^, and 
%^WHITE%^climbing tools %^ORANGE%^are just a few of the things you might find here.  A long 
%^YELLOW%^wooden counter %^RESET%^%^ORANGE%^stands just in front of a stool, upon which you can
often find a clerk perched.

%^RESET%^<help shop> will show you a list of commands to use here.
TABOR
	);
	set_items(([
		"counter" : "A worn and battered oak counter about waist high.",
		"shelves" : "The shelves are made of oak and covered "+
               "with all manner of supplies.",
            "supplies" : "You see nearly everything an adventurer could "+
               "want here.  You may need help finding some, however, "+
               "as a few of the things seem out of place."
	]));
	set_exits(([
		"east" : ROOMDIR+"math5"
	]));
	set_smell("default","The smell of oil lanterns and rope fills your nostrils.");
	set_listen("default","You hear the sounds from the street outside.");
 }


void init(){
      ::init();
      if(!present("clerk",TO))
              new("/d/darkwood/tabor/mon/tabor_clerk")->move(TO);
}
